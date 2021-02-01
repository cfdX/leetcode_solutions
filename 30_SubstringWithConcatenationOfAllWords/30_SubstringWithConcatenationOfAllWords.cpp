#include "30_SubstringWithConcatenationOfAllWords.h"

#include <unordered_map>
#include <algorithm>

namespace lc::t30 {

namespace {
// TODO тут можно подумать над оптимизаций - мы вычисляем хэш для подстроки раза три,
// а можно и один и запоминать его (правда, мапа, наверное, все равно будет его вычислять сама

//------------------------------
class Word {
public:
    //------------------------------
    Word( std::string_view word ) noexcept
        : m_word{ word }
        , m_hash{ std::hash<std::string_view>{}( m_word ) }
    {}

    //------------------------------
    [[nodiscard]]
    auto word() const noexcept -> std::string_view {
        return m_word;
    }
    [[nodiscard]]
    auto count() const noexcept -> std::size_t {
        return m_count;
    }
    [[nodiscard]]
    auto hash() const noexcept -> std::size_t {
        return m_hash;
    }

    //------------------------------
    void incCount() noexcept {
        ++m_count;
    }

    //------------------------------
    // корявый метод, и вообще плохо, что мы храним в описателе
    // количество вхождений в подстроке, но это делает реализацию эффективнее
    [[nodiscard]]
    auto incUseCountAndReturnIsGood() noexcept -> bool {
        ++m_use_count;
        return m_use_count <= m_count;
    }

    void resetUseCount() noexcept {
        m_use_count = 0;
    }

private:
    std::string_view m_word;
    // количество повторений в исходном массиве
    std::size_t m_count = 1;
    std::size_t m_hash = 0;

    std::size_t m_use_count = 0;
};

//------------------------------
using WordsMap = std::unordered_map<
      std::string_view
    , Word
>;

//------------------------------
[[nodiscard]]
auto preProcess( std::vector<std::string> const& words ) -> WordsMap {
    auto map = WordsMap( words.size() );
    for ( const auto& w : words ) {
        const auto wsv = std::string_view{ w };
        auto iter = map.find( wsv );
        if ( iter == map.end() ) {
            map.insert( { wsv, Word{ wsv } } );
        } else {
            iter->second.incCount();
        }
    }
    return map;
}

//------------------------------
[[nodiscard]]
auto allWordsHash( WordsMap const& words ) -> std::size_t {
    auto hash = std::size_t{0};
    for ( const auto& w : words ) {
        // для слов, встречающихся четное число раз
        // мы в итоге не будем использовать сравнение по хешу
        // Это сильная пессимизация, но я не знаю как это исправить
        // Ведь порядок слов в целевой строке не определен
        if ( (w.second.count()&1) == 1 ) {
            hash ^= w.second.hash();
        }
    }
    return hash;
}

//------------------------------
[[nodiscard]]
auto checkString(
              std::string_view s
            , std::size_t word_len
            , WordsMap& map ) noexcept
        -> bool {
    std::for_each( map.begin(), map.end(), []( auto& el ) {
        el.second.resetUseCount();
    });
    for ( auto i = std::size_t{0}; i < s.length(); i += word_len ) {
        auto iter = map.find( s.substr( i, word_len ) );
        if ( iter == map.end() ) {
            return false;
        }
        if ( false == iter->second.incUseCountAndReturnIsGood() ) {
            return false;
        }
    }
    return true;
}

} // namespace {

//------------------------------
[[nodiscard]]
auto Solution::findSubstring(
              std::string_view s
            , std::vector<std::string> const& words )
        -> std::vector<int> {
    if ( true == words.empty() ) {
        // непонятно, что возвращать в этом случае
        auto res = std::vector<int>{};
        for ( auto i = std::size_t{0}; i < s.size(); ++i ) {
            res.push_back( static_cast<int>(i) );
        }
        return res;
    }
    if ( true == s.empty() ) {
        return {};
    }
    const auto word_length = words.front().length();
    const auto words_length = word_length * words.size();
    if ( s.length() < words_length ) {
        return {};
    }
    auto words_info = preProcess( words );
    const auto all_hash = allWordsHash( words_info );
    constexpr const auto hasher = std::hash<std::string_view>{};
    auto res = std::vector<int>{};
    // цикла два - но это все равно линейная сложность
    for ( auto shift = std::size_t{0}; shift < word_length; ++shift ) {
        if ( (s.length() - shift) < words_length ) {
            break;
        }
        const auto cutted_str = s.substr( shift, s.length() - shift );
        // вычисляем хэш для начала (без одного слова)
        auto curr_hash = std::size_t{0};
        for ( auto i = std::size_t{0}; i < words_length; i += word_length ) {
            curr_hash ^= hasher( cutted_str.substr( i, word_length ) );
        }
        for ( auto i = std::size_t{0}; i <= cutted_str.size() - words_length; i += word_length ) {
            if ( i != 0 ) {
                // удаляем вышедшее из окна
                curr_hash ^= hasher( cutted_str.substr( i - word_length, word_length ) );
                // добавляем вошедшее в окно
                curr_hash ^= hasher( cutted_str.substr( i + words_length - word_length, word_length ) );
            }
            if ( curr_hash == all_hash ) {
                const auto is_good = checkString(
                      cutted_str.substr( i, words_length )
                    , word_length
                    , words_info
                );
                if ( true == is_good ) {
                    res.push_back( static_cast<int>( shift + i ) );
                }
            }
        }
    }
    return res;
}

} // namespace lc::t30

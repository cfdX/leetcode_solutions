#include "37_SudokuSolver.h"

#include <array>
#include <bitset>
#include <optional>

#include <iostream>

namespace lc::t37 {

namespace {

//------------------------------
constexpr const auto kBoxCount = std::size_t{3};
constexpr const auto kBoardSize = kBoxCount*kBoxCount;

//------------------------------
using CharBoard = std::vector<std::vector<char>>;

//------------------------------
template<class T, std::size_t kSize = kBoardSize>
using Matr = std::array<std::array<T, kSize>, kSize>;

// Битами показываем, какие возможны варианты в ячейке
using CellDecisions = std::bitset<kBoardSize>;

using Decisions = Matr<CellDecisions>;

std::string step;
struct D {
    D() {
        step += "  ";
    }
    ~D() {
        step.resize( step.size() - 2 );
    }
};

//------------------------------
[[nodiscard]]
auto toNum( char const c ) noexcept -> CellDecisions {
    if ( (c >= '1') && (c <= '9') ) {
        return CellDecisions{}.set( static_cast<std::size_t>( c - '1' ), true );
    }
    return CellDecisions{};
}

//------------------------------
// предполагается, что на входе сет только с одним битом
// TODO это очень дебильный способ узнать индекс установленного бита
// но мне лень сейчас с битами возиться, а эта не эффективность
// особо не должна влиять на общее время работы алгоритмаы
[[nodiscard]]
auto fromNum( CellDecisions const& d ) noexcept -> char {
    if ( d.count() != 1 ) { // TODO!!!!!!!!!!!!!!!!!!!! Это не нужно тогда
        return '.';
    }
    for ( std::size_t i = 0; i < 9; ++i ) {
        if ( d.test( i ) == true ) {
            return '1' + static_cast<char>(i);
        }
    }
    return '.';
}

//------------------------------
struct BoxInd {
    std::size_t box_i = 0;
    std::size_t box_j = 0;
};
struct CellInd {
    std::size_t cell_i = 0;
    std::size_t cell_j = 0;
    [[nodiscard]]
    auto operator==( CellInd const& ) const -> bool = default;
};

//------------------------------
[[nodiscard]]
auto boxForCell( std::size_t i, std::size_t j ) noexcept -> BoxInd {
    return { i / kBoxCount, j / kBoxCount };
}

//------------------------------
[[nodiscard]]
auto cellInBox( BoxInd bi, std::size_t i, std::size_t j ) noexcept -> CellInd {
    return { bi.box_i*kBoxCount + i, bi.box_j*kBoxCount + j };
}

//------------------------------
class DecisionDesc {
public:
    //------------------------------
    DecisionDesc() {
        fillInit();
    }
    DecisionDesc( CharBoard const& board ) noexcept {
        fillInit();
        m_unsolved_count = kBoardSize*kBoardSize;
        for ( std::size_t i = 0; i < kBoardSize; ++i ) {
            for ( std::size_t j = 0; j < kBoardSize; ++j ) {
                const auto val = toNum( board[i][j] );
                if ( val.count() == 1 ) {
                    --m_unsolved_count;
                    m_decisions[i][j] = val;
                    m_solved[i][j] = true;
                } else {
                    m_decisions[i][j] = CellDecisions{}.flip();
                }

            }
        }
        tryAutoSolveAll();
    }

    void print() const {
        for ( std::size_t i = 0; i < kBoardSize; ++i ) {
            std::cout << step;
            for ( std::size_t j = 0; j < kBoardSize; ++j ) {
                std::cout << fromNum( variants( i, j ) ) ;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        for ( std::size_t i = 0; i < kBoardSize; ++i ) {
            std::cout << step;
            for ( std::size_t j = 0; j < kBoardSize; ++j ) {
                std::cout << variants( i, j ).to_string() << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    //------------------------------
    void fillBoard( CharBoard& board ) const noexcept {
        for ( std::size_t i = 0; i < kBoardSize; ++i ) {
            for ( std::size_t j = 0; j < kBoardSize; ++j ) {
                board[i][j] = fromNum( variants( i, j ) );
            }
        }
    }
    //------------------------------
    [[nodiscard]]
    auto variants( std::size_t i, std::size_t j ) const noexcept -> CellDecisions {
        return m_decisions[i][j];
    }
    //------------------------------
    // считаем, что vars.count() == 1
    // то есть это окончательное решение
    // и более того, оно подходит (не делает решение не валидным)
    void setVariants( std::size_t i, std::size_t j, CellDecisions vars ) noexcept {
        if ( true == m_solved[i][j] ) {
            return;
        }
        m_decisions[ i ][ j ] = vars;
        m_solved[ i ][ j ] = true;
        // поставили пометки
        --m_unsolved_count;
        const auto box = boxForCell( i, j );



        const auto mask = ~vars;
        for ( std::size_t ci = 0; ci < kBoardSize; ++ci ) {
            if ( ci != j ) {
                m_decisions[ i ][ ci ] &= mask;
            }
        }
        for ( std::size_t ri = 0; ri < kBoardSize; ++ri ) {
            if ( ri != i ) {
                m_decisions[ ri ][ j ] &= mask;
            }
        }
        const auto bi = boxForCell( i, j );
        // можно сделать несколько эффективнее за счет проверки индекса перед вторым циклом
        for ( std::size_t ri = 0; ri < kBoxCount; ++ri ) {
            for ( std::size_t ci = 0; ci < kBoxCount; ++ci ) {
                const auto cell = cellInBox( bi, ri, ci );
                if ( cell == CellInd{ i, j } ) {
                    continue;
                }
                m_decisions[ cell.cell_i ][ cell.cell_j ] &= mask;
            }
        }

        tryAutoSolveRow( i );
        tryAutoSolveCol( j );
        tryAutoSolveBox( box );

    }
    // проверяет, можно ли поставить в ячейку значение
    // предполагаем, что это, конечное, решение (то есть стоит лишь один бит)
    [[nodiscard]]
    auto isApplyable( std::size_t i, std::size_t j, CellDecisions vars ) const noexcept -> bool {
        if ( m_solved[i][j] == true ) {
            return false;
        }
        if ( (variants( i, j ) & vars).count() == 0 ) {
            return false;
        }
        const auto mask = ~vars;
        for ( std::size_t ci = 0; ci < kBoardSize; ++ci ) {
            if ( (ci != j) && ( (variants( i, ci ) & mask).count() == 0 ) ) {
                return false;
            }
        }
        for ( std::size_t ri = 0; ri < kBoardSize; ++ri ) {
            if ( (ri != i) && ( (variants( ri, j ) & mask).count() == 0 ) ) {
                return false;
            }
        }
        const auto bi = boxForCell( i, j );
        // можно сделать несколько эффективнее за счет проверки индекса перед вторым циклом
        for ( std::size_t ri = 0; ri < kBoxCount; ++ri ) {
            for ( std::size_t ci = 0; ci < kBoxCount; ++ci ) {
                const auto cell = cellInBox( bi, ri, ci );
                if ( cell == CellInd{ i, j } ) {
                    continue;
                }
                if ( ( variants( cell.cell_i, cell.cell_j ) & mask).count() == 0 ) {
                    return false;
                }
            }
        }
        return true;
    }
    //------------------------------
    // предполагается, что ячейка ветвления не была
    // ячейкой с принятым решением и переданный вариант валиден
    [[nodiscard]]
    auto forkTheWorld( std::size_t i, std::size_t j, std::size_t num ) const noexcept  -> DecisionDesc {
        auto copy = *this;
        copy.setVariants( i, j, CellDecisions{}.set( num, true ) );
        return copy;
    }
    //------------------------------
    [[nodiscard]]
    auto isSolved() const noexcept -> bool {
        return m_unsolved_count == 0;
    }
    //------------------------------
    [[nodiscard]]
    auto findBetterForForkCell() const noexcept -> std::optional<CellInd> {
        auto res = std::optional<CellInd>{};
        // это важно, variants( 0,  ).count() может не подойти
        // если в 0, 0 уже принято решение
        auto min_cnt = kBoardSize + 1;
        for ( std::size_t ri = 0; ri < kBoardSize; ++ri ) {
            for ( std::size_t ci = 0; ci < kBoardSize; ++ci ) {
                const auto cnt = variants( ri, ci ).count();
                if ( cnt < 2 ) {
                    continue;
                }
                if ( cnt <= min_cnt ) {
                    min_cnt = cnt;
                    res = CellInd{ ri, ci };
                }
            }
        }
        return res;
    }
private:
    //------------------------------
    void fillInit() {
        auto arr9 = std::array<CellDecisions,kBoardSize>{};
        arr9.fill( CellDecisions{}.flip() );
        m_decisions.fill( arr9 );
    }
public:
    //------------------------------
    void tryAutoSolveRow( std::size_t ri ) noexcept {
        if ( true == isSolved() ) {
            return;
        }
        for ( std::size_t ci = 0; ci < kBoardSize; ++ci ) {
            if ( variants( ri, ci ).count() == 1 ) {
                setVariants( ri, ci, variants( ri, ci ) );
            }
        }
    }
    void tryAutoSolveCol( std::size_t ci ) noexcept {
        if ( true == isSolved() ) {
            return;
        }
        for ( std::size_t ri = 0; ri < kBoardSize; ++ri ) {
            if ( variants( ri, ci ).count() == 1 ) {
                setVariants( ri, ci, variants( ri, ci ) );
            }
        }
    }
    void tryAutoSolveBox( BoxInd bi ) noexcept {
        if ( true == isSolved() ) {
            return;
        }
        for ( std::size_t ri = 0; ri < kBoxCount; ++ri ) {
            for ( std::size_t ci = 0; ci < kBoxCount; ++ci ) {
                const auto cell = cellInBox( bi, ri, ci );
                if ( variants( cell.cell_i, cell.cell_j ).count() == 1 ) {
                    setVariants( cell.cell_i, cell.cell_j, variants( cell.cell_i, cell.cell_j ) );
                }
            }
        }
    }
    // А это штука найдет все варианты
    void tryAutoSolveAll() noexcept {
        if ( true == isSolved() ) {
            return;
        }
        for ( std::size_t ri = 0; ri < kBoardSize; ++ri ) {
            tryAutoSolveRow( ri );
        }
    }
private:
    // принятые решения
    Decisions m_decisions{};
    Matr<bool> m_solved{};
    // сколько всего клеток, где пока непонятно
    std::size_t m_unsolved_count = 0;
};

//------------------------------
[[nodiscard]]
auto solve( DecisionDesc const& desc ) -> std::optional<DecisionDesc> {
    if ( true == desc.isSolved() ) {
        return desc;
    }
    const auto mb_best_cell = desc.findBetterForForkCell();
    // TOTHINK не очень понятно, как мы тогда здесь оказались, мы ведь проверяем isApplyable
    if ( false == mb_best_cell.has_value() ) {
        return {};
    }
    const auto best_cell = mb_best_cell.value();
    for ( std::size_t i = 0; i < kBoardSize; ++i ) {
//        std::cout << step << 'x' << std::endl;
        const auto des = CellDecisions{}.set( i, true );
        if ( false == desc.isApplyable( best_cell.cell_i, best_cell.cell_j, des ) ) {
            continue;
        }
        auto new_desc = desc.forkTheWorld(
            best_cell.cell_i, best_cell.cell_j, i
        );
        new_desc.tryAutoSolveAll();
        const auto res = solve( new_desc );
        if ( false == res.has_value() ) {
            continue;
        }
//        if ( true == res->isSolved() ) {
//            return res;
//        }
        return res; //!!!!!!!!!!!!!!!!
    }
    return {};
}

} // namespace {


//------------------------------
void Solution::solveSudoku( std::vector<std::vector<char>>& board ) noexcept {
    const auto solved = solve( DecisionDesc{ board } );
    if ( true == solved.has_value() ) {
        solved->fillBoard( board );
        return;
    }
    // unreachable
}

} // namespace lc::t37




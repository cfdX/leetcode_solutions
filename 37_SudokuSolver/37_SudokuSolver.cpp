#include "37_SudokuSolver.h"

#include <array>
#include <bitset>
#include <optional>

namespace lc::t37 {

namespace {

//------------------------------
constexpr const auto kBoxCount = std::size_t{3};
constexpr const auto kBoardSize = kBoxCount*kBoxCount;

//------------------------------
using CharBoard = std::vector<std::vector<char>>;

using Num = unsigned int;
constexpr const auto kNoValue = static_cast<Num>( kBoardSize );

//------------------------------
template<class T, std::size_t kSize = kBoardSize>
using Matr = std::array<std::array<T, kSize>, kSize>;

// Битами показываем, какие возможны варианты в ячейке
using Variants = std::bitset<kBoardSize>;

//------------------------------
[[nodiscard]]
constexpr
auto toNum( char const c ) noexcept -> Num {
    if ( (c >= '1') && (c <= '9') ) {
        return static_cast<Num>( c - '1' );
    }
    return kNoValue;
}

//------------------------------
// предполагается, что на входе сет только с одним битом
// TODO это очень дебильный способ узнать индекс установленного бита
// но мне лень сейчас с битами возиться, и это лучше чем цикл c test[i]
[[nodiscard]]
auto numFromSet( Variants const& d ) noexcept -> Num {
    static_assert( kBoardSize == 9, "this switch is designed for 9*9 board" );
    switch ( d.to_ullong() ) {
        case 1: return 0;
        case 2: return 1;
        case 4: return 2;
        case 8: return 3;
        case 16: return 4;
        case 32: return 5;
        case 64: return 6;
        case 128: return 7;
        case 256: return 8;
        default: {}
    }
    return kNoValue;
}

//------------------------------
[[nodiscard]]
constexpr
auto toChar( Num const d ) noexcept -> char {
    return static_cast<char>( d ) + '1';
}

//------------------------------
[[nodiscard]]
auto numToSet( Num n ) noexcept -> Variants {
    return Variants{}.set( n, true );
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
constexpr
auto boxForRow( std::size_t i ) noexcept -> std::size_t {
    return i / kBoxCount;
}

//------------------------------
[[nodiscard]]
constexpr
auto boxForCol( std::size_t i ) noexcept -> std::size_t {
    return boxForRow( i );
}

//------------------------------
[[nodiscard]]
constexpr
auto boxForCell( std::size_t i, std::size_t j ) noexcept -> BoxInd {
    return { boxForRow(i), boxForCol(j) };
}

//------------------------------
[[nodiscard]]
constexpr
auto cellInBox( BoxInd bi, std::size_t i, std::size_t j ) noexcept -> CellInd {
    return { bi.box_i*kBoxCount + i, bi.box_j*kBoxCount + j };
}

//------------------------------
class DecisionDesc {
public:
    //------------------------------
    DecisionDesc() noexcept {
        fillInit();
    }
    //------------------------------
    DecisionDesc( CharBoard const& board ) noexcept {
        fillInit();
        m_unsolved_count = kBoardSize*kBoardSize;
        for ( std::size_t i = 0; i < kBoardSize; ++i ) {
            const auto box_ri = boxForRow( i );
            for ( std::size_t j = 0; j < kBoardSize; ++j ) {
                const auto val = toNum( board[i][j] );
                if ( val == kNoValue ) {
                    m_decisions[i][j] = kNoValue;
                } else {
                    --m_unsolved_count;
                    m_decisions[i][j] = val;
                    const auto mask = numToSet( val ).flip();
                    m_rows_unused[ i ] &= mask;
                    m_cols_unused[ j ] &= mask;
                    m_boxes_unused[ box_ri ][ boxForCol(j) ] &= mask;
                }
            }
        }
        tryAutoSolveAll();
    }

    //------------------------------
    void fillBoard( CharBoard& board ) const noexcept {
        for ( std::size_t i = 0; i < kBoardSize; ++i ) {
            for ( std::size_t j = 0; j < kBoardSize; ++j ) {
                board[i][j] = toChar( m_decisions[i][j] );
            }
        }
    }
    //------------------------------
    [[nodiscard]]
    auto variants( std::size_t i, std::size_t j, BoxInd bi ) const noexcept -> Variants {
        return m_rows_unused[i] & m_cols_unused[j] & m_boxes_unused[bi.box_i][bi.box_j];
    }
    //------------------------------
    void setVariants( std::size_t i, std::size_t j, Num val, BoxInd bi ) noexcept {
        if ( m_decisions[ i ][ j ] == val ) {
            return;
        }
        m_decisions[ i ][ j ] = val;
        // поставили пометки
        --m_unsolved_count;
        const auto mask = numToSet( val ).flip();
        m_rows_unused[ i ] &= mask;
        m_cols_unused[ j ] &= mask;
        m_boxes_unused[ bi.box_i ][ bi.box_j ] &= mask;
        if ( true == isSolved() ) {
            return;
        }
        tryAutoSolveRow( i, bi.box_i );
        tryAutoSolveCol( j, bi.box_j );
        tryAutoSolveBox( bi );
    }
    //------------------------------
    [[nodiscard]]
    auto isApplyable( std::size_t i, std::size_t j, Num val, BoxInd bi ) const noexcept -> bool {
        if ( m_decisions[i][j] != kNoValue ) {
            return false;
        }
        if ( false == variants( i, j, bi )[val] ) {
            return false;
        }
        const auto mask = numToSet( val ).flip();
        for ( std::size_t ci = 0; ci < kBoardSize; ++ci ) {
            if ( m_decisions[i][ci] != kNoValue ) {
                continue;
            }
            const auto box = BoxInd{ bi.box_i, boxForCol( ci ) };
            if ( (ci != j) && ( (variants( i, ci, box ) & mask).count() == 0 ) ) {
                return false;
            }
        }
        for ( std::size_t ri = 0; ri < kBoardSize; ++ri ) {
            if ( m_decisions[ri][j] != kNoValue ) {
                continue;
            }
            const auto box = BoxInd{ boxForRow( ri ), bi.box_j };
            if ( (ri != i) && ( (variants( ri, j, box ) & mask).count() == 0 ) ) {
                return false;
            }
        }
        // можно сделать несколько эффективнее за счет проверки индекса перед вторым циклом
        for ( std::size_t ri = 0; ri < kBoxCount; ++ri ) {
            for ( std::size_t ci = 0; ci < kBoxCount; ++ci ) {
                const auto cell = cellInBox( bi, ri, ci );
                if ( m_decisions[cell.cell_i][cell.cell_j] != kNoValue ) {
                    continue;
                }
                if ( cell == CellInd{ i, j } ) {
                    continue;
                }
                if ( ( variants( cell.cell_i, cell.cell_j, bi ) & mask).count() == 0 ) {
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
    auto forkTheWorld( std::size_t i, std::size_t j, Num num, BoxInd bi ) const noexcept  -> DecisionDesc {
        auto copy = *this;
        copy.setVariants( i, j, num, bi );
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
        auto min_cnt = kBoardSize + 1;
        for ( std::size_t ri = 0; ri < kBoardSize; ++ri ) {
            if ( m_rows_unused[ri].count() == 0 ) {
                continue;
            }
            const auto box_ri = boxForRow( ri );
            for ( std::size_t ci = 0; ci < kBoardSize; ++ci ) {
                if ( m_decisions[ri][ci] != kNoValue ) {
                    continue;
                }
                const auto bi = BoxInd{ box_ri, boxForCol( ci ) };
                const auto cnt = variants( ri, ci, bi ).count();
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
    void fillInit() noexcept {
        const auto val = Variants{}.flip();
        auto arr9 = std::array<Variants,kBoardSize>{};
        arr9.fill( val );
        m_rows_unused = arr9;
        m_cols_unused = arr9;
        auto arr3 = std::array<Variants,kBoxCount>{};
        arr3.fill( val );
        m_boxes_unused.fill( arr3 );
    }
public:
    //------------------------------
    void tryAutoSolveRow( std::size_t ri, std::size_t box_row ) noexcept {
        for ( std::size_t ci = 0; ci < kBoardSize; ++ci ) {
            if ( m_decisions[ri][ci] != kNoValue ) {
                continue;
            }
            const auto bi = BoxInd{ box_row, boxForCol( ci ) };
            const auto vars = variants( ri, ci, bi );
            if ( vars.count() == 1 ) {
                setVariants( ri, ci, numFromSet( vars ), bi );
            }
        }
    }
    //------------------------------
    void tryAutoSolveCol( std::size_t ci, std::size_t box_col ) noexcept {
        for ( std::size_t ri = 0; ri < kBoardSize; ++ri ) {
            if ( m_decisions[ri][ci] != kNoValue ) {
                continue;
            }
            const auto bi = BoxInd{ boxForRow( ri ), box_col };
            const auto vars = variants( ri, ci, bi );
            if ( vars.count() == 1 ) {
                setVariants( ri, ci, numFromSet( vars ), bi );
            }
        }
    }
    //------------------------------
    void tryAutoSolveBox( BoxInd bi ) noexcept {
        for ( std::size_t ri = 0; ri < kBoxCount; ++ri ) {
            for ( std::size_t ci = 0; ci < kBoxCount; ++ci ) {
                const auto cell = cellInBox( bi, ri, ci );
                if ( m_decisions[cell.cell_i][ cell.cell_j] != kNoValue ) {
                    continue;
                }
                const auto vars = variants(
                    cell.cell_i, cell.cell_j, bi
                );
                if ( vars.count() == 1 ) {
                    setVariants(
                          cell.cell_i
                        , cell.cell_j
                        , numFromSet( vars )
                        , bi
                    );
                }
            }
        }
    }
    //------------------------------
    // А это штука найдет все варианты
    void tryAutoSolveAll() noexcept {
        if ( true == isSolved() ) {
            return;
        }
        for ( std::size_t ri = 0; ri < kBoardSize; ++ri ) {
            if ( 0 == m_rows_unused[ ri ].count() ) {
                continue;
            }
            tryAutoSolveRow( ri, boxForRow( ri ) );
        }
    }
private:
    // принятые решения
    Matr<Num> m_decisions{};
    // не занятые числа для каждой строки, столбца и клетки
    std::array<Variants, kBoardSize> m_rows_unused{};
    std::array<Variants, kBoardSize> m_cols_unused{};
    Matr<Variants, kBoxCount> m_boxes_unused{};
    // сколько всего клеток, где пока непонятно
    std::size_t m_unsolved_count = 0;
};

//------------------------------
[[nodiscard]]
auto solve( DecisionDesc const& desc ) noexcept -> std::optional<DecisionDesc> {
    if ( true == desc.isSolved() ) {
        return desc;
    }
    const auto mb_best_cell = desc.findBetterForForkCell();
    if ( false == mb_best_cell.has_value() ) {
        // unreachable
        // не очень понятно, как мы тогда здесь оказались, мы ведь проверяем isApplyable
        return {};
    }
    const auto best_cell = mb_best_cell.value();
    const auto box_for_cell = boxForCell( best_cell.cell_i, best_cell.cell_j );
    for ( Num val = 0; val < static_cast<Num>(kBoardSize); ++val ) {
        const auto is_applyable = desc.isApplyable(
            best_cell.cell_i, best_cell.cell_j, val, box_for_cell
        );
        if ( false == is_applyable ) {
            continue;
        }
        const auto new_desc = desc.forkTheWorld(
            best_cell.cell_i, best_cell.cell_j, val, box_for_cell
        );
        const auto res = solve( new_desc );
        if ( false == res.has_value() ) {
            continue;
        }
//        if ( true == res->isSolved() ) {
//            return res;
//        }
        return res; // мы не проверяем решение на полноту, так как иначе бы его не вернули бы
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




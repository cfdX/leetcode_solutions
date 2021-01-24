#ifndef LC_LISTNODE_H
#define LC_LISTNODE_H

#include <vector>
#include <initializer_list>

namespace lc {

// Видимо, это определение списка используется во многих задачах
// Поэтому удобно его ввести один раз
// И здесь же всякие полезные утилиты для него

//---------------------------
// Definition for singly-linked list.
struct ListNode {
    int val = 0;
    ListNode *next = nullptr;
    ListNode() = default;
    ListNode( int x );
    ListNode( int x, ListNode * next );
};

//---------------------------
// мы не можем использовать обычный std::unique_ptr, так как
// нам нужно удалить всю цепочку
// А использовать деструктор самого класса мы не можем
// так как это поломает нам красивый хак со стековым объектом списка
class ListUniquePtr {
public:
    ~ListUniquePtr();
    ListUniquePtr() = default;
    ListUniquePtr( ListNode * );
    ListUniquePtr( ListUniquePtr const& ) = delete;
    ListUniquePtr& operator=( ListUniquePtr const& ) = delete;
    ListUniquePtr( ListUniquePtr&& ) noexcept;
    ListUniquePtr& operator=( ListUniquePtr&& ) noexcept;

    [[nodiscard]]
    auto operator==( ListUniquePtr const& ) const -> bool = default;

    [[nodiscard]]
    auto operator->() const noexcept -> ListNode * {
        return m_node;
    }
    [[nodiscard]]
    auto get() const noexcept -> ListNode * {
        return m_node;
    }

private:
    void deleteChain();

private:
    ListNode * m_node = nullptr;

};

//---------------------------
auto generateList( std::initializer_list<int> ) -> ListUniquePtr;
auto listToVec( ListNode * ) -> std::vector<int>;

} // namespace lc

#endif // LC_LISTNODE_H


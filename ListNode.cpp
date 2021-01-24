#include "ListNode.h"

namespace lc {

//---------------------------
//---------------------------
//---------------------------
ListNode::ListNode( int x)
    : val{ x }
{}

ListNode::ListNode( int x, ListNode* next )
    : val{ x }
    , next{ next }
{}

//---------------------------
//---------------------------
//---------------------------
ListUniquePtr::~ListUniquePtr() {
    deleteChain();
}

ListUniquePtr::ListUniquePtr(ListNode* node)
    : m_node{ node }
{}

ListUniquePtr::ListUniquePtr( ListUniquePtr&& o ) noexcept
    : m_node( std::exchange( o.m_node, nullptr ) )
{}

void ListUniquePtr::deleteChain() {
    while ( m_node != nullptr ) {
        const auto prev = m_node;
        m_node = m_node->next;
        delete prev;
    }
}

auto ListUniquePtr::operator=( ListUniquePtr&& o ) noexcept -> ListUniquePtr& {
    deleteChain();
    m_node = std::exchange( o.m_node, nullptr );
    return *this;
}


//---------------------------
//---------------------------
//---------------------------
auto generateList( std::initializer_list<int> nums ) -> ListUniquePtr {
    auto dummy = ListNode{};
    auto prev = &dummy;
    // TODO код не безопасен относительно исключений, но "и так сойдет"
    for ( auto x : nums ) {
        prev->next = new ListNode{x};
        prev = prev->next;
    }
    return ListUniquePtr{ dummy.next };
}

//---------------------------
auto listToVec( ListNode * head ) -> std::vector<int> {
    auto res = std::vector<int>{};
    while ( head != nullptr ) {
        res.push_back( head->val );
        head = head->next;
    }
    return res;
}

} // namespace lc

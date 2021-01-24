#include "2_AddTwoNumbers.h"

namespace lc::t2 {

auto Solution::addTwoNumbers( ListNode* l1, ListNode* l2 ) -> ListNode* {
    auto dummy = ListNode{};
    auto curr_node = &dummy;
    auto bit = int{0};
    const auto append_res = [&]( int const x_ ) {
        const auto x = x_ + bit;
        const auto x10 = x/10;
        bit = x10;
        // (x - 10*x10) == x%10, but faster(or slower???)
        const auto prev_res = std::exchange(
            curr_node, new ListNode{ x - 10*x10 }
        );
        prev_res->next = curr_node;
    };
    while ( (nullptr != l1) && (nullptr != l2) ) {
        append_res( l1->val + l2->val );
        l1 = l1->next;
        l2 = l2->next;
    }
    while ( nullptr != l1 ) {
        append_res( l1->val );
        l1 = l1->next;
    }
    while ( nullptr != l2 ) {
        append_res( l2->val );
        l2 = l2->next;
    }
    if ( 0 != bit ) {
        append_res( 0 );
    }
    return dummy.next;
}

} // namespace lc::t2


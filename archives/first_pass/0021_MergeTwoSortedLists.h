/*
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 */

#ifndef LEET_CODE_0021_MERGE_TWO_SORTED_LISTS_H_
#define LEET_CODE_0021_MERGE_TWO_SORTED_LISTS_H_

#include <stack>
#include <string>
#include <climits>
#include <gtest/gtest.h>

using namespace std;

namespace L0021 {
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        Solution() = default;

        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            ListNode result_obj(0);
            ListNode * result = &result_obj;
            ListNode *head = result;

            while (l1 && l2) {
                if (l1->val <= l2->val) {
                    result->next = l1;
                    l1 = l1->next;
                } else {
                    result->next = l2;
                    l2 = l2->next;
                }
                result = result->next;
            }
            result->next = l1 ? l1 : l2;

            return head->next;
        }
    };
}


TEST(L0021_MERGE_TWO_SORTED_LISTS, CASE_TEST) {
    L0021::ListNode *l10 = new L0021::ListNode(1);
    L0021::ListNode *l11 = new L0021::ListNode(2);
    L0021::ListNode *l12 = new L0021::ListNode(4);
    l10->next = l11;
    l11->next = l12;

    L0021::ListNode *l20 = new L0021::ListNode(1);
    L0021::ListNode *l21 = new L0021::ListNode(3);
    L0021::ListNode *l22 = new L0021::ListNode(4);
    l20->next = l21;
    l21->next = l22;

    L0021::Solution s;

    L0021::ListNode *l1l2 = s.mergeTwoLists(l10, l20);
    EXPECT_EQ(l1l2->val, 1);
    EXPECT_EQ(l1l2->next->val, 1);
    EXPECT_EQ(l1l2->next->next->val, 2);
    EXPECT_EQ(l1l2->next->next->next->val, 3);
    EXPECT_EQ(l1l2->next->next->next->next->val, 4);
    EXPECT_EQ(l1l2->next->next->next->next->next->val, 4);

    delete l12;
    delete l11;
    delete l10;
    delete l22;
    delete l21;
    delete l20;
}

#endif //LEET_CODE_0021_MERGE_TWO_SORTED_LISTS_H_

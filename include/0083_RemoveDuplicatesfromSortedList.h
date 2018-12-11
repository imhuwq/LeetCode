/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * 
 * Example 1:
 * 
 * Input: 1->1->2
 * Output: 1->2
 * Example 2:
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 */

#ifndef LEET_CODE_0083_REMOVE_DUPLICATES_FROM_SORTED_LIST_H_
#define LEET_CODE_0083_REMOVE_DUPLICATES_FROM_SORTED_LIST_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0083 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            if (!head) return head;

            ListNode *current = head;
            ListNode *scanning = current->next;

            while (scanning) {
                if (current->val != scanning->val) {
                    current->next = scanning;
                    current = current->next;
                }
                scanning = scanning->next;
            }

            current->next = NULL;
            return head;
        }
    };

}

TEST(L0083_REMOVE_DUPLICATES_FROM_SORTED_LIST, CASE_TEST) {
    L0083::Solution s;

    L0083::ListNode l1(1);
    L0083::ListNode l2(1);
    L0083::ListNode l3(2);
    l1.next = &l2;
    l2.next = &l3;
    L0083::ListNode *r1 = s.deleteDuplicates(&l1);
    EXPECT_EQ(r1->val, 1);
    EXPECT_EQ(r1->next->val, 2);
    EXPECT_TRUE(r1->next->next == NULL);


    L0083::ListNode l4(1);
    L0083::ListNode l5(1);
    L0083::ListNode l6(2);
    L0083::ListNode l7(3);
    L0083::ListNode l8(3);
    l4.next = &l5;
    l5.next = &l6;
    l6.next = &l7;
    l7.next = &l8;
    L0083::ListNode *r2 = s.deleteDuplicates(&l4);
    EXPECT_EQ(r2->val, 1);
    EXPECT_EQ(r2->next->val, 2);
    EXPECT_EQ(r2->next->next->val, 3);
    EXPECT_TRUE(r2->next->next->next == NULL);
}

#endif //LEET_CODE_0083_REMOVE_DUPLICATES_FROM_SORTED_LIST_H_

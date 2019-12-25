/*
 * 
 * Given a linked list, swap every two adjacent nodes and return its head.
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 * 
 * Example:
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 */

#ifndef LEET_CODE_0024_SWAP_NODES_IN_PAIRS_H_
#define LEET_CODE_0024_SWAP_NODES_IN_PAIRS_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0024 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}

        static ListNode *CreateFromVec(vector<int> &vals) {
            if (vals.empty()) nullptr;

            ListNode *head = new ListNode(vals[0]);
            ListNode *current = head;
            for (size_t idx = 1; idx < vals.size(); idx++) {
                ListNode *next = new ListNode(vals[idx]);
                current->next = next;
                current = next;
            }
            return head;
        }

        static ListNode *CreateFromVec(vector<int> &&vals) {
            return ListNode::CreateFromVec(vals);
        }

        bool operator==(ListNode rhs) {
            if (val != rhs.val) return false;
            if (next != nullptr) {
                if (rhs.next != nullptr) return *next == *rhs.next;
                else return false;
            } else return rhs.next == nullptr;
        }
    };

    class Solution {
    public:
        ListNode *swapPairs(ListNode *head) {
            if (head == nullptr) return nullptr;

            ListNode *pre_head = new ListNode(0);
            pre_head->next = head;

            bool should_swap = false;
            ListNode *pre_before = nullptr;
            ListNode *before = pre_head;
            ListNode *current = head;
            while (current) {
                if (should_swap) {
                    before->next = current->next;
                    current->next = before;
                    pre_before->next = current;
                    pre_before = current;
                    current = before->next;
                } else {
                    pre_before = before;
                    before = current;
                    current = current->next;
                }
                should_swap = !should_swap;
            }

            return pre_head->next;
        }
    };
}

TEST(L0024_SWAP_NODES_IN_PAIRS, CASE_TEST) {
    using namespace L0024;
    Solution s;
    ListNode *input = ListNode::CreateFromVec({1, 2, 3, 4});
    ListNode *output = s.swapPairs(input);
    ListNode *expect = ListNode::CreateFromVec({2, 1, 4, 3});
    EXPECT_TRUE(*output == *expect);
}

#endif //LEET_CODE_0024_SWAP_NODES_IN_PAIRS_H_

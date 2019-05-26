/*
 * 
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * 
 * Example:
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 * 
 * 
 */

#ifndef LEET_CODE_0086_PARTITIONLIST_H_
#define LEET_CODE_0086_PARTITIONLIST_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0086 {
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
        ListNode *partition(ListNode *head, int x) {
            if (head == nullptr) return nullptr;

            ListNode *left = new ListNode(0);
            ListNode *right = new ListNode(0);
            ListNode *left_beg = left, *right_beg = right;

            while (head) {
                if (head->val < x) {
                    left->next = head;
                    left = left->next;
                } else {
                    right->next = head;
                    right = right->next;
                }
                head = head->next;
            }
            right->next = nullptr;
            left->next = right_beg->next;
            return left_beg->next;
        }
    };

}

TEST(L0086_PartitionList, CASE_TEST) {
    using namespace L0086;
    Solution s;
    ListNode *inp = ListNode::CreateFromVec({1, 4, 3, 2, 5, 2});
    ListNode *out = s.partition(inp, 3);
    ListNode *ans = ListNode::CreateFromVec({1, 2, 2, 4, 3, 5});
    EXPECT_TRUE(*out == *ans);
    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0086_PARTITIONLIST_H_

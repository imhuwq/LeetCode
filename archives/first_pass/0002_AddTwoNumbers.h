/*
 * 
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Example:
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */

#ifndef LEET_CODE_0002_ADDTWONUMBERS_H_
#define LEET_CODE_0002_ADDTWONUMBERS_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0002 {
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}

        bool operator==(ListNode rhs) {
            if (val != rhs.val) return false;
            if (next != nullptr) {
                if (rhs.next != nullptr) return *next == *rhs.next;
                else return false;
            } else return rhs.next == nullptr;
        }

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
    };

    class Solution {
    public:

        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            ListNode *prev = new ListNode(0);
            ListNode *head = prev, *next;

            int value = 0;
            int carry = 0;
            while (l1 || l2 || carry) {
                value = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
                carry = value / 10;
                value = value % 10;
                next = new ListNode(value);
                head->next = next;
                head = head->next;
                l1 = l1 ? l1->next : nullptr;
                l2 = l2 ? l2->next : nullptr;
            }

            return prev->next;
        }
    };
}

TEST(L0002_AddTwoNumbers, CASE_TEST) {
    using namespace L0002;
    Solution s;

    ListNode *l1 = ListNode::CreateFromVec({2, 4, 3});
    ListNode *l2 = ListNode::CreateFromVec({5, 6, 4});
    ListNode *s1 = ListNode::CreateFromVec({7, 0, 8});
    ListNode *r1 = s.addTwoNumbers(l1, l2);
    EXPECT_TRUE(*s1 == *r1);
}

#endif //LEET_CODE_0002_ADDTWONUMBERS_H_

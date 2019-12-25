/*
 * 
 * Reverse a linked list from position m to n. Do it in one-pass.
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 * 
 */

#ifndef LEET_CODE_0092_REVERSELINKEDLISTII_H_
#define LEET_CODE_0092_REVERSELINKEDLISTII_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0092 {

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
        ListNode *reverseBetween(ListNode *head, int m, int n) {
            if (m == n) return head;
            else if (m > n) return head;

            auto *pre_head = new ListNode(0);
            pre_head->next = head;

            ListNode *prev = pre_head, *next, *r_before, *r_end;
            for (int i = 1; i <= n; i++) {
                if (i < m) {
                    prev = head;
                    head = head->next;
                } else if (i == m) {
                    r_end = head;
                    r_before = prev;
                    next = head->next;
                    head->next = nullptr;
                    prev = head;
                    head = next;
                } else if (i > m && i < n) {
                    next = head->next;
                    head->next = prev;
                    prev = head;
                    head = next;
                } else if (i == n) {
                    next = head->next;
                    head->next = prev;
                    r_before->next = head;
                    r_end->next = next;
                }
            }

            head = pre_head->next;
            delete pre_head;
            return head;
        }
    };

}

TEST(L0092_ReverseLinkedListII, CASE_TEST) {
    using namespace L0092;
    Solution s;

    ListNode *inp = ListNode::CreateFromVec({3, 5});
    ListNode *ans = ListNode::CreateFromVec({1, 4, 3, 2, 5});
    ListNode *out = s.reverseBetween(inp, 1, 2);
    EXPECT_TRUE(*ans == *out);
}

#endif //LEET_CODE_0092_REVERSELINKEDLISTII_H_

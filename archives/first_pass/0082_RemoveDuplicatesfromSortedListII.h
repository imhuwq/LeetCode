/*
 * 
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * Example 2:
 * Input: 1->1->1->2->3
 * Output: 2->3
 * 
 */

#ifndef LEET_CODE_0082_REMOVEDUPLICATESFROMSORTEDLISTII_H_
#define LEET_CODE_0082_REMOVEDUPLICATESFROMSORTEDLISTII_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0082 {
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
        ListNode *deleteDuplicates(ListNode *head) {
            // 1 2 2
            if (head == nullptr) return nullptr;
            ListNode *last = new ListNode(0);
            ListNode *dummy = last;
            bool eq_next, eq_pre = false;
            while (head->next) {
                eq_next = head->val == head->next->val;
                if (!eq_next && !eq_pre) {
                    last->next = head;
                    last = head;
                }
                head = head->next;
                eq_pre = eq_next;
            }

            if(!eq_pre) last->next = head;
            else last->next = nullptr;

            return dummy->next;
        }
    };

}

TEST(L0082_RemoveDuplicatesfromSortedListII, CASE_TEST) {
    using namespace L0082;
    Solution s;
    ListNode *inp = ListNode::CreateFromVec({1, 2, 2});
    ListNode *out = s.deleteDuplicates(inp);
    ListNode *ans = ListNode::CreateFromVec({1});
    EXPECT_TRUE(*out == *ans);
}

#endif //LEET_CODE_0082_REMOVEDUPLICATESFROMSORTEDLISTII_H_

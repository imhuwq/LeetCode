/*
 * 
 * Given a linked list, rotate the list to the right by k places, where k is non-negative.
 * 
 * Example 1:
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 * 
 * Example 2:
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
 * 
 */

#ifndef LEET_CODE_0061_ROTATELIST_H_
#define LEET_CODE_0061_ROTATELIST_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0061 {
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
        ListNode *rotateRight(ListNode *head, int k) {
            if (head == nullptr) return nullptr;
            if (k == 0) return head;

            int len = 0;
            ListNode *cur = head, *tail = nullptr;
            while (cur) {
                len++;
                tail = cur;
                cur = cur->next;
            }

            k = k % len;
            if (k == 0) return head;

            cur = head;
            tail->next = head;
            for (int i = 0; i < len - k - 1; i++) cur = cur->next;
            head = cur->next;
            cur->next = nullptr;
            return head;
        }
    };

}

TEST(L0061_RotateList, CASE_TEST) {
    using namespace L0061;
    Solution s;

    ListNode *l1 = ListNode::CreateFromVec({1, 2, 3, 4, 5});
    ListNode *r1 = ListNode::CreateFromVec({4, 5, 1, 2, 3});
    EXPECT_TRUE(*s.rotateRight(l1, 2) == *r1);

    l1 = ListNode::CreateFromVec({0, 1, 2});
    r1 = ListNode::CreateFromVec({2, 0, 1});
    EXPECT_TRUE(*s.rotateRight(l1, 4) == *r1);

    l1 = ListNode::CreateFromVec({1, 2});
    r1 = ListNode::CreateFromVec({2, 1});
    EXPECT_TRUE(*s.rotateRight(l1, 1) == *r1);

    l1 = ListNode::CreateFromVec({1, 2, 3});
    r1 = ListNode::CreateFromVec({2, 3, 1});
    EXPECT_TRUE(*s.rotateRight(l1, 2000000000) == *r1);
}

#endif //LEET_CODE_0061_ROTATELIST_H_

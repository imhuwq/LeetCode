/*
 * 
 * Given a linked list, remove the n-th node from the end of list and return its head.
 * 
 * Example:
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * 
 * Note:
 * Given n will always be valid.
 * 
 * Follow up:
 * Could you do this in one pass?
 * 
 *
 *  Definition for singly-linked list.
 *  struct ListNode {
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {}
 *   };
 *
 */

#ifndef LEET_CODE_0019_REMOVE_NTH_NODE_FROM_END_OF_LIST_H_
#define LEET_CODE_0019_REMOVE_NTH_NODE_FROM_END_OF_LIST_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0019 {

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
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            ListNode *slow = head, *fast = head, *before = nullptr;

            while (n > 0) {
                fast = fast->next;
                n--;
            }

            while (fast) {
                before = slow;
                slow = slow->next;
                fast = fast->next;
            }

            if (before == nullptr) {
                return slow->next;
            } else {
                before->next = slow->next;
                return head;
            }
        }
    };
}

TEST(L0019_REMOVE_NTH_NODE_FROM_END_OF_LIST, CASE_TEST) {
    using namespace L0019;
    Solution s;

    vector<int> vec = {1, 2, 3, 4, 5};
    ListNode *list = ListNode::CreateFromVec(vec);

    vector<int> vec2 = {1, 2, 3, 5};
    ListNode *list2 = ListNode::CreateFromVec(vec2);
    ListNode* ret2 = s.removeNthFromEnd(list, 2);
    bool eq = (*ret2 == *list2);
    EXPECT_TRUE(eq);
}

#endif //LEET_CODE_0019_REMOVE_NTH_NODE_FROM_END_OF_LIST_H_

/*
 * 
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * 
 * Example 1:
 * Input: 1->1->2
 * Output: 1->2
 * 
 * Example 2:
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 * 
 */

#ifndef LEET_CODE_0083_REMOVEDUPLICATESFROMSORTEDLIST_H_
#define LEET_CODE_0083_REMOVEDUPLICATESFROMSORTEDLIST_H_

#include <map>
#include <stack>
#include <queue>
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

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}

        ListNode(string str) {
            if (str.empty()) return;

            ListNode *head = nullptr;
            ListNode *next_node = nullptr;
            for (char c:str) {
                if (c == '-' or c == '>') continue;
                int value = (int) (c - '0');

                if (head == nullptr) {
                    head = this;
                    val = value;
                } else {
                    next_node = new ListNode(value);
                    head->next = next_node;
                    head = next_node;
                }
            }
        }

        ~ListNode() {
            delete this->next;
        }


    };

    bool operator==(const ListNode &lhs, const ListNode &rhs) {
        if (lhs.val != rhs.val) return false;
        bool l_empty = lhs.next == nullptr;
        bool r_empty = rhs.next == nullptr;
        if (l_empty & r_empty) return true;
        if (l_empty ^ r_empty) return false;
        return *lhs.next == *rhs.next;
    }

    class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            if (!head) return nullptr;

            ListNode *pre = head;
            ListNode *cur = head->next;

            while (cur) {
                if (pre->val != cur->val) {
                    pre->next = cur;
                    pre = cur;
                }
                cur = cur->next;
            }

            pre->next = nullptr;

            return head;
        }
    };

}

TEST(L0083_RemoveDuplicatesfromSortedList, CASE_TEST) {
    using namespace L0083;
    Solution s;

    ListNode *ln1 = new ListNode("1->1->2");
    ListNode *ln2 = new ListNode("1->2");
    ListNode *ln3 = s.deleteDuplicates(ln1);
    EXPECT_EQ(*ln3, *ln2);

    ln1 = new ListNode("1->1->2->3->3");
    ln2 = new ListNode("1->2->3");
    ln3 = s.deleteDuplicates(ln1);
    EXPECT_EQ(*ln3, *ln2);

    ln1 = new ListNode(1);
    ln2 = new ListNode(1);
    ln3 = s.deleteDuplicates(ln1);
    EXPECT_EQ(*ln3, *ln2);
}

#endif //LEET_CODE_0083_REMOVEDUPLICATESFROMSORTEDLIST_H_

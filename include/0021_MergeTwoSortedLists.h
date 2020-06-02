/*
 * 
 * Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 */

#ifndef LEET_CODE_0021_MERGETWOSORTEDLISTS_H_
#define LEET_CODE_0021_MERGETWOSORTEDLISTS_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0021 {
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
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            if (l1 == nullptr) return l2;
            if (l2 == nullptr) return l1;

            ListNode *left = l1;
            ListNode *right = l2;
            ListNode *cur = new ListNode(0);
            ListNode *pre = cur;
            while (left != nullptr or right != nullptr) {
                cur->next = new ListNode(0);
                cur = cur->next;

                if (left == nullptr) {
                    cur->val = right->val;
                    right = right->next;
                } else if (right == nullptr) {
                    cur->val = left->val;
                    left = left->next;
                } else if (left->val < right->val) {
                    cur->val = left->val;
                    left = left->next;
                } else {
                    cur->val = right->val;
                    right = right->next;
                }
            }

            return pre->next;
        }
    };

}

TEST(L0021_MergeTwoSortedLists, CASE_TEST) {
    using namespace L0021;
    Solution s;

    ListNode l1 = ListNode("1->2->4");
    ListNode l2 = ListNode("1->3->4");
    ListNode l3 = ListNode("1->1->2->3->4->4");
    EXPECT_EQ(*s.mergeTwoLists(&l1, &l2), l3);
}

#endif //LEET_CODE_0021_MERGETWOSORTEDLISTS_H_

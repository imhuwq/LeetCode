/*
 * 
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 * 
 */

#ifndef LEET_CODE_0203_REMOVELINKEDLISTELEMENTS_H_
#define LEET_CODE_0203_REMOVELINKEDLISTELEMENTS_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0203 {
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}
    };

    class Solution {
    public:
        ListNode *removeElements(ListNode *head, int val) {
            ListNode *begin = new ListNode(0);
            begin->next = head;
            ListNode *curr = begin;

            while (curr) {
                if (curr->next && curr->next->val == val) curr->next = curr->next->next;
                else curr = curr->next;
            }

            ListNode* result =  begin->next;
            delete begin;
            return result;
        }
    };
}

TEST(L0203_RemoveLinkedListElements, CASE_TEST) {
    using namespace L0203;
    Solution s;

//   begin->1->2->6->3->4->5->6
    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0203_REMOVELINKEDLISTELEMENTS_H_

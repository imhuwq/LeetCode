/*
 * Given a linked list, determine if it has a cycle in it.
 * 
 * To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
 * 
 *  
 * 
 * Example 1:
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the second node.
 * 
 * Example 2:
 * Input: head = [1,2], pos = 0
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the first node.
 * 
 * Example 3:
 * Input: head = [1], pos = -1
 * Output: false
 * Explanation: There is no cycle in the linked list.
 *  
 * Follow up:
 * Can you solve it using O(1) (i.e. constant) memory?
 * 
 */

#ifndef LEET_CODE_0141_LINKED_LIST_CYCLE_H_
#define LEET_CODE_0141_LINKED_LIST_CYCLE_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0141 {

    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(NULL) {}

        ListNode *AddNext(int val) {
            ListNode *nextNode = new ListNode(val);
            next = nextNode;
            return nextNode;
        }

        ~ListNode() {
            delete next;
            next = NULL;
        }
    };

    class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode * slow = head;
            ListNode * fast = head;
            while (true) {
                if (fast == NULL || fast->next == NULL) return false;
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow) return true;
            }
        }
    };

}

TEST(L0141_LINKED_LIST_CYCLE, CASE_TEST) {
    using namespace L0141;
    Solution s;

    ListNode *ln1 = new ListNode(3);
    ListNode *lnTail1 = ln1->AddNext(2)->AddNext(0)->AddNext(-4);
    EXPECT_FALSE(s.hasCycle(ln1));
    lnTail1->next = ln1->next;
    EXPECT_TRUE(s.hasCycle(ln1));
}

#endif //LEET_CODE_0141_LINKED_LIST_CYCLE_H_

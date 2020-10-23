/*
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * Example 1:
 * Input
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * 
 * Output
 * [null,null,null,null,-3,null,0,-2]
 * 
 * Explanation
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin(); // return -3
 * minStack.pop();
 * minStack.top();    // return 0
 * minStack.getMin(); // return -2
 * 
 * 
 * Constraints:
 * Methods pop, top and getMin operations will always be called on non-empty stacks.
 */

#ifndef LEET_CODE_0155_MINSTACK_H_
#define LEET_CODE_0155_MINSTACK_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0155 {

    class MinStack {
    public:

        /** initialize your data structure here. */
        MinStack() {
            head_ = nullptr;
        }

        ~MinStack() {
            Node *head = head_;
            while (head) {
                Node *next = head->next_;
                delete head;
                head = next;
            }
        }

        void push(int x) {
            if (head_ == nullptr) head_ = new Node(x, x, nullptr);
            else head_ = new Node(x, min(x, head_->min_), head_);
        }

        void pop() {
            if (head_ == nullptr) return;
            Node *tmp = head_;
            head_ = head_->next_;
            delete tmp;
        }

        int top() {
            if (head_ == nullptr) return 0;
            return head_->val_;
        }

        int getMin() {
            if (head_ == nullptr) return 0;
            return head_->min_;
        }

    private:
        struct Node {
            Node(int val, int min, Node *next) : val_(val), min_(min), next_(next) {}

            int val_;
            int min_;
            Node *next_;
        };

        Node *head_;
    };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
}

TEST(L0155_MinStack, CASE_TEST) {
    using namespace L0155;
    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0155_MINSTACK_H_

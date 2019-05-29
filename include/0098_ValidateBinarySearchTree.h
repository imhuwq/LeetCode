/*
 * 
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * Example 1:
 *     2
 *    / \
 *   1   3
 * 
 * Input: [2,1,3]
 * Output: true
 * 
 * Example 2:
 *     5
 *    / \
 *   1   4
 *      / \
 *     3   6
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 * 
 */

#ifndef LEET_CODE_0098_VALIDATEBINARYSEARCHTREE_H_
#define LEET_CODE_0098_VALIDATEBINARYSEARCHTREE_H_

#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <memory>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0098 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    template<int resolve_order_, int num_child_stack_>
    struct StackFrame {
        typedef shared_ptr<StackFrame> StackFramePtr;
        typedef shared_ptr<const StackFrame> kStackFramePtr;

        // arguments
        long long min;
        long long max;
        TreeNode *node;

        int idx_child_stack = 0;
        int num_child_stack = num_child_stack_;
        int resolve_order = resolve_order_;
        bool resolved = false;
        bool result = false;

        StackFrame(TreeNode *node_, long long min_, long long max_) :
                node(node_), min(min_), max(max_) {}

        bool HasChildStack() {
            if (node == nullptr) return false;
            if (idx_child_stack == 0) return (node->left != nullptr || node->right != nullptr);
            else if (idx_child_stack == 1) return (node->right != nullptr);
            else return false; //  (idx_child_stack >= num_child_stack)
        }

        // can only be called when HasChildStack() return true
        StackFramePtr CreateChildStack() {
            idx_child_stack++;
            if (idx_child_stack == 1 && node->left) return make_shared<StackFrame>(node->left, min, node->val);
            return make_shared<StackFrame>(node->right, node->val, max);
        }

        void Resolve(const kStackFramePtr &last_stack) {
            if (resolved) return;
            if (idx_child_stack != resolve_order && HasChildStack()) return;
            resolved = true;
            bool this_result = (node == nullptr) || (node->val > min && node->val < max);
            if (last_stack) result = last_stack->result && this_result;
            else result = this_result;
        }
    };

    class Solution {
    public:
        bool isValidBST(TreeNode *root) {
            const int order_root_node = 0;
            const int num_child_stack = 2;
            typedef StackFrame<order_root_node, num_child_stack> StackFrame;
            using StackFramePtr = StackFrame::StackFramePtr;
            vector<StackFramePtr> stacks;
            stacks.emplace_back(make_shared<StackFrame>(root, LONG_LONG_MIN, LONG_LONG_MAX));
            StackFramePtr current_stack = stacks.back();
            StackFramePtr last_stack = nullptr;

            while (!stacks.empty()) {
                current_stack = stacks.back();
                stacks.pop_back();

                while (current_stack->HasChildStack()) {
                    current_stack->Resolve(last_stack);
                    if (!current_stack->result) return false;
                    stacks.push_back(current_stack);
                    last_stack = current_stack;
                    current_stack = current_stack->CreateChildStack();
                }

                current_stack->Resolve(last_stack);
                if (!current_stack->result) return false;
            }

            return current_stack->result;
        }
    };
}

TEST(L0098_ValidateBinarySearchTree, CASE_TEST) {
    using namespace L0098;
    Solution s;
    auto *t0 = new TreeNode(0);
    auto *t1 = new TreeNode(1);
    auto *t2 = new TreeNode(2);
    auto *t3 = new TreeNode(3);
    auto *t4 = new TreeNode(4);
    auto *t5 = new TreeNode(5);
    auto *t6 = new TreeNode(6);
    t1->left = t0;
    t1->right = t2;
    t5->left = t4;
    t5->right = t6;
    t3->left = t1;
    t3->right = t5;
    EXPECT_TRUE(s.isValidBST(t3));
}

#endif //LEET_CODE_0098_VALIDATEBINARYSEARCHTREE_H_

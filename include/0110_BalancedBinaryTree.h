/*
 * 
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as:
 * 
 * a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 * 
 * 
 * 
 * Example 1:
 * 
 * Given the following tree [3,9,20,null,null,15,7]:
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * Return true.
 * 
 * Example 2:
 * 
 * Given the following tree [1,2,2,3,3,null,null,4,4]:
 * 
 *        1
 *       / \
 *      2   2
 *     / \
 *    3   3
 *   / \
 *  4   4
 * Return false.
 * 
 */

#ifndef LEET_CODE_0110_BALANCEDBINARYTREE_H_
#define LEET_CODE_0110_BALANCEDBINARYTREE_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0110 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    class Solution {
    private:
        int isBalanced_(TreeNode *node) {
            if (node == nullptr) return 0;

            int left_depth = isBalanced_(node->left);
            if (left_depth == -1) return -1;

            int right_depth = isBalanced_(node->right);
            if (right_depth == -1) return -1;

            if (abs(left_depth - right_depth) > 1) return -1;

            return max(left_depth, right_depth) + 1;
        }

    public:
        bool isBalanced(TreeNode *root) {
            return isBalanced_(root) != -1;
        }
    };

}

TEST(L0110_BalancedBinaryTree, CASE_TEST) {
    using namespace L0110;
    Solution s;

    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0110_BALANCEDBINARYTREE_H_

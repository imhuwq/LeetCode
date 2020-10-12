/*
 * 
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 *       5
 *      / \
 *     4   8
 *    /   / \
 *   11  13  4
 *  /  \      \
 * 7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 *
 *          1
 *     -2     -3
 *   1   3  -2  null
 * -1
 * 
 * 
 */

#ifndef LEET_CODE_0112_PATHSUM_H_
#define LEET_CODE_0112_PATHSUM_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0112 {
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
    public:
        bool hasPathSum(TreeNode *root, int sum) {
            if (root == nullptr) return false;
            if (root->val == sum and root->left == nullptr and root->right == nullptr) return true;
            return hasPathSum(root->left, sum - root->val) or hasPathSum(root->right, sum - root->val);
        }
    };
}

TEST(L0112_PathSum, CASE_TEST) {
    using namespace L0112;
    Solution s;

    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0112_PATHSUM_H_

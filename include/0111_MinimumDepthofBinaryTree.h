/*
 * 
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its minimum depth = 2.
 * 
 */

#ifndef LEET_CODE_0111_MINIMUMDEPTHOFBINARYTREE_H_
#define LEET_CODE_0111_MINIMUMDEPTHOFBINARYTREE_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0111 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    class Solution {
    public:
        int minDepth(TreeNode *root) {
            if (root == nullptr) return 0;
            if (root->left == nullptr) return minDepth(root->right) + 1;
            if (root->right == nullptr) return minDepth(root->left) + 1;
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        }
    };
}

TEST(L0111_MinimumDepthofBinaryTree, CASE_TEST) {
    using namespace L0111;
    Solution s;

    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0111_MINIMUMDEPTHOFBINARYTREE_H_

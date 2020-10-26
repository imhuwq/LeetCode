/*
 * 
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
 * return its depth = 3.
 * 
 */

#ifndef LEET_CODE_0104_MAXIMUMDEPTHOFBINARYTREE_H_
#define LEET_CODE_0104_MAXIMUMDEPTHOFBINARYTREE_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0104 {
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
        int maxDepth(TreeNode *root) {
            if (root == nullptr) return 0;
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    };

}

TEST(L0104_MaximumDepthofBinaryTree, CASE_TEST) {
    using namespace L0104;
    Solution s;

    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0104_MAXIMUMDEPTHOFBINARYTREE_H_

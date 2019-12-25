/*
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
 *     / \
 *    15   7
 */

#ifndef LEET_CODE_0104_MAXIMUM_DEPTH_OF_BINARY_TREE_H_
#define LEET_CODE_0104_MAXIMUM_DEPTH_OF_BINARY_TREE_H_

#include <stack>
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

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        int maxDepth(TreeNode *root) {
            if (root == NULL) return 0;
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    };
}

TEST(L0104_MAXIMUM_DEPTH_OF_BINARY_TREE, CASE_TEST) {
    L0104::Solution s;
    L0104::TreeNode tn1(1);
    L0104::TreeNode tn2(2);
    L0104::TreeNode tn3(2);
    L0104::TreeNode tn4(3);
    L0104::TreeNode tn5(4);
    L0104::TreeNode tn6(4);
    L0104::TreeNode tn7(3);

    tn1.left = &tn2;
    tn1.right = &tn3;
    tn2.left = &tn4;
    tn2.right = &tn5;
    tn3.left = &tn6;
    tn3.right = &tn7;

    EXPECT_EQ(s.maxDepth(&tn1), 3);
}

#endif //LEET_CODE_0104_MAXIMUM_DEPTH_OF_BINARY_TREE_H_

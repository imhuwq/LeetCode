/*
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

#ifndef LEET_CODE_0111_MINIMUM_DEPTH_OF_BINARY_TREE_H_
#define LEET_CODE_0111_MINIMUM_DEPTH_OF_BINARY_TREE_H_

#include <stack>
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
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    class Solution {
    public:
        int minDepth(TreeNode* root) {
            if (root == NULL) return 0;
            if (root->left == NULL) return minDepth(root->right) + 1;
            if (root->right == NULL) return minDepth(root->left) + 1;
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        }
    };

}

TEST(L0111_MINIMUM_DEPTH_OF_BINARY_TREE, CASE_TEST) {
    L0111::Solution s;
    L0111::TreeNode tn1(3);
    L0111::TreeNode tn2(9);
    L0111::TreeNode tn3(20);
    L0111::TreeNode tn4(15);
    L0111::TreeNode tn5(7);
    tn1.left = &tn2;
    tn1.right = &tn3;
    tn3.left = &tn4;
    tn3.right = &tn5;

    EXPECT_EQ(s.minDepth(&tn1), 2);
}

#endif //LEET_CODE_0111_MINIMUM_DEPTH_OF_BINARY_TREE_H_

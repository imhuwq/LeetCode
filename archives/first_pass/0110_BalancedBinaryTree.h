/*
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as:
 * 
 * a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * 
 * Example 1:
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
 * Given the following tree [1,2,2,3,3,null,null,4,4]:
 * 
 *        1
 *       / \
 *      2   2
 *     / \
 *    3   3
 *   / \
 *  4   4
 *  Return false.
 */

#ifndef LEET_CODE_0110_BALANCED_BINARY_TREE_H_
#define LEET_CODE_0110_BALANCED_BINARY_TREE_H_

#include <stack>
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

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        bool isBalanced(TreeNode *root) {
            int rootDepth = 0;
            return findDepth(root) != -1;
        }

    private:
        int findDepth(TreeNode *node) {
            if (node == NULL) return 0;

            int depthLeft = findDepth(node->left);
            int depthRight = findDepth(node->right);
            if (depthLeft == -1 || depthRight == -1)
                return -1;
            if (abs(depthLeft - depthRight) > 1) return -1;
            return max(depthLeft, depthRight) + 1;
        }
    };

}

TEST(L0110_BALANCED_BINARY_TREE, CASE_TEST) {
    L0110::Solution s;

    L0110::TreeNode tn1(3);
    L0110::TreeNode tn2(9);
    L0110::TreeNode tn3(20);
    L0110::TreeNode tn4(15);
    L0110::TreeNode tn5(7);

    tn1.left = &tn2;
    tn1.right = &tn3;
    tn3.left = &tn4;
    tn3.right = &tn5;
    EXPECT_TRUE(s.isBalanced(&tn1));

    L0110::TreeNode tn6(1);
    L0110::TreeNode tn7(2);
    L0110::TreeNode tn8(2);
    L0110::TreeNode tn9(3);
    L0110::TreeNode tn10(3);
    L0110::TreeNode tn11(4);
    L0110::TreeNode tn12(4);

    tn6.left = &tn7;
    tn6.right = &tn8;
    tn7.left = &tn9;
    tn7.right = &tn10;
    tn9.left = &tn11;
    tn9.right = &tn12;
    EXPECT_FALSE(s.isBalanced(&tn6));
}

#endif //LEET_CODE_0110_BALANCED_BINARY_TREE_H_

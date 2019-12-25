/*
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
 */

#ifndef LEET_CODE_0112_PATH_SUM_H_
#define LEET_CODE_0112_PATH_SUM_H_

#include <stack>
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

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}

        TreeNode *AddLeft(int val) {
            left = new TreeNode(val);
            return left;
        }

        TreeNode *AddRight(int val) {
            right = new TreeNode(val);
            return right;
        }

        ~TreeNode() {
            if (left != NULL) delete left;
            if (right != NULL) delete right;
            this->left = NULL;
            this->right = NULL;
        }
    };

    class Solution {
    public:
        bool hasPathSum(TreeNode *root, int sum) {
            if (root == NULL) return false;
            int sum_left = sum - root->val;
            if (sum_left == 0 && root->left == NULL && root->right == NULL) return true ;
            return hasPathSum(root->left, sum_left) or hasPathSum(root->right, sum_left);
        }
    };
}

TEST(L0112_PATH_SUM, CASE_TEST) {
    using namespace L0112;
    Solution s;
    TreeNode tn1(5);
    auto tn2 = tn1.AddLeft(4);
    auto tn3 = tn2->AddLeft(11);
    tn3->AddLeft(7);
    tn3->AddRight(2);
    auto tn4 = tn1.AddRight(8);
    tn4->AddLeft(13);
    auto tn5 = tn4->AddRight(4);
    tn5->AddRight(1);

    EXPECT_TRUE(s.hasPathSum(&tn1, 22));
}

#endif //LEET_CODE_0112_PATH_SUM_H_

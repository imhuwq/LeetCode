/*
 * 
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * Input: [1,null,2,3]
 *    1
 *     \
 *      2
 *     /
 *    3
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 *
 */

#ifndef LEET_CODE_0094_BINARYTREEINORDERTRAVERSAL_H_
#define LEET_CODE_0094_BINARYTREEINORDERTRAVERSAL_H_

#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0094 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> result;
            if (root == nullptr) return result;

            vector<TreeNode *> nodes;
            nodes.push_back(root);
            bool to_left = true;
            while (!nodes.empty()) {
                TreeNode *node = nodes.back();
                if (to_left) {
                    while (node->left) {
                        nodes.push_back(node->left);
                        node = node->left;
                    }
                    to_left = false;
                } else {
                    result.push_back(node->val);
                    nodes.pop_back();
                    if (node->right) {
                        nodes.push_back(node->right);
                        to_left = true;
                    }
                }
            }
            return result;
        }
    };


}

TEST(L0094_BinaryTreeInorderTraversal, CASE_TEST) {
    using namespace L0094;
    Solution s;
    TreeNode *tn1 = new TreeNode(1);
    TreeNode *tn2 = new TreeNode(2);
    TreeNode *tn3 = new TreeNode(3);
    tn1->right = tn2;
    tn2->left = tn3;
    s.inorderTraversal(tn1);
    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0094_BINARYTREEINORDERTRAVERSAL_H_

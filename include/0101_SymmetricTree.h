/*
 * 
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 *
 *           1
 *        /     \
 *       2       2
 *     /  \    /  \
 *    3   4   4   3
 *   /\  /\  /\  /\
 *  5 6 7 8 8 7 6  5
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 * 
 * 
 * Follow up: Solve it both recursively and iteratively.
 * 
 */

#ifndef LEET_CODE_0101_SYMMETRICTREE_H_
#define LEET_CODE_0101_SYMMETRICTREE_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0101 {
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
        bool isSymmetric(TreeNode *root) {
            if (root == nullptr) return true;

            TreeNode* left, *right;
            stack<TreeNode*> stacks;
            stacks.push(root->left);
            stacks.push(root->right);

            while (! stacks.empty()) {
                right = stacks.top(); stacks.pop();
                left = stacks.top(); stacks.pop();

                bool leftNull = left == nullptr;
                bool rightNull = right == nullptr;

                if (leftNull ^ rightNull) return false;
                if (leftNull & rightNull) continue;
                if (left->val != right->val) return false;

                stacks.push(left->right);
                stacks.push(right->left);
                stacks.push(left->left);
                stacks.push(right->right);
            }

            return true;
        }

    };

}

TEST(L0101_SymmetricTree, CASE_TEST) {
    using namespace L0101;
    Solution s;

    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0101_SYMMETRICTREE_H_

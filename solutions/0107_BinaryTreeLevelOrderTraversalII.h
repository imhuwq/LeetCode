/*
 * 
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its bottom-up level order traversal as:
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
 * 
 */

#ifndef LEET_CODE_0107_BINARYTREELEVELORDERTRAVERSALII_H_
#define LEET_CODE_0107_BINARYTREELEVELORDERTRAVERSALII_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0107 {
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
        void levelOrderBottom(TreeNode *node, vector<vector<int>> &result, int depth) {
            if (node == nullptr) return;

            result.resize(max(depth + 1, (int) result.size()));

            vector<int>& holder = result[depth];
            holder.push_back(node->val);

            levelOrderBottom(node->left, result, depth + 1);
            levelOrderBottom(node->right, result, depth + 1);
        }

    public:
        vector<vector<int>> levelOrderBottom(TreeNode *root) {
            vector<vector<int>> result;
            int depth = 0;

            levelOrderBottom(root, result, depth);

            vector<vector<int>> final(result.size());
            move(result.rbegin(), result.rend(), final.begin());
            return final;
        }
    };

}

TEST(L0107_BinaryTreeLevelOrderTraversalII, CASE_TEST) {
    using namespace L0107;
    Solution s;

    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0107_BINARYTREELEVELORDERTRAVERSALII_H_

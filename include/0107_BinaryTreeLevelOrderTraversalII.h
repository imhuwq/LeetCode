/*
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
 *   [3],
 * ]
 */

#ifndef LEET_CODE_0107_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H_
#define LEET_CODE_0107_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H_

#include <stack>
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

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        vector<vector<int>> levelOrderBottom(TreeNode *root) {
            vector<vector<int>> result;
            int depth = 0;

            levelOrderBottom(root, result, depth);

            vector<vector<int>> final(result.size());
            move(result.rbegin(), result.rend(), final.begin());
            return final;
        }

    private:
        void levelOrderBottom(TreeNode *node, vector<vector<int>> &result, int depth) {
            if (node == NULL) return;

            result.resize(max(depth + 1, (int)result.size()));
            vector<int> &levelResult = result[depth];
            levelResult.push_back(node->val);

            levelOrderBottom(node->left, result, depth + 1);
            levelOrderBottom(node->right, result, depth + 1);
        }
    };

}

TEST(L0107_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II, CASE_TEST) {
    L0107::Solution s;
    L0107::TreeNode tn1(3);
    L0107::TreeNode tn2(9);
    L0107::TreeNode tn3(20);
    L0107::TreeNode tn4(15);
    L0107::TreeNode tn5(7);

    tn1.left = &tn2;
    tn1.right = &tn3;
    tn3.left = &tn4;
    tn3.right = &tn5;

    vector<vector<int>> result = s.levelOrderBottom(&tn1);
    vector<vector<int>> answer = {{15, 7},
                                  {9,  20},
                                  {3}};
    EXPECT_EQ(result, answer);
}

#endif //LEET_CODE_0107_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H_

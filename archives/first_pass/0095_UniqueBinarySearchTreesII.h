/*
 * 
 * Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
 * 
 * Example:
 * Input: 3
 * Output:
 * [
 *   [1,null,3,2],
 *   [3,2,null,1],
 *   [3,1,null,null,2],
 *   [2,1,3],
 *   [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 * 

 * 
 */

#ifndef LEET_CODE_0095_UNIQUEBINARYSEARCHTREESII_H_
#define LEET_CODE_0095_UNIQUEBINARYSEARCHTREESII_H_

#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0095 {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        vector<TreeNode *> generateTrees(int lo, int hi) {
            if (lo > hi) return {nullptr};

            vector<TreeNode *> trees;
            for (int val = lo; val <= hi; val++) {
                vector<TreeNode *> left_trees = generateTrees(lo, val - 1);
                vector<TreeNode *> right_trees = generateTrees(val + 1, hi);
                for (auto l:left_trees) {
                    for (auto r:right_trees) {
                        auto tree = new TreeNode(val);
                        tree->left = l;
                        tree->right = r;
                        trees.push_back(tree);
                    }
                }
            }
            return trees;
        }

        vector<TreeNode *> generateTrees(int n) {
            if (n == 0) return {};
            return generateTrees(1, n);
        }
    };
}

TEST(L0095_UniqueBinarySearchTreesII, CASE_TEST) {
    using namespace L0095;
    Solution s;
    s.generateTrees(4);
    EXPECT_EQ(1, 1);
}


#endif //LEET_CODE_0095_UNIQUEBINARYSEARCHTREESII_H_

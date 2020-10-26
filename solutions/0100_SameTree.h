/*
 * 
 * Given two binary trees, write a function to check if they are the same or not.
 * Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
 * 
 * Example 1:
 * 
 * Input:     1         1
 *           / \       / \
 *          2   3     2   3
 *         [1,2,3],   [1,2,3]
 * Output: true
 * 
 * Example 2:
 * Input:     1         1
 *           /           \
 *          2             2
 *         [1,2],     [1,null,2]
 * Output: false
 * 
 * Example 3:
 * Input:     1         1
 *           / \       / \
 *          2   1     1   2
 *         [1,2,1],   [1,1,2]
 * Output: false
 * 
 */

#ifndef LEET_CODE_0100_SAMETREE_H_
#define LEET_CODE_0100_SAMETREE_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0100 {
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
        bool isSameTree(TreeNode *p, TreeNode *q) {
            bool p_null = p == nullptr, q_null = q == nullptr;
            if (p_null & q_null) return true;
            if (p_null ^ q_null) return false;
            if (p->val != q->val) return false;
            if (!isSameTree(p->left, q->left)) return false;
            return isSameTree(p->right, q->right);
        }
    };
}

TEST(L0100_SameTree, CASE_TEST) {
    using namespace L0100;
    Solution s;

    TreeNode *tree1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode *tree2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    EXPECT_TRUE(s.isSameTree(tree1, tree2));

    tree1 = new TreeNode(1, new TreeNode(2), nullptr);
    tree2 = new TreeNode(1, nullptr, new TreeNode(2));
    EXPECT_FALSE(s.isSameTree(tree1, tree2));

    tree1 = new TreeNode(1, new TreeNode(2), new TreeNode(1));
    tree2 = new TreeNode(1, new TreeNode(1), new TreeNode(2));
    EXPECT_FALSE(s.isSameTree(tree1, tree2));

    tree1 = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(1));
    tree2 = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(1));
    EXPECT_TRUE(s.isSameTree(tree1, tree2));

    tree1 = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(1));
    tree2 = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(4)), new TreeNode(1));
    EXPECT_FALSE(s.isSameTree(tree1, tree2));

    EXPECT_TRUE(s.isSameTree(nullptr, nullptr));
}

#endif //LEET_CODE_0100_SAMETREE_H_

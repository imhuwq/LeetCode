/*
 * Given two binary trees, write a function to check if they are the same or not.
 * 
 * Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
 * 
 * Example 1:
 * 
 * Input:     1         1
 *           / \       / \
 *          2   3     2   3
 * 
 *         [1,2,3],   [1,2,3]
 * Output: true
 *
 * Example 2:
 * Input:     1         1
 *           / \       / \
 *          2             2
 * 
 *         [1,2],     [1,null,2]
 * Output: false
 *
 *
 * Example 3:
 * Input:     1         1
 *           / \       / \
 *          2   1     1   2
 * 
 *         [1,2,1],   [1,1,2]
 * Output: false
 */

#ifndef LEET_CODE_0100_SAME_TREE_H_
#define LEET_CODE_0100_SAME_TREE_H_

#include <stack>
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

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        bool isSameTree(TreeNode *p, TreeNode *q) {
            bool pNull = p == NULL;
            bool qNull = q == NULL;
            if (pNull ^ qNull) return false;
            if (pNull & qNull) return true;

            if (p->val != q->val) return false;
            if (!isSameTree(p->left, q->left)) return false;
            return isSameTree(p->right, q->right);
        }
    };

}

TEST(L0100_SAME_TREE, CASE_TEST) {
    L0100::Solution s;

    L0100::TreeNode t11(1);
    L0100::TreeNode t12(2);
    L0100::TreeNode t13(3);
    t11.left = &t12;
    t11.right = &t13;

    L0100::TreeNode t21(1);
    L0100::TreeNode t22(2);
    L0100::TreeNode t23(3);
    t21.left = &t22;
    t21.right = &t23;

    EXPECT_TRUE(s.isSameTree(&t11, &t21));
}

#endif //LEET_CODE_0100_SAME_TREE_H_

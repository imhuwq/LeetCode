/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * But the following [1,2,2,null,3,null,3] is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 */

#ifndef LEET_CODE_0101_SYMMETRIC_TREE_H_
#define LEET_CODE_0101_SYMMETRIC_TREE_H_

#include <stack>
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

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        bool isSymmetric(TreeNode *root) {
            if (root == NULL) return true;
            return isSymmetric(root->left, root->right);
        }

    private:
        bool isSymmetric(TreeNode *p, TreeNode *q) {
            bool pNull = p == NULL;
            bool qNull = q == NULL;
            if (pNull ^ qNull) return false;
            if (pNull & qNull) return true;

            if (p->val != q->val) return false;
            if (!isSymmetric(p->left, q->right)) return false;
            return isSymmetric(p->right, q->left);
        }
    };

}

TEST(L0101_SYMMETRIC_TREE, CASE_TEST) {
    L0101::Solution s;

    L0101::TreeNode tn1(1);
    L0101::TreeNode tn2(2);
    L0101::TreeNode tn3(2);
    L0101::TreeNode tn4(3);
    L0101::TreeNode tn5(4);
    L0101::TreeNode tn6(4);
    L0101::TreeNode tn7(3);
    tn1.left = &tn2;
    tn1.right = &tn3;
    tn2.left = &tn4;
    tn2.right = &tn5;
    tn3.left = &tn6;
    tn3.right = &tn7;
    EXPECT_TRUE(s.isSymmetric(&tn1));
}

#endif //LEET_CODE_0101_SYMMETRIC_TREE_H_

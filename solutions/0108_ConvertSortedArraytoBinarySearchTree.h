/*
 * 
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * 
 * Example:
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
 * 
 *       0
 *      / \
 *    -3   9
 *    /   /
 *  -10  5
 * 
 */

#ifndef LEET_CODE_0108_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H_
#define LEET_CODE_0108_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0108 {
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
        void sortedArrayToBST(TreeNode*& node, vector<int> &nums, int lo, int hi) {
            if (lo > hi) return;
            int mid = lo + (hi - lo) / 2;
            node = new TreeNode(nums[mid]);
            sortedArrayToBST(node->left, nums, lo, mid - 1);
            sortedArrayToBST(node->right, nums, mid + 1, hi);
        }

    public:
        TreeNode *sortedArrayToBST(vector<int> &nums) {
            if (nums.empty()) return nullptr;

            int mid = nums.size() / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            sortedArrayToBST(root->left, nums, 0, mid - 1);
            sortedArrayToBST(root->right, nums, mid + 1, nums.size() - 1);
            return root;
        }
    };
}

TEST(L0108_ConvertSortedArraytoBinarySearchTree, CASE_TEST) {
    using namespace L0108;
    Solution s;

    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0108_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H_

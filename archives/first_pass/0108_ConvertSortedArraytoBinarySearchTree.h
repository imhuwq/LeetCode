/*
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
 */

#ifndef LEET_CODE_0108_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H_
#define LEET_CODE_0108_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H_

#include <stack>
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

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        TreeNode *sortedArrayToBST(vector<int> &nums) {
            if (nums.empty()) return NULL;

            TreeNode *tree = NULL;
            sortedArrayToBST(tree, nums, 0, nums.size() - 1);
            return tree;
        }

    private:
        void sortedArrayToBST(TreeNode *&node, vector<int> &nums, int beg, int end) {
            if (beg > end) return;
            if (beg == end) {
                node = new TreeNode(nums[end]);
                return;
            }

            int mid = (beg + end) >> 1;
            if (mid == beg) mid++;
            node = new TreeNode(nums[mid]);
            sortedArrayToBST(node->left, nums, beg, mid - 1);
            sortedArrayToBST(node->right, nums, mid + 1, end);
        }
    };

}

TEST(L0108_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE, CASE_TEST) {
    L0108::Solution s;

    vector<int> nums = {-10, -3, 0, 5, 9};
    L0108::TreeNode* tree = s.sortedArrayToBST(nums);

    EXPECT_EQ(tree->val, 0);

    EXPECT_EQ(tree->left->val, -3);
    EXPECT_EQ(tree->right->val, 9);


}

#endif //LEET_CODE_0108_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H_

/*
 * 
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 1,1,5,4 -> 1,4,1,5
 * 1,1,5,2,4 -> 1,1,5,4,2
 * 1,1,5,4,2 -> 1,2,1,4,5
 * 1,2,6,5,4,2 -> 1,4,2,2,5,6
 * 1,4,6,5,3,2 -> 1,5,2,3,4,6
 * 1,2,6,5,1,2 -> 1,2,6,5,2,1
 */

#ifndef LEET_CODE_0031_NEXT_PERMUTATION_H_
#define LEET_CODE_0031_NEXT_PERMUTATION_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0031 {
    class Solution {
    public:
        void nextPermutation(vector<int> &nums) {
            size_t left = 0;
            size_t right = 0;
            bool found = false;

            size_t i = 0;
            for (; i < nums.size() - 1; i++) {
                if (nums[i] < nums[i + 1]) {
                    left = i;
                    right = i + 1;
                    found = true;
                } else {
                    if (nums[i] > nums[left] && nums[i] <= nums[right]) right = i;
                }
            }

            if (nums[i] > nums[left] && nums[i] <= nums[right]) right = i;

            if (found) {
                std::swap(nums[left], nums[right]);
                std::reverse(nums.begin() + left + 1, nums.end());
            } else {
                std::reverse(nums.begin(), nums.end());
            }

        }
    };

}

TEST(L0031_NEXT_PERMUTATION, CASE_TEST) {
    using namespace L0031;
    Solution s;

    vector<int> qes1 = {1, 2, 3};
    vector<int> ans1 = {1, 3, 2};
    s.nextPermutation(qes1);
    EXPECT_EQ(qes1, ans1);

    vector<int> qes2 = {3, 2, 1};
    vector<int> ans2 = {1, 2, 3};
    s.nextPermutation(qes2);
    EXPECT_EQ(qes2, ans2);

    vector<int> qes3 = {1, 1, 5};
    vector<int> ans3 = {1, 5, 1};
    s.nextPermutation(qes3);
    EXPECT_EQ(qes3, ans3);

    vector<int> qes4 = {1, 1, 5, 4};
    vector<int> ans4 = {1, 4, 1, 5};
    s.nextPermutation(qes4);
    EXPECT_EQ(qes4, ans4);

    vector<int> qes5 = {1, 2, 3};
    vector<int> ans5 = {1, 3, 2};
    s.nextPermutation(qes5);
    EXPECT_EQ(qes5, ans5);

    vector<int> qes6 = {1, 2, 3};
    vector<int> ans6 = {1, 3, 2};
    s.nextPermutation(qes6);
    EXPECT_EQ(qes6, ans6);

    vector<int> qes7 = {2, 3, 1, 3, 3};
    vector<int> ans7 = {2, 3, 3, 1, 3};
    s.nextPermutation(qes7);
    EXPECT_EQ(qes7, ans7);
}

// 1154 1415

#endif //LEET_CODE_0031_NEXT_PERMUTATION_H_

/*
 * 
 * Given a collection of distinct integers, return all possible permutations.
 * Example:
 * Input: [1,2,3]
 * Output:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 * 
 */

#ifndef LEET_CODE_0046_PERMUTATIONS_H_
#define LEET_CODE_0046_PERMUTATIONS_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0046 {
    class Solution {
    public:
        void permute(vector<int> &nums, int start, vector<vector<int>> &permutations) {
            if (start == nums.size() - 1) {
                permutations.push_back(nums);
                return;
            }

            for (int i = start; i < nums.size(); i++) {
                std::swap(nums[start], nums[i]);
                permute(nums, start + 1, permutations);
                std::swap(nums[start], nums[i]);
            }
        }

        vector<vector<int>> permute(vector<int> &nums) {
            int size = nums.size();
            for (int i = size - 1; i > 1; i--) size *= i;
            vector<vector<int>> permutations;
            permutations.reserve(size);
            permute(nums, 0, permutations);
            return permutations;
        }
    };

}

TEST(L0046_PERMUTATIONS, CASE_TEST) {
    using namespace L0046;
    Solution s;
    vector<int> vec1 = {1, 2, 3};
    s.permute(vec1);
    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0046_PERMUTATIONS_H_

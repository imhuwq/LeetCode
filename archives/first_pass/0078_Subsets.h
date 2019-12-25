/*
 * 
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * Input: nums = [1,2,3]
 * Output:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 * 
 */

#ifndef LEET_CODE_0078_SUBSETS_H_
#define LEET_CODE_0078_SUBSETS_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0078 {
    class Solution {
    public:
        void subsets(vector<int> &nums, int start, vector<int> &set, vector<vector<int>> &sets) {
            sets.push_back(set);
            for (int idx = start; idx < nums.size(); idx++) {
                set.push_back(nums[idx]);
                subsets(nums, idx + 1, set, sets);
                set.pop_back();
            }
        }

        vector<vector<int>> subsets(vector<int> &nums) {
            vector<int> set;
            vector<vector<int>> sets;
            subsets(nums, 0, set, sets);
            return sets;
        }

        vector<vector<int>> subsets(vector<int> &&nums) {
            return subsets(nums);
        }

    };
}

TEST(L0078_Subsets, CASE_TEST) {
    using namespace L0078;
    Solution s;
    s.subsets({1, 2, 3});
    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0078_SUBSETS_H_

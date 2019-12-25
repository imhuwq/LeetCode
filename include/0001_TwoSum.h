/*
 * 
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * 
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 */

#ifndef LEET_CODE_0001_TWOSUM_H_
#define LEET_CODE_0001_TWOSUM_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0001 {
    class Solution {
    public:
        vector<int> twoSum(vector<int> &nums, int target) {
            map<int, int> reminders;

            for (int idx = 0; idx < nums.size(); idx++) {
                int num = nums[idx];
                auto find = reminders.find(num);
                if (find != reminders.end()) {
                    return {find->second, idx};
                } else {
                    reminders[target - num] = idx;
                }
            }

            return {};
        }
    };

}

TEST(L0001_TwoSum, CASE_TEST) {
    using namespace L0001;
    Solution s;

    vector<int> nums = {2, 7, 11, 15};
    vector<int> result1 = {0, 1};
    vector<int> result2 = {0, 2};
    vector<int> result3 = {0, 3};
    vector<int> result4 = {2, 3};

    EXPECT_EQ(s.twoSum(nums, 9), result1);
    EXPECT_EQ(s.twoSum(nums, 13), result2);
    EXPECT_EQ(s.twoSum(nums, 17), result3);
    EXPECT_EQ(s.twoSum(nums, 26), result4);
}

#endif //LEET_CODE_0001_TWOSUM_H_

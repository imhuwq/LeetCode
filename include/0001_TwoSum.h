/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return[0, 1].
 */

#ifndef LEET_CODE_0001_TWO_SUM_H_
#define LEET_CODE_0001_TWO_SUM_H_

#include <vector>
#include <map>
#include <gtest/gtest.h>

using namespace std;

namespace L0001 {
    class Solution {
    public:
        Solution() = default;

        vector<int> twoSum(vector<int> &nums, int target) {
            map<int, int> complement_map;
            for (int i = 0, num = 0, complement = 0; i < nums.size(); i++) {
                num = nums[i];
                if (complement_map.find(num) != complement_map.end()) return {complement_map.at(num), i};
                complement = target - num;
                complement_map[complement] = i;
            }
            throw runtime_error("no solution found");
        }

        bool Test() {
            vector<int> nums = {2, 7, 11, 15};
            int target = 9;

            vector<int> result = twoSum(nums, target);
            return result[0] == 0 && result[1] == 1;
        }
    };
}

TEST(L0001_TWO_SUM, CASE_TEST) {
    L0001::Solution s;
    EXPECT_TRUE(s.Test());
}

#endif //LEET_CODE_0001_TWO_SUM_H_

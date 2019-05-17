/*
 * 
 * Given an array nums of n integers and an integer target, find three integers in nums such that
 * the sum is closest to target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 * 
 * Example:
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 */

#ifndef LEET_CODE_0016_3SUM_CLOSEST_H_
#define LEET_CODE_0016_3SUM_CLOSEST_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0016 {
    class Solution {
    public:
        int Sum(vector<int> &nums) {
            int rt = 0;
            for (auto num:nums) rt += num;
            return rt;
        }

        int threeSumClosest(vector<int> &nums, int target) {
            if (nums.size() <= 3) return Sum(nums);
            std::sort(nums.begin(), nums.end());

            int current_diff;
            int current_target;
            int closest_diff = 0x7fffffff;
            int closest_target;

            int first, second, third;
            int first_idx, second_idx, third_idx;
            for (first_idx = 0; first_idx < nums.size() - 2; first_idx++) {
                first = nums[first_idx];
                second_idx = first_idx + 1;
                third_idx = nums.size() - 1;

                while (second_idx < third_idx) {
                    second = nums[second_idx];
                    third = nums[third_idx];
                    current_target = first + second + third;
                    current_diff = abs(current_target - target);

                    if (current_diff == 0) {
                        return current_target;
                    }

                    if (current_diff < closest_diff) {
                        // 更新 closest_diff
                        closest_diff = current_diff;
                        closest_target = current_target;
                    }

                    // 缩小 diff
                    if (current_target > target) {
                        third_idx--;
                        if (nums[third_idx] == third) third_idx--;
                    } else {
                        second_idx++;
                        if (nums[second_idx] == second) second_idx++;
                    }

                }
            }

            return closest_target;
        }
    };

}

TEST(L0016_3SUM_CLOSEST, CASE_TEST) {
    using namespace L0016;
    Solution s;
    vector<int> vec1 = {-1, 2, 1, -4};
    EXPECT_EQ(s.threeSumClosest(vec1, 1), 2);
}

#endif //LEET_CODE_0016_3SUM_CLOSEST_H_

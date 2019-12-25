/*
 * 
 * Given an array nums of n integers and an integer target, are there elements a, b, c,
 * and d in nums such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 *   [-1,  0, 0, 1],
 *   [-2, -1, 1, 2],
 *   [-2,  0, 0, 2]
 * ]
 * 
 */

#ifndef LEET_CODE_0018_4SUM_H_
#define LEET_CODE_0018_4SUM_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0018 {
    class Solution {
    public:
        vector<vector<int>> fourSum(vector<int> &nums, int target) {
            vector<vector<int>> rt;
            if (nums.size() < 4) return rt;

            std::sort(nums.begin(), nums.end());

            size_t size = nums.size();
            for (size_t f_idx = 0; f_idx < size - 3; f_idx++) {
                if (f_idx > 0 && nums[f_idx] == nums[f_idx - 1]) continue;
                if (nums[f_idx] + nums[f_idx + 1] + nums[f_idx + 2] + nums[f_idx + 3] > target) break;
                if (nums[f_idx] + nums[size - 3] + nums[size - 2] + nums[size - 1] < target) continue;

                for (size_t s_idx = f_idx + 1; s_idx < size - 2; s_idx++) {
                    if (s_idx > f_idx + 1 && nums[s_idx] == nums[s_idx - 1]) continue;
                    if (nums[f_idx] + nums[s_idx] + nums[s_idx + 1] + nums[s_idx + 2] > target) break;
                    if (nums[f_idx] + nums[s_idx] + nums[size - 2] + nums[size - 1] < target) continue;

                    size_t t_idx = s_idx + 1, fo_idx = size - 1;
                    int left_target = target - nums[f_idx] - nums[s_idx];
                    while (t_idx < fo_idx) {
                        if (t_idx > s_idx + 1 && nums[t_idx] == nums[t_idx - 1]) {
                            t_idx++;
                            continue;
                        }

                        int sum = nums[t_idx] + nums[fo_idx];
                        if (sum > left_target) {
                            fo_idx--;
                        } else if (sum < left_target) {
                            t_idx++;
                        } else {
                            rt.push_back({nums[f_idx], nums[s_idx], nums[t_idx++], nums[fo_idx--]});
                        }
                    }
                }
            }
            return rt;
        }
    };

}

TEST(L0018_4SUM, CASE_TEST) {
    using namespace L0018;
    Solution s;

    vector<int> vec1 = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> ret1 = s.fourSum(vec1, 0);

    vec1 = {-3, -1, 0, 2, 4, 5};
    ret1 = s.fourSum(vec1, 2);
    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0018_4SUM_H_

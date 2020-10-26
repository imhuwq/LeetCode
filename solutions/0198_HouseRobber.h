/*
 * 
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 * 
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 *              Total amount you can rob = 1 + 3 = 4.
 * 
 * Example 2:
 * Input: nums = [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
 *              Total amount you can rob = 2 + 9 + 1 = 12.
 * 
 * 
 * Constraints:
 * 0 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 * 
 */

#ifndef LEET_CODE_0198_HOUSEROBBER_H_
#define LEET_CODE_0198_HOUSEROBBER_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0198 {
    class Solution {
    public:
        int rob(vector<int> &nums) {
            if (nums.empty()) return 0;
            int before_2 = 0, before_1 = nums[0];
            int tmp;
            for (int i = 1; i < nums.size(); i++) {
                tmp = before_1;
                before_1 = max(before_2 + nums[i], before_1);
                before_2 = tmp;
            }
            return max(before_2, before_1);
        }

        int rob(vector<int> &&nums) {
            return rob(nums);
        }


    };

}

TEST(L0198_HouseRobber, CASE_TEST) {
    using namespace L0198;
    Solution s;

    EXPECT_EQ(s.rob({1, 2, 3, 1}), 4);
}

#endif //LEET_CODE_0198_HOUSEROBBER_H_

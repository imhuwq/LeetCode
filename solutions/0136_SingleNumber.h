/*
 * 
 * Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
 * 
 * Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?
 * 
 * 
 * Example 1:
 * Input: nums = [2,2,1]
 * Output: 1
 * 
 * Example 2:
 * Input: nums = [4,1,2,1,2]
 * Output: 4
 * 
 * Example 3:
 * Input: nums = [1]
 * Output: 1
 * 
 * Constraints:
 * 1 <= nums.length <= 3 * 104
 * -3 * 104 <= nums[i] <= 3 * 104
 * Each element in the array appears twice except for one element which appears only once.
 * 
 */

#ifndef LEET_CODE_0136_SINGLENUMBER_H_
#define LEET_CODE_0136_SINGLENUMBER_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0136 {
    class Solution {
    public:
        int singleNumber(vector<int> &nums) {
            int res = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                res = res ^ nums[i];
            }
            return res;
        }

        int singleNumber(vector<int> &&nums) {
            return singleNumber(nums);
        }
    };
}

TEST(L0136_SingleNumber, CASE_TEST) {
    using namespace L0136;
    Solution s;

    EXPECT_EQ(s.singleNumber({2, 2, 1}), 1);
    EXPECT_EQ(s.singleNumber({4, 1, 2, 1, 2}), 4);
    EXPECT_EQ(s.singleNumber({1}), 1);

}

#endif //LEET_CODE_0136_SINGLENUMBER_H_

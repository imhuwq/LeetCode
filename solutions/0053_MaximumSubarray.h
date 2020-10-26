/*
 * 
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * Follow up:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 * 
 */

#ifndef LEET_CODE_0053_MAXIMUMSUBARRAY_H_
#define LEET_CODE_0053_MAXIMUMSUBARRAY_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0053 {
    class Solution {
    public:
        int maxSubArray(vector<int> &nums) {
            if (nums.empty()) return 0;

            int final_max = nums[0];
            int current_max = nums[0];

            for (size_t i = 1; i < nums.size(); i++) {
                current_max = max(current_max + nums[i], nums[i]);
                final_max = max(final_max, current_max);
            }

            return final_max;
        }
    };

}

TEST(L0053_MaximumSubarray, CASE_TEST) {
    using namespace L0053;
    Solution s;

    vector<int> input;

    input = {-2};
    EXPECT_EQ(s.maxSubArray(input), -2);

    input = {-2, 1};
    EXPECT_EQ(s.maxSubArray(input), 1);

    input = {-2, 1, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(s.maxSubArray(input), 6);
}

#endif //LEET_CODE_0053_MAXIMUMSUBARRAY_H_

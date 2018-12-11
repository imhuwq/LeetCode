/*
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * Follow up:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

#ifndef LEET_CODE_0053_MAXIMUM_SUBARRAY_H_
#define LEET_CODE_0053_MAXIMUM_SUBARRAY_H_

#include <stack>
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
            /*
             * The maximum sum in the first I elements is either the maximum sum in the first i - 1 elements (MaxSoFar),
             * or it is that of a sub-vector that ends in position i (which we'll call MaxHere).
             */
            if (nums.empty()) return 0;

            int maxSoFar = nums[0];
            int maxHere = nums[0];

            for (size_t i = 1; i < nums.size(); i++) {
                maxHere = max(maxHere + nums[i], nums[i]);
                maxSoFar = max(maxSoFar, maxHere);
            }

            return maxSoFar;
        }
    };

}

TEST(L0053_MAXIMUM_SUBARRAY, CASE_TEST) {
    L0053::Solution s;

    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(s.maxSubArray(nums1), 6);
}

#endif //LEET_CODE_0053_MAXIMUM_SUBARRAY_H_

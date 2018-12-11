/*
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 * 
 * Example 1:
 * Input: [2,2,1]
 * Output: 1
 * 
 * Example 2:
 * Input: [4,1,2,1,2]
 * Output: 4
 */

#ifndef LEET_CODE_0136_SINGLE_NUMBER_H_
#define LEET_CODE_0136_SINGLE_NUMBER_H_

#include <stack>
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
            int result = 0;
            for (int n:nums) result ^= n;
            return result;
        }
    };

}

TEST(L0136_SINGLE_NUMBER, CASE_TEST) {
    using namespace L0136;
    Solution s;

    vector<int> nums1 = {2, 2, 1};
    EXPECT_EQ(s.singleNumber(nums1), 1);

    vector<int> nums2 = {4, 1, 2, 1, 2};
    EXPECT_EQ(s.singleNumber(nums2), 4);

}

#endif //LEET_CODE_0136_SINGLE_NUMBER_H_

/*
 * Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the number 0 itself.
 * 
 * Example 1:
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * Example 2:
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 */

#ifndef LEET_CODE_0066_PLUS_ONE_H_
#define LEET_CODE_0066_PLUS_ONE_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0066 {

    class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            vector<int> tmp(digits.size(), 0);
            int sum = 0;
            int carry = 1;
            for (int i = digits.size() - 1; i >= 0; i--) {
                sum = digits[i] + carry;
                if (sum >= 10) {
                    carry = 1;
                    tmp[i] = sum - 10;
                } else {
                    carry = 0;
                    tmp[i] = sum;
                }
            }

            if (carry == 0) return tmp;

            vector<int> result(tmp.size() + 1);
            result[0] = 1;
            move(tmp.begin(), tmp.end(), result.begin() + 1);
            return result;
        }
    };

}

TEST(L0066_PLUS_ONE, CASE_TEST) {
    L0066::Solution s;

    vector<int> nums1 = {1, 2, 3};
    vector<int> results1 = {1, 2, 4};
    EXPECT_EQ(s.plusOne(nums1), results1);

    vector<int> nums2 = {4, 3, 2, 1};
    vector<int> results2 = {4, 3, 2, 2};
    EXPECT_EQ(s.plusOne(nums2), results2);
}

#endif //LEET_CODE_0066_PLUS_ONE_H_

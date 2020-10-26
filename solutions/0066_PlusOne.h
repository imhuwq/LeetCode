/*
 * 
 * Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 * The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
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
 * 
 */

#ifndef LEET_CODE_0066_PLUSONE_H_
#define LEET_CODE_0066_PLUSONE_H_

#include <map>
#include <stack>
#include <queue>
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
            vector<int> output(digits.size() + 1, 0);

            int carry = 1;
            int value = 0;
            for (int idx = digits.size(); idx > 0; idx--) {
                value = digits[idx-1];
                value += carry;
                carry = value / 10;
                value = value % 10;
                output[idx] = value;
            }

            output[0] = carry;
            if (output[0] == 0) {
                move(output.begin() + 1, output.end(), output.begin());
                output.pop_back();
            }
            return output;
        }
    };
}

TEST(L0066_PlusOne, CASE_TEST) {
    using namespace L0066;
    Solution s;

    vector<int> input;
    vector<int> output;

    input = {1, 2, 3};
    output = {1, 2, 4};
    EXPECT_EQ(s.plusOne(input), output);

    input = {1, 2, 9};
    output = {1, 3, 0};
    EXPECT_EQ(s.plusOne(input), output);

    input = {9, 9, 9};
    output = {1, 0, 0, 0};
    EXPECT_EQ(s.plusOne(input), output);
}

#endif //LEET_CODE_0066_PLUSONE_H_

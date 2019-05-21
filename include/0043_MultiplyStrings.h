/*
 * 
 * Given two non-negative integers num1 and num2 represented as strings,
 * return the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * Note:
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0 itself.
 */

#ifndef LEET_CODE_0043_MULTIPLY_STRINGS_H_
#define LEET_CODE_0043_MULTIPLY_STRINGS_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0043 {
    class Solution {
    public:
        string multiply(string num1, string num2) {
            if (num1.size() == 0 || num2.size() == 0) return "";
            else if (num1 == "0" || num2 == "0") return "0";

            string possible(num1.size() + num2.size() + 1, '0');

            int above, below, index, value, carry = 0;
            for (int below_idx = num2.size() - 1; below_idx >= 0; below_idx--) {
                below = num2[below_idx] - '0';
                index = possible.size() - num2.size() + below_idx;
                for (int above_idx = num1.size() - 1; above_idx >= 0; above_idx--) {
                    above = num1[above_idx] - '0';
                    value = below * above + carry + (possible[index] - '0');
                    carry = value / 10;
                    value = value % 10;
                    possible[index--] = '0' + value;
                }
                if (carry != 0) possible[index] = '0' + carry;
                carry = 0;
            }

            int start = possible.find_first_not_of('0');
            return string(possible.begin() + start, possible.end());
        }
    };

}

TEST(L0043_MULTIPLY_STRINGS, CASE_TEST) {
    using namespace L0043;
    Solution s;

    EXPECT_EQ(s.multiply("3", "6"), "18");
    EXPECT_EQ(s.multiply("123", "456"), "56088");
    EXPECT_EQ(s.multiply("9", "99"), "891");
}

#endif //LEET_CODE_0043_MULTIPLY_STRINGS_H_

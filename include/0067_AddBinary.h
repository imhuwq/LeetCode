/*
 * 
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 * 
 * Constraints:
 * Each string consists only of '0' or '1' characters.
 * 1 <= a.length, b.length <= 10^4
 * Each string is either "0" or doesn't contain any leading zero.
 * 
 */

#ifndef LEET_CODE_0067_ADDBINARY_H_
#define LEET_CODE_0067_ADDBINARY_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0067 {
    class Solution {
    public:
        string addBinary(string a, string b) {
            string result(max(a.size(),  b.size()) + 1, ' ');
            int idx = result.size() - 1;

            int carry = 0;
            int val_a = 0;
            int val_b = 0;
            int value = 0;
            while (!a.empty() or !b.empty()) {
                if (a.empty()) {
                    val_a = 0;
                } else {
                    val_a = a.back() - '0';
                    a.pop_back();
                }

                if (b.empty()) {
                    val_b = 0;
                } else {
                    val_b = b.back() - '0';
                    b.pop_back();
                }

                value = val_a + val_b + carry;
                carry = value / 2;
                value = value % 2;
                result[idx] = '0' + value;
                idx--;
            }

            result[0] = '0' + carry;
            if (result[0] == ' ' or result[0] == '0') {
                move(result.begin() + 1, result.end(), result.begin());
                result.pop_back();
            }

            return result;
        }
    };
}

TEST(L0067_AddBinary, CASE_TEST) {
    using namespace L0067;
    Solution s;

    EXPECT_EQ(s.addBinary("11", "1"), "100");
    EXPECT_EQ(s.addBinary("100", "11"), "111");

}

#endif //LEET_CODE_0067_ADDBINARY_H_

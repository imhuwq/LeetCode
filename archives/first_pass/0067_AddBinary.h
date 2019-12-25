/*
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
 */

#ifndef LEET_CODE_0067_ADD_BINARY_H_
#define LEET_CODE_0067_ADD_BINARY_H_

#include <stack>
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
            char zero = '0';
            char one = '1';

            size_t size_a = a.size();
            size_t size_b = b.size();

            string &short_str = size_a >= size_b ? b : a;
            string &long_str = size_a >= size_b ? a : b;
            size_t size_long = long_str.size();
            size_t size_short = short_str.size();

            int carry = 0;
            string str(size_long, zero);
            size_t size_head = size_long - size_short;
            for (int i = size_short - 1; i >= 0; i--) {
                int sum = (short_str[i] - zero) + (long_str[size_head + i] - zero) + carry;
                if (sum >= 2) {
                    sum -= 2;
                    carry = 1;
                } else {
                    carry = 0;
                }
                str[size_head + i] = (char) sum + zero;
            }

            for (int i = size_head - 1; i >= 0; i--) {
                int sum = long_str[i] - zero + carry;
                if (sum >= 2) {
                    sum -= 2;
                    carry = 1;
                } else {
                    carry = 0;
                }
                str[i] = (char) sum + zero;
            }

            if (carry == 0) return str;
            string final_str(str.size() + 1, one);
            move(str.begin(), str.end(), final_str.begin() + 1);
            return final_str;
        }
    };

}

TEST(L0067_ADD_BINARY, CASE_TEST) {
    L0067::Solution s;

    string a1 = "11";
    string b1 = "1";
    EXPECT_EQ(s.addBinary(a1, b1), "100");

    string a2 = "1010";
    string b2 = "1011";
    EXPECT_EQ(s.addBinary(a2, b2), "10101");

    string a3 = "100";
    string b3 = "110010";
    EXPECT_EQ(s.addBinary(a3, b3), "110110");
}

#endif //LEET_CODE_0067_ADD_BINARY_H_

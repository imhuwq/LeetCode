/*
 * 
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII,
 * which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII.
 * Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same
 * principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 * I can be placed before V (5) and X (10) to make 4 and 9.
 * X can be placed before L (50) and C (100) to make 40 and 90.
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
 * 
 * Example 1:
 * Input: 3
 * Output: "III"
 * 
 * Example 2:
 * Input: 4
 * Output: "IV"
 * 
 * Example 3:
 * Input: 9
 * Output: "IX"
 * 
 * Example 4:
 * Input: 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 * 
 * Example 5:
 * Input: 1994
 * Output: "MCMXCIV"
 */

#ifndef LEET_CODE_0012_INTEGER_TO_ROMAN_H_
#define LEET_CODE_0012_INTEGER_TO_ROMAN_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0012 {
    class Solution {
    public:
        string pack(int count, char one, char five, char ten) {
            if (count == 0) return "";

            string rt;
            if (count < 4) {
                for (int i = 0; i < count; i++) rt += one;
            } else if (count == 4) {
                rt += one;
                rt += five;
            } else if (count == 5) {
                rt += five;
            } else if (count == 9) {
                rt += one;
                rt += ten;
            } else {
                rt += five;
                for (int i = 0; i < count - 5; i++) rt += one;
            }
            return rt;
        }

        string intToRoman(int num) {
            if (num > 3999) num = 3999;
            char units[4][3] = {{'I', 'V', 'X'},
                                {'X', 'L', 'C'},
                                {'C', 'D', 'M'},
                                {'M', 'M', 'M'}};
            int counts[4];
            for (int idx = 0; idx < 4; idx++) {
                counts[idx] = num % 10;
                num /= 10;
            }

            string rt;
            for (int idx = 3; idx >= 0; idx--) {
                int count = counts[idx];
                char *unit = units[idx];
                rt += pack(count, unit[0], unit[1], unit[2]);
            }

            return rt;
        }
    };
}

TEST(L0012_INTEGER_TO_ROMAN, CASE_TEST) {
    using namespace L0012;
    Solution s;

    EXPECT_EQ(s.intToRoman(3), "III");
    EXPECT_EQ(s.intToRoman(4), "IV");
    EXPECT_EQ(s.intToRoman(9), "IX");
    EXPECT_EQ(s.intToRoman(58), "LVIII");
    EXPECT_EQ(s.intToRoman(1994), "MCMXCIV");
}

#endif //LEET_CODE_0012_INTEGER_TO_ROMAN_H_

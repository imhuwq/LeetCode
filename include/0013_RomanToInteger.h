/*
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
 * For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is
 * simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII.
 * Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same
 * principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 * I can be placed before V (5) and X (10) to make 4 and 9.
 * X can be placed before L (50) and C (100) to make 40 and 90.
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
 *
 * Example 1:
 * Input: "III"
 * Output: 3
 *
 * Example 2:
 * Input: "IV"
 * Output: 4
 *
 * Example 3:
 * Input: "IX"
 * Output: 9
 *
 * Example 4:
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 *
 * Example 5:
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */

#ifndef LEET_CODE_0013_ROMAN_TO_INTEGER_H_
#define LEET_CODE_0013_ROMAN_TO_INTEGER_H_

#include <map>
#include <string>
#include <gtest/gtest.h>

using namespace std;

namespace L0013 {
    class Solution {
    public:
        Solution() = default;

        int romanToInt(const string &s) {
            int result = 0;
            int current = 0;
            int last = 1001;
            for (const char &c:s) {
                current = maps_[c];
                if (current > last) result -= (last + last - current);
                else result += current;
                last = current;
            }
            return result;
        }

        bool Test() {
            return (romanToInt("I") == 1) &&
                   (romanToInt("III") == 3) &&
                   (romanToInt("IV") == 4) &&
                   (romanToInt("IX") == 9) &&
                   (romanToInt("LVIII") == 58) &&
                   (romanToInt("MCMXCIV") == 1994);
        }

    private:
        map<char, int> maps_ = {{'I', 1},
                                {'V', 5},
                                {'X', 10},
                                {'L', 50},
                                {'C', 100},
                                {'D', 500},
                                {'M', 1000}};
    };
}


TEST(L0013_ROMAN_TO_INTEGER, CASE_TEST) {
    L0013::Solution s;
    EXPECT_TRUE(s.Test());
}

#endif //LEET_CODE_0013_ROMAN_TO_INTEGER_H_

/*
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a number of rows:
 * 
 * string convert(string s, int numRows);
 * Example 1:
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * Example 2:
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */

#ifndef LEET_CODE_0006_ZIGZAG_CONVERSION_H_
#define LEET_CODE_0006_ZIGZAG_CONVERSION_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0006 {
    class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows == 1) return s;

            int row = 0;
            bool going_down = false;
            vector<string> lines(numRows);
            for (char c: s) {
                lines[row] += c;
                if (row == 0 || row == numRows - 1) going_down = !going_down;
                row += going_down ? 1 : -1;
            }

            string rt;
            for (const string &line:lines) rt += line;
            return rt;
        }
    };
}

TEST(L0006_ZIGZAG_CONVERSION, CASE_TEST) {
    using namespace L0006;
    Solution s;

    EXPECT_EQ(s.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
    EXPECT_EQ(s.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
    EXPECT_EQ(s.convert("PAYPALISHIRING", 1), "PAYPALISHIRING");
    EXPECT_EQ(s.convert("ABABAB", 1), "ABABAB");
    EXPECT_EQ(s.convert("ABABAB", 2), "AAABBB");

}

#endif //LEET_CODE_0006_ZIGZAG_CONVERSION_H_

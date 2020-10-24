/*
 * 
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 * 
 * For example:
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *     ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28
 *     ...
 * 
 * Example 1:
 * Input: "A"
 * Output: 1
 * 
 * Example 2:
 * Input: "AB"
 * Output: 28
 * 
 * Example 3:
 * Input: "ZY"
 * Output: 701
 * 
 * 
 * Constraints:
 * 1 <= s.length <= 7
 * s consists only of uppercase English letters.
 * s is between "A" and "FXSHRXW".
 * 
 */

#ifndef LEET_CODE_0171_EXCELSHEETCOLUMNNUMBER_H_
#define LEET_CODE_0171_EXCELSHEETCOLUMNNUMBER_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0171 {
    class Solution {
    public:
        int titleToNumber(string s) {
            int final = 0, value = 0;
            for (char c:s) {
                value = (int) (c - 'A') + 1;
                final = final * 26 + value;
            }

            return final;
        }
    };
}

TEST(L0171_ExcelSheetColumnNumber, CASE_TEST) {
    using namespace L0171;
    Solution s;

    EXPECT_EQ(s.titleToNumber("A"), 1);
    EXPECT_EQ(s.titleToNumber("AB"), 28);
    EXPECT_EQ(s.titleToNumber("ZY"), 701);
}

#endif //LEET_CODE_0171_EXCELSHEETCOLUMNNUMBER_H_

/*
 * 
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 * For example:
 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB
 *     ...
 * 
 * Example 1:
 * Input: 1
 * Output: "A"
 * 
 * Example 2:
 * Input: 28
 * Output: "AB"
 * 
 * Example 3:
 * Input: 701
 * Output: "ZY"
 * 
 */

#ifndef LEET_CODE_0168_EXCELSHEETCOLUMNTITLE_H_
#define LEET_CODE_0168_EXCELSHEETCOLUMNTITLE_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0168 {
    class Solution {
    public:
        string convertToTitle(int n) {
            string res;
            int rem = 0;

            while (n > 0) {
                rem = (n - 1) % 26;
                res += (char)('A' + rem);
                n = (n - 1) / 26;
            }
            return string(res.rbegin(), res.rend());
        }
    };
}

TEST(L0168_ExcelSheetColumnTitle, CASE_TEST) {
    using namespace L0168;
    Solution s;

//    EXPECT_EQ(s.convertToTitle(1), "A");
//    EXPECT_EQ(s.convertToTitle(28), "AB");
    EXPECT_EQ(s.convertToTitle(701), "ZY");
}

#endif //LEET_CODE_0168_EXCELSHEETCOLUMNTITLE_H_

/*
 * 
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly above it.
 * 
 * Example:
 * 
 * Input: 5
 * Output:
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 * 
 */

#ifndef LEET_CODE_0118_PASCALSTRIANGLE_H_
#define LEET_CODE_0118_PASCALSTRIANGLE_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0118 {
    class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            if (numRows < 1) return {};

            vector<vector<int>> result = {{1}};
            for (int curRowNum = 2; curRowNum <= numRows; curRowNum++) {
                vector<int> curRow(curRowNum, 1);
                vector<int> &lstRow = result.back();
                for (int curColNum = 1; curColNum < curRowNum - 1; curColNum++) {
                    curRow[curColNum] = lstRow[curColNum - 1] + lstRow[curColNum];
                }
                result.push_back(curRow);
            }
            return result;
        }

    };
}

TEST(L0118_PascalsTriangle, CASE_TEST) {
    using namespace L0118;
    Solution s;

    vector<vector<int>> out1 = {{1},
                                {1, 1},
                                {1, 2, 1},
                                {1, 3, 3, 1},
                                {1, 4, 6, 4, 1}};
    EXPECT_EQ(out1, s.generate(5));
}

#endif //LEET_CODE_0118_PASCALSTRIANGLE_H_

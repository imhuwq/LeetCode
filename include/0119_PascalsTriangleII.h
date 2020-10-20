/*
 * 
 * Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.
 * 
 * Notice that the row index starts from 0.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly above it.
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: rowIndex = 3
 * Output: [1,3,3,1]
 * Example 2:
 * 
 * Input: rowIndex = 0
 * Output: [1]
 * Example 3:
 * 
 * Input: rowIndex = 1
 * Output: [1,1]
 * 
 * 
 * Constraints:
 * 
 * 0 <= rowIndex <= 40
 * 
 */

#ifndef LEET_CODE_0119_PASCALSTRIANGLEII_H_
#define LEET_CODE_0119_PASCALSTRIANGLEII_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0119 {
    class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            if (rowIndex < 0) return {};
            else if (rowIndex == 0) return {1};
            vector<int> result(1, 1);

            for (int row = 1; row <= rowIndex; row++) {
                result.resize(row + 1);
                result[row] = 1;
                int last = 1, tmp;

                for (int col = 1; col < row; col++) {
                    tmp = result[col];
                    result[col] += last;
                    last = tmp;
                }
            }
            return result;
        }
    };
}

TEST(L0119_PascalsTriangleII, CASE_TEST) {
    using namespace L0119;
    Solution s;
    EXPECT_EQ(s.getRow(0), vector<int>({1}));
    EXPECT_EQ(s.getRow(1), vector<int>({1, 1}));
    EXPECT_EQ(s.getRow(2), vector<int>({1, 2, 1}));
    EXPECT_EQ(s.getRow(3), vector<int>({1, 3, 3, 1}));
    EXPECT_EQ(s.getRow(4), vector<int>({1, 4, 6, 4, 1}));

}

#endif //LEET_CODE_0119_PASCALSTRIANGLEII_H_

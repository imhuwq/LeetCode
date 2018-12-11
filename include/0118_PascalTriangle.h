/*
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 * 
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

#ifndef LEET_CODE_0118_PASCAL_TRIANGLE_H_
#define LEET_CODE_0118_PASCAL_TRIANGLE_H_

#include <stack>
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
            if (numRows == 0) return {};
            vector<vector<int>> result(numRows);
            result[0] = {1};
            for (size_t i = 1; i < numRows; i++) {
                result[i] = {1};
                for (size_t j = 1; j < i; j++) {
                    result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
                }
                result[i].push_back(1);
            }
            return move(result);
        }
    };

}

TEST(L0118_PASCAL_TRIANGLE, CASE_TEST) {
    using namespace L0118;
    Solution s;

    vector<vector<int>> result = {{1},
                                  {1, 1},
                                  {1, 2, 1},
                                  {1, 3, 3, 1},
                                  {1, 4, 6, 4, 1},
    };
    EXPECT_EQ(s.generate(5), result);
}

#endif //LEET_CODE_0118_PASCAL_TRIANGLE_H_

/*
 * 
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * Example:
 * Consider the following matrix:
 * 
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * 
 * Given target = 5, return true.
 * Given target = 20, return false.
 * 
 */

#ifndef LEET_CODE_0240_SEARCH_A_2D_MATRIX_II_H_
#define LEET_CODE_0240_SEARCH_A_2D_MATRIX_II_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0240 {
    class Solution {
    public:
        bool searchMatrix(vector<vector<int>> &matrix, int target) {
            int rowNum = matrix.size();
            if (rowNum == 0) return false;
            int colNum = matrix[0].size();
            if (colNum == 0) return false;

            int rowIndex = 0;
            int colIndex = colNum - 1;

            while (true) {
                while (target > matrix[rowIndex][colIndex]) {
                    if (++rowIndex == rowNum) return false;
                }

                while (target < matrix[rowIndex][colIndex]) {
                    if (--colIndex == -1) return false;
                }

                if (matrix[rowIndex][colIndex] == target) return true;
            }

            return false;
        }
    };

}

TEST(L0240_SEARCH_A_2D_MATRIX_II, CASE_TEST) {
    using namespace L0240;
    Solution s;

    vector<vector<int>> matrix = {{1,  4,  7,  11, 15},
                                  {2,  5,  8,  12, 19},
                                  {3,  6,  9,  16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};

    EXPECT_EQ(s.searchMatrix(matrix, 5), true);
    EXPECT_EQ(s.searchMatrix(matrix, 20), false);
}

#endif //LEET_CODE_0240_SEARCH_A_2D_MATRIX_II_H_

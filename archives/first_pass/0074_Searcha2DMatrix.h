/*
 * 
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * 
 * Example 1:
 * Input:
 * matrix = [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * Example 2:
 * Input:
 * matrix = [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */

#ifndef LEET_CODE_0074_SEARCHA2DMATRIX_H_
#define LEET_CODE_0074_SEARCHA2DMATRIX_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0074 {
    class Solution {
    public:
        bool searchRow(vector<int> &row, int lo, int hi, int target) {
            int mid;
            while (lo < hi) {
                mid = (lo + hi) / 2;
                if (row[mid] > target) hi = mid - 1;
                else if (row[mid] < target) lo = mid + 1;
                else return true;
            }
            if (lo == hi) return row[lo] == target;
            return false;
        }

        bool searchMatrix(vector<vector<int>> &matrix, int target) {
            int row_num = matrix.size();
            if (row_num == 0) return false;
            int col_num = matrix[0].size();
            if (col_num == 0) return false;

            vector<int> &current_row = matrix[0];
            for (int row_idx = 0; row_idx < row_num; row_idx++) {
                current_row = matrix[row_idx];
                if (current_row[0] > target) return false;
                if (current_row[col_num - 1] < target) continue;
                return searchRow(current_row, 0, col_num - 1, target);
            }
            return false;
        }
    };

}

TEST(L0074_Searcha2DMatrix, CASE_TEST) {
    using namespace L0074;
    Solution s;

    vector<vector<int>> matrix = {{1,  3,  5,  7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 50}};
    EXPECT_TRUE(s.searchMatrix(matrix, 3));
    EXPECT_FALSE(s.searchMatrix(matrix, 13));
}

#endif //LEET_CODE_0074_SEARCHA2DMATRIX_H_

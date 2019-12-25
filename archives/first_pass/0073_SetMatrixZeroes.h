/*
 * 
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 * 
 * Example 1:
 * Input:
 * [
 *   [1,1,1],
 *   [1,0,1],
 *   [1,1,1]
 * ]
 * Output:
 * [
 *   [1,0,1],
 *   [0,0,0],
 *   [1,0,1]
 * ]
 * 
 * Example 2:
 * Input:
 * [
 *   [0,1,2,0],
 *   [3,4,5,2],
 *   [1,3,1,5]
 * ]
 * Output:
 * [
 *   [0,0,0,0],
 *   [0,4,5,0],
 *   [0,3,1,0]
 * ]
 * 
 * Follow up:
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 * 
 */

#ifndef LEET_CODE_0073_SETMATRIXZEROES_H_
#define LEET_CODE_0073_SETMATRIXZEROES_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0073 {
    class Solution {
    public:
        void setZeroes(vector<vector<int>> &matrix) {
            int row_num = matrix.size();
            if (row_num == 0) return;
            int col_num = matrix[0].size();
            if (col_num == 0) return;

            bool first_row_zero = false;
            bool first_col_zero = false;
            for (int i = 0; i < col_num; i++) {
                if (matrix[0][i] == 0) {
                    first_row_zero = true;
                    break;
                }
            }
            for (int i = 0; i < row_num; i++) {
                if (matrix[i][0] == 0) {
                    first_col_zero = true;
                    break;
                }
            }

            for (int row_idx = 1; row_idx < row_num; row_idx++) {
                for (int col_idx = 1; col_idx < col_num; col_idx++) {
                    if (matrix[row_idx][col_idx] == 0) {
                        matrix[row_idx][0] = 0;
                        matrix[0][col_idx] = 0;
                    }
                }
            }

            for (int col_idx = 1; col_idx < col_num; col_idx++) {
                if (matrix[0][col_idx] == 0) {
                    for (int row_idx = 1; row_idx < row_num; row_idx++) {
                        matrix[row_idx][col_idx] = 0;
                    }
                }
            }

            for (int row_idx = 1; row_idx < row_num; row_idx++) {
                if (matrix[row_idx][0] == 0) {
                    for (int col_idx = 1; col_idx < col_num; col_idx++) {
                        matrix[row_idx][col_idx] = 0;
                    }
                }
            }

            if (first_row_zero) {
                for (int i = 0; i < col_num; i++) matrix[0][i] = 0;
            }

            if (first_col_zero) {
                for (int i = 0; i < row_num; i++) matrix[i][0] = 0;
            }
        }
    };
}

TEST(L0073_SetMatrixZeroes, CASE_TEST) {
    using namespace L0073;
    Solution s;

    vector<vector<int>> matrix = {{0, 1, 2, 0},
                                  {3, 4, 5, 2},
                                  {1, 3, 1, 5}};

    vector<vector<int>> result = {{0, 0, 0, 0},
                                  {0, 4, 5, 0},
                                  {0, 3, 1, 0}};
    s.setZeroes(matrix);
    EXPECT_EQ(matrix, result);
}

#endif //LEET_CODE_0073_SETMATRIXZEROES_H_

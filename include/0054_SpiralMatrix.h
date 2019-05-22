/*
 * 
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 * 
 * Example 1:
 * Input:
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * Example 2:
 * Input:
 * [
 *   [1, 2, 3, 4],
 *   [5, 6, 7, 8],
 *   [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */

#ifndef LEET_CODE_0054_SPIRALMATRIX_H_
#define LEET_CODE_0054_SPIRALMATRIX_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0054 {
    class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>> &matrix) {
            int row = matrix.size();
            if (row == 0) return {};
            int col = matrix[0].size();
            if (col == 0) return {};

            int row_beg = 0, row_end = row - 1;
            int col_beg = 0, col_end = col - 1;
            vector<int> result;
            result.reserve(col * row);
            while (row_beg <= row_end && col_beg <= col_end) {
                for (int i = col_beg; i <= col_end; i++) result.push_back(matrix[row_beg][i]);
                row_beg++;
                if (row_beg > row_end) break;

                for (int i = row_beg; i <= row_end; i++) result.push_back(matrix[i][col_end]);
                col_end--;
                if (col_beg > col_end) break;

                for (int i = col_end; i >= col_beg; i--) result.push_back(matrix[row_end][i]);
                row_end--;
                if (row_beg > row_end) break;

                for (int i = row_end; i >= row_beg; i--) result.push_back(matrix[i][col_beg]);
                col_beg++;
                if (col_beg > col_end) break;
            }

            return result;
        }
    };

}

TEST(L0054_SpiralMatrix, CASE_TEST) {
    using namespace L0054;
    Solution s;

    vector<vector<int>> mat1 = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};
    vector<int> ans1 = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    EXPECT_EQ(s.spiralOrder(mat1), ans1);
}

#endif //LEET_CODE_0054_SPIRALMATRIX_H_

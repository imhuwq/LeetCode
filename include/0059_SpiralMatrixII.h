/*
 * 
 * Given a positive integer n, generate a square matrix filled with elements from 1 to n**2 in spiral order.
 * 
 * Example:
 * 
 * Input: 3
 * Output:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 * 
 */

#ifndef LEET_CODE_0059_SPIRALMATRIXII_H_
#define LEET_CODE_0059_SPIRALMATRIXII_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0059 {
    class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            if (n == 0) return {};
            vector<vector<int>> result(n, vector<int>(n, 0));

            int row_beg = 0, row_end = n - 1;
            int col_beg = 0, col_end = n - 1;
            int value = 1;
            while (true) {
                for (int col_idx = col_beg; col_idx <= col_end; col_idx++) result[row_beg][col_idx] = value++;
                row_beg++;
                if (row_beg > row_end) break;

                for (int row_idx = row_beg; row_idx <= row_end; row_idx++) result[row_idx][col_end] = value++;
                col_end--;
                if (col_beg > col_end) break;

                for (int col_idx = col_end; col_idx >= col_beg; col_idx--) result[row_end][col_idx] = value++;
                row_end--;
                if (row_beg > row_end) break;

                for (int row_idx = row_end; row_idx >= row_beg; row_idx--) result[row_idx][col_beg] = value++;
                col_beg++;
                if (col_beg > col_end) break;
            }

            return result;
        }
    };

}

TEST(L0059_SpiralMatrixII, CASE_TEST) {
    using namespace L0059;
    Solution s;

    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0059_SPIRALMATRIXII_H_

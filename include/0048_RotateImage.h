/*
 * 
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * 
 * Note:
 * You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
 * 
 * Example 1:
 * Given input matrix =
 * [
 *   [1,2,3],
 *   [4,5,6],
 *   [7,8,9]
 * ],
 * rotate the input matrix in-place such that it becomes:
 * [
 *   [7,4,1],
 *   [8,5,2],
 *   [9,6,3]
 * ]
 * 
 * Example 2:
 * Given input matrix =
 * [
 *   [ 5, 1, 9,11],
 *   [ 2, 4, 8,10],
 *   [13, 3, 6, 7],
 *   [15,14,12,16]
 * ],
 * rotate the input matrix in-place such that it becomes:
 * [
 *   [15,13, 2, 5],
 *   [14, 3, 4, 1],
 *   [12, 6, 8, 9],
 *   [16, 7,10,11]
 * ]
 * 
 */

#ifndef LEET_CODE_0048_ROTATE_IMAGE_H_
#define LEET_CODE_0048_ROTATE_IMAGE_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0048 {
    class Solution {
    public:
        int max_row;
        int max_col;

        pair<int, int> replace(vector<vector<int>> &matrix, const pair<int, int> &pos) {
            int row = max_row - 1 - pos.second, col = pos.first;
            matrix[pos.first][pos.second] = matrix[row][col];
            return {row, col};
        }

        pair<int, int> new_place(const pair<int, int> &pos) {
            return {pos.second, max_col - 1 - pos.first};
        }

        void insert(vector<vector<int>> &matrix, const pair<int, int> &pos, int val) {
            matrix[pos.first][pos.second] = val;
        }

        void rotate(vector<vector<int>> &matrix) {
            max_row = matrix.size();
            if (max_row == 0) return;
            max_col = matrix[0].size();
            if (max_col == 0) return;

            int row_beg = 0;
            int row_end = max_row - 1;
            int col_beg = 0;
            int col_end = max_col - 1;
            int swap;
            pair<int, int> current, from, to;
            for (current.first = row_beg; current.first < row_end; current.first++) {
                for (current.second = col_beg; current.second < col_end; current.second++) {
                    swap = matrix[current.first][current.second];
                    from = replace(matrix, current);
                    to = new_place(current);
                    while (from != to) {
                        from = replace(matrix, from);
                    }
                    insert(matrix, to, swap);
                }
                row_beg++;
                row_end--;
                col_beg++;
                col_end--;
            }
        }
    };
}

TEST(L0048_ROTATE_IMAGE, CASE_TEST) {
    using namespace L0048;
    Solution s;
    vector<vector<int>> matrix = {
            {5,  1,  9,  11},
            {2,  4,  8,  10},
            {13, 3,  6,  7},
            {15, 14, 12, 16}
    };
    s.rotate(matrix);

    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0048_ROTATE_IMAGE_H_

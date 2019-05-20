/*
 * 
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 * 
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 * 
 * Example 1:
 * Input:
 * [
 *   ["5","3",".",".","7",".",".",".","."],
 *   ["6",".",".","1","9","5",".",".","."],
 *   [".","9","8",".",".",".",".","6","."],
 *   ["8",".",".",".","6",".",".",".","3"],
 *   ["4",".",".","8",".","3",".",".","1"],
 *   ["7",".",".",".","2",".",".",".","6"],
 *   [".","6",".",".",".",".","2","8","."],
 *   [".",".",".","4","1","9",".",".","5"],
 *   [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: true
 * 
 * 
 * Example 2:
 * Input:
 * [
 *   ["8","3",".",".","7",".",".",".","."],
 *   ["6",".",".","1","9","5",".",".","."],
 *   [".","9","8",".",".",".",".","6","."],
 *   ["8",".",".",".","6",".",".",".","3"],
 *   ["4",".",".","8",".","3",".",".","1"],
 *   ["7",".",".",".","2",".",".",".","6"],
 *   [".","6",".",".",".",".","2","8","."],
 *   [".",".",".","4","1","9",".",".","5"],
 *   [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner being
 *     modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 * 
 * Note:
 * A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 * Only the filled cells need to be validated according to the mentioned rules.
 * The given board contain only digits 1-9 and the character '.'.
 * The given board size is always 9x9.
 * 
 */

#ifndef LEET_CODE_0036_VALID_SUDOKU_H_
#define LEET_CODE_0036_VALID_SUDOKU_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <stdlib.h>
#include <gtest/gtest.h>

using namespace std;

namespace L0036 {
    class Solution {
    public:
        bool isValidSudoku(vector<vector<char>> &board) {
            uint8_t row_counter[9][9] = {0};
            uint8_t col_counter[9][9] = {0};
            uint8_t box_counter[9][9] = {0};

            uint8_t num;
            auto nan = uint8_t('.' - '0');
            size_t box_idx = 0;
            for (size_t row_idx = 0; row_idx < 9; row_idx++) {
                vector<char> &row = board[row_idx];
                for (size_t col_idx = 0; col_idx < 9; col_idx++) {
                    num = uint8_t(row[col_idx] - (uint8_t) '0');
                    if (num == nan) continue;
                    box_idx = (row_idx / 3) * 3 + col_idx / 3;
                    if (++row_counter[row_idx][num - 1] != 1) return false;
                    if (++col_counter[col_idx][num - 1] != 1) return false;
                    if (++box_counter[box_idx][num - 1] != 1) return false;
                }
            }

            return true;
        }
    };

}

TEST(L0036_VALID_SUDOKU, CASE_TEST) {
    using namespace L0036;
    Solution s;

    vector<vector<char>> board1 = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                   {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                   {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                   {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                   {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                   {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                   {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                   {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                   {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char>> board2 = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                                   {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                   {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                   {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                   {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                   {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                   {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                   {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                   {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    EXPECT_EQ(s.isValidSudoku(board1), true);
    EXPECT_EQ(s.isValidSudoku(board2), false);
}

#endif //LEET_CODE_0036_VALID_SUDOKU_H_

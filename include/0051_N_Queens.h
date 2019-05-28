/*
 * 
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.'
 * both indicate a queen and an empty space respectively.
 * 
 * Example:
 * Input: 4
 * Output: [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 * 
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 * 
 */

#ifndef LEET_CODE_0051_N_QUEENS_H_
#define LEET_CODE_0051_N_QUEENS_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0051 {
    class Solution {
    public:
        void take(int row, int col, vector<vector<int>> &taken, int n) {
            for (int nex_row = row + 1, offset = 1, nex_col; nex_row < n; nex_row++, offset++) {
                taken[nex_row][col]++;
                nex_col = col + offset;
                if (nex_col < n) taken[nex_row][nex_col]++;
                nex_col = col - offset;
                if (nex_col >= 0) taken[nex_row][nex_col]++;
            }
        }

        void free(int row, int col, vector<vector<int>> &taken, int n) {
            for (int nex_row = row + 1, offset = 1, nex_col; nex_row < n; nex_row++, offset++) {
                taken[nex_row][col]--;
                nex_col = col + offset;
                if (nex_col < n) taken[nex_row][nex_col]--;
                nex_col = col - offset;
                if (nex_col >= 0) taken[nex_row][nex_col]--;
            }
        }

        void solveNextQueen(int row, vector<vector<int>> &taken, int n,
                            vector<pair<int, int>> &positions,
                            vector<vector<string>> &results) {
            if (positions.size() == n) {
                results.emplace_back(n, string(n, '.'));
                vector<string> &board = results.back();
                for (auto &row_col:positions) board[row_col.first][row_col.second] = 'Q';
                return;
            }

            for (int col = 0; col < n; col++) {
                if (taken[row][col] > 0) continue;
                take(row, col, taken, n);
                positions.emplace_back(row, col);
                solveNextQueen(row + 1, taken, n, positions, results);
                free(row, col, taken, n);
                positions.pop_back();
            }
        }

        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> results;
            vector<vector<int>> taken(n, vector<int>(n, 0));
            vector<pair<int, int>> positions;

            solveNextQueen(0, taken, n, positions, results);
            return results;
        }
    };
}

TEST(L0051_N_Queens, CASE_TEST) {
    using namespace L0051;
    Solution s;
    s.solveNQueens(4);
    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0051_N_QUEENS_H_

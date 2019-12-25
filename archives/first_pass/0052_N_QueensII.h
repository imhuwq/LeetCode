/*
 * 
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens puzzle.
 * 
 * Example:
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
 * [
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

#ifndef LEET_CODE_0052_N_QUEENSII_H_
#define LEET_CODE_0052_N_QUEENSII_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0052 {
    class Solution {
    public:
        int num_solutions;
        int num_queens;

        void take(int row, int col, vector<vector<int>> &taken, int n) {
            for (int nex_row = row + 1, offset = 1, nex_col = col; nex_row < n; nex_row++, offset++, nex_col = col) {
                taken[nex_row][nex_col]++;
                nex_col = col + offset;
                if (nex_col < n) taken[nex_row][nex_col]++;
                nex_col = col - offset;
                if (nex_col >= 0) taken[nex_row][nex_col]++;
            }
        }

        void free(int row, int col, vector<vector<int>> &taken, int n) {
            for (int nex_row = row + 1, offset = 1, nex_col = col; nex_row < n; nex_row++, offset++, nex_col = col) {
                taken[nex_row][nex_col]--;
                nex_col = col + offset;
                if (nex_col < n) taken[nex_row][nex_col]--;
                nex_col = col - offset;
                if (nex_col >= 0) taken[nex_row][nex_col]--;
            }
        }

        void solveNextLine(int row, int num_queens, vector<vector<int>> &taken, int n) {
            if (num_queens == n) {
                num_solutions++;
                return;
            }

            for (int col = 0; col < n; col++) {
                if (taken[row][col]) continue;
                take(row, col, taken, n);
                solveNextLine(row + 1, num_queens + 1, taken, n);
                free(row, col, taken, n);
            }
        }

        int totalNQueens(int n) {
            num_queens = 0;
            num_solutions = 0;
            vector<vector<int>> taken(n, vector<int>(n, 0));
            solveNextLine(0, num_queens, taken, n);
            return num_solutions;
        }
    };

}

TEST(L0052_N_QueensII, CASE_TEST) {
    using namespace L0052;
    Solution s;

    EXPECT_EQ(s.totalNQueens(4), 2);
}

#endif //LEET_CODE_0052_N_QUEENSII_H_

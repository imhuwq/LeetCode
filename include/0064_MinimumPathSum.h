/*
 * 
 * Given a m x n grid filled with non-negative numbers,
 * find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * Input:
 * [
 *   [1,3,1],
 *   [1,5,1],
 *   [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 */

#ifndef LEET_CODE_0064_MINIMUMPATHSUM_H_
#define LEET_CODE_0064_MINIMUMPATHSUM_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0064 {
    class Solution {
    public:
        int minPathSum(vector<vector<int>> &grid) {
            int row_num = grid.size();
            if (row_num == 0) return 0;
            int col_num = grid[0].size();
            if (col_num == 0) return 0;

            vector<size_t> counter(col_num, 0);
            vector<int> &current_row = grid[0];
            counter[0] = current_row[0];
            for (int i = 1; i < col_num; i++) counter[i] = counter[i - 1] + current_row[i];

            for (int row_idx = 1; row_idx < row_num; row_idx++) {
                current_row = grid[row_idx];
                counter[0] = counter[0] + current_row[0];

                for (int col_idx = 1; col_idx < col_num; col_idx++) {
                    int sum_from_left = counter[col_idx - 1] + current_row[col_idx];
                    int sum_from_top = counter[col_idx] + current_row[col_idx];
                    counter[col_idx] = min(sum_from_left, sum_from_top);
                }
            }

            return counter.back();
        }
    };
}

TEST(L0064_MinimumPathSum, CASE_TEST) {
    using namespace L0064;
    Solution s;

    vector<vector<int>> map = {{1, 3, 1},
                               {1, 5, 1},
                               {4, 2, 1}};
    EXPECT_EQ(s.minPathSum(map), 7);
}

#endif //LEET_CODE_0064_MINIMUMPATHSUM_H_

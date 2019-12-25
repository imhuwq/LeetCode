/*
 * 
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * 
 * How many possible unique paths are there?
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * 
 * Example 2:
 * Input: m = 7, n = 3
 * Output: 28
 * 
 */

#ifndef LEET_CODE_0062_UNIQUEPATHS_H_
#define LEET_CODE_0062_UNIQUEPATHS_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0062 {
    class Solution {
    public:

        int uniquePaths(int m, int n) {
            if (m == 0 || n == 0) return 0;
            if (m == 1 || n == 1) return 1;

            vector<int> counter(n, 1);
            counter[0] = 1;
            for (int row = 1; row < m; row++) {
                for (int col = 1; col < n; col++) {
                    counter[col] = counter[col - 1] + counter[col];
                }
            }

            return counter[n - 1];
        }
    };

}

TEST(L0062_UniquePaths, CASE_TEST) {
    using namespace L0062;
    Solution s;

    EXPECT_EQ(s.uniquePaths(2, 0), 0);
    EXPECT_EQ(s.uniquePaths(0, 5), 0);
    EXPECT_EQ(s.uniquePaths(1, 5), 1);
    EXPECT_EQ(s.uniquePaths(1, 1), 1);
    EXPECT_EQ(s.uniquePaths(2, 2), 2);
    EXPECT_EQ(s.uniquePaths(3, 2), 3);
    EXPECT_EQ(s.uniquePaths(7, 3), 28);
}

#endif //LEET_CODE_0062_UNIQUEPATHS_H_

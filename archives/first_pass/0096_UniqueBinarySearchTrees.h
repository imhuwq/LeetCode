/*
 * 
 * Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
 * 
 * Example:
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 * 
 */

#ifndef LEET_CODE_0096_UNIQUEBINARYSEARCHTREES_H_
#define LEET_CODE_0096_UNIQUEBINARYSEARCHTREES_H_

#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0096 {
    class Solution {
    public:
        int numTrees(int n) {
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            for (int i = 1; i <= n; i++) {
                int num = 0;
                for (int j = 1; j <= i; j++) {
                    num += dp[j - 1] * dp[i - j];
                }
                dp[i] = num;
            }

            return dp[n];
        }
    };
}

TEST(L0096_UniqueBinarySearchTrees, CASE_TEST) {
    using namespace L0096;
    Solution s;
    EXPECT_EQ(s.numTrees(1), 1);
    EXPECT_EQ(s.numTrees(2), 2);
    EXPECT_EQ(s.numTrees(3), 5);
}

#endif //LEET_CODE_0096_UNIQUEBINARYSEARCHTREES_H_

/*
 * 
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * 
 * Example:
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 * 
 */

#ifndef LEET_CODE_0077_COMBINATIONS_H_
#define LEET_CODE_0077_COMBINATIONS_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0077 {
    class Solution {
    public:
        long long fract(int n) {
            if (n == 0) return 1;
            long long result = n;
            while (n > 1) result *= (--n);
            return result;
        }

        int C(int count, int total) {
            return fract(total) / (fract(total - count) * fract(count));
        }

        void combine(int n, int k, int pos, int start_symbol, int offset, vector<vector<int>> &combinations) {
            if (pos == k) return;

            int left_k = k - (pos + 1);
            int left_n = n - start_symbol;
            for (int symbol = start_symbol; symbol <= n; symbol++) {
                int count = C(left_k, left_n--);
                for (int i = 0; i < count; i++) combinations[offset + i][pos] = symbol;
                combine(n, k, pos + 1, symbol + 1, offset, combinations);
                offset += count;
            }
        }

        vector<vector<int>> combine(int n, int k) {
            int count = C(k, n);
            vector<vector<int>> combinations(count, vector<int>(k, 0));
            combine(n, k, 0, 1, 0, combinations);
            return combinations;
        }
    };
}

TEST(L0077_Combinations, CASE_TEST) {
    using namespace L0077;
    Solution s;
    s.combine(4, 2);
    s.combine(3, 3);
    s.combine(4, 3);
    s.combine(1, 1);
    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0077_COMBINATIONS_H_

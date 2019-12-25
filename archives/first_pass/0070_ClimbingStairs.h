/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * Example 2:
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 */

#ifndef LEET_CODE_0070_CLIMBING_STAIRS_H_
#define LEET_CODE_0070_CLIMBING_STAIRS_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0070 {

    class Solution {
    public:
        int climbStairs(int n) {
            if (n == 0) return 0;
            if (n == 1) return 1;

            int result = 0;
            int n_2 = 1, n_1 = 1;
            for (int i = 2; i <= n; i++) {
                result = n_1 + n_2;
                n_2 = n_1;
                n_1 = result;
            }
            return result;
        }
    };

}

TEST(L0070_CLIMBING_STAIRS, CASE_TEST) {
    L0070::Solution s;

    EXPECT_EQ(s.climbStairs(1), 1);
    EXPECT_EQ(s.climbStairs(2), 2);
    EXPECT_EQ(s.climbStairs(3), 3);
}

#endif //LEET_CODE_0070_CLIMBING_STAIRS_H_

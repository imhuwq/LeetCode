/*
 * 
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
 * 
 */

#ifndef LEET_CODE_0070_CLIMBINGSTAIRS_H_
#define LEET_CODE_0070_CLIMBINGSTAIRS_H_

#include <map>
#include <stack>
#include <queue>
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
            if (n == 0) return 1;
            else if (n == 1) return 1;
            return climbStairs(n - 1) + climbStairs(n - 2);
        }
    };
}

TEST(L0070_ClimbingStairs, CASE_TEST) {
    using namespace L0070;
    Solution s;

    EXPECT_EQ(s.climbStairs(1), 1);
    EXPECT_EQ(s.climbStairs(2), 2);
    EXPECT_EQ(s.climbStairs(3), 3);
    EXPECT_EQ(s.climbStairs(4), 5);
    EXPECT_EQ(s.climbStairs(5), 8);
    EXPECT_EQ(s.climbStairs(6), 13);

}

#endif //LEET_CODE_0070_CLIMBINGSTAIRS_H_

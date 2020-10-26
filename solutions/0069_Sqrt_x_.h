/*
 * 
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
 * 
 * Example 1:
 * Input: 4
 * Output: 2
 * 
 * Example 2:
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since
 *              the decimal part is truncated, 2 is returned.
 * 
 * 
 */

#ifndef LEET_CODE_0069_SQRT_X__H_
#define LEET_CODE_0069_SQRT_X__H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0069 {
    class Solution {
    public:
        int mySqrt(int x) {
            if (x == 0) return 0;

            int left = 1, right = x, result = 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (mid <= x / mid) {
                    result = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            return result;

        }
    };
}

TEST(L0069_Sqrt_x_, CASE_TEST) {
    using namespace L0069;
    Solution s;

    EXPECT_EQ(s.mySqrt(2147483647), 3);
    EXPECT_EQ(s.mySqrt(0), 0);
    EXPECT_EQ(s.mySqrt(1), 1);
    EXPECT_EQ(s.mySqrt(2), 1);
    EXPECT_EQ(s.mySqrt(4), 2);
    EXPECT_EQ(s.mySqrt(8), 2);
    EXPECT_EQ(s.mySqrt(9), 3);
}

#endif //LEET_CODE_0069_SQRT_X__H_

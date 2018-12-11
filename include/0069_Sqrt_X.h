/*
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
 */

#ifndef LEET_CODE_0069_SQRT_X_H_
#define LEET_CODE_0069_SQRT_X_H_

#include <stack>
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
            if (x == 1) return 1;

            int beg = 1;
            int end = x;
            int mid;

            int val;
            while (true) {
                mid = (beg + end) / 2;
                val = mid * mid;
                if (val > x) end = mid - 1;
                else if (val < x) beg = mid + 1;
                else return mid;
                if (mid == beg) return beg -1;
            }
        }
    };

}

TEST(L0069_SQRT_X_, CASE_TEST) {
    L0069::Solution s;

    EXPECT_EQ(s.mySqrt(4), 2);
    EXPECT_EQ(s.mySqrt(8), 2);
    EXPECT_EQ(s.mySqrt(2), 1);
}

#endif //LEET_CODE_0069_SQRT_X_H_(X)_H_

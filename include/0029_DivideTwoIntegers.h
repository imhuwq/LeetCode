/*
 * 
 * Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
 * Return the quotient after dividing dividend by divisor.
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2**31,  2**31 − 1].
 * For the purpose of this problem, assume that your function returns 2**31 − 1 when the division result overflows.
 * 
 */

#ifndef LEET_CODE_0029_DIVIDE_TWO_INTEGERS_H_
#define LEET_CODE_0029_DIVIDE_TWO_INTEGERS_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0029 {
    class Solution {
    public:
        int divide(int dividend, int divisor) {
            if (dividend == 0) return 0;

            if (divisor == 0) return INT_MAX;

            if (divisor == 1) {
                if (dividend == INT_MIN) return INT_MIN;
                return dividend;
            }

            if (divisor == -1) {
                if (dividend == INT_MIN) return INT_MAX;
                return -dividend;
            }

            if (divisor == INT_MAX) {
                if (dividend == INT_MAX) return 1;
                if (dividend == INT_MIN) return -1;
                return 0;
            }

            if (divisor == INT_MIN) {
                if (dividend == INT_MIN) return 1;
                return 0;
            }

            int mask = 1 << 31;
            bool is_neg = (bool) ((dividend & mask) >> 31 ^ (divisor & mask) >> 31);

            bool reduced_1 = false;
            if (dividend == INT_MIN) {
                dividend = INT_MAX;
                reduced_1 = true;
            } else if (dividend < 0) {
                dividend = -dividend;
            }
            if (divisor < 0) divisor = -divisor;

            int result = 0;
            while (dividend >= divisor) {
                int count = 1;
                int tmp = divisor;
                bool calculated = false;
                while (dividend >= tmp && tmp << 1 > 0) {
                    calculated = true;
                    count = count << 1;
                    tmp = tmp << 1;
                }

                if (calculated) {
                    dividend -= (tmp >> 1);
                    result += (count >> 1);
                } else {
                    dividend -= tmp;
                    result += count;
                }


                if (reduced_1) {
                    dividend += 1;
                    reduced_1 = false;
                }

            }

            return is_neg ? -result : result;
        }
    };

}

TEST(L0029_DIVIDE_TWO_INTEGERS, CASE_TEST) {
    using namespace L0029;
    Solution s;

    EXPECT_EQ(3, s.divide(10, 3));
    EXPECT_EQ(-2, s.divide(7, -3));
    EXPECT_EQ(2147483647, s.divide(-2147483648, -1));
    EXPECT_EQ(1073741824, s.divide(-2147483648, -2));
    EXPECT_EQ(0, s.divide(-1010369383, -2147483648));
    EXPECT_EQ(-1, s.divide(1100540749, -1090366779));
}

#endif //LEET_CODE_0029_DIVIDE_TWO_INTEGERS_H_

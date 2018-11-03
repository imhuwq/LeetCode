/*
 * Given a 32 - bit signed integer, reverse digits of an integer.
 * Example :
 *  Input: 123
 *  Output : 321
 *  Example 2 :
 *
 *  Input : -123
 *  Output : -321
 *  Example 3 :
 *
 *  Input : 120
 *  Output : 21
 *
 * Note :
 * Assume we are dealing with an environment which could only store integers within the 32 - bit signed integer range : [−231, 231 − 1].
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#ifndef LEET_CODE_0007_REVERSE_INTEGER_H_
#define LEET_CODE_0007_REVERSE_INTEGER_H_

#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0007 {
    int max_val = INT_MAX / 10;
    int min_val = INT_MIN / 10;

    class Solution {
    public:
        Solution() = default;

        int reverse(int x) {
            if (-10 < x && x < 10) return x;

            int r = 0;
            int div = 0;
            int rem = 0;
            while (x != 0) {
                rem = x % 10;
                if (r > max_val || (r == max_val && rem > 7)) return 0;
                else if (r < min_val || (r == min_val && rem < -8)) return 0;
                r = r * 10 + rem;
                x = x / 10;
            }
            return r;
        }

        bool Test() {
            bool t1 = (reverse(123) == 321);
            bool t2 = (reverse(-123) == -321);
            bool t3 = (reverse(120) == 21);
            return t1 && t2 && t3;
        }
    };
}

TEST(L0007_TWO_SUM, CASE_TEST) {
    L0007::Solution s;
    EXPECT_EQ(s.reverse(123), 321);
    EXPECT_EQ(s.reverse(-123), -321);
    EXPECT_EQ(s.reverse(120), 21);
}

#endif //LEET_CODE_0007_REVERSE_INTEGER_H_

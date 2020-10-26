/*
 * 
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * Input: 123
 * Output: 321
 * 
 * Example 2:
 * Input: -123
 * Output: -321
 * 
 * Example 3:
 * Input: 120
 * Output: 21
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 * 
 */

#ifndef LEET_CODE_0007_REVERSEINTEGER_H_
#define LEET_CODE_0007_REVERSEINTEGER_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0007 {
    const int PERMIT_BASE = INT_MAX / 10;
    const int PERMIT_REMINDER = INT_MAX - PERMIT_BASE * 10;

    class Solution {
    public:
        int reverse(int input) {
            if (input == 0) return 0;
            if (input == INT_MIN) return 0;

            int output = 0;
            int reminder = 0;
            bool is_negative = input < 0;
            if (is_negative) input = -input;

            while (input) {
                reminder = input % 10;

                if (output > PERMIT_BASE) return 0;
                else if (output == PERMIT_BASE and reminder > PERMIT_REMINDER) return 0;

                output = (output * 10) + reminder;
                input = input / 10;
            }

            if (is_negative) return -output;
            return output;
        }
    };

}

TEST(L0007_ReverseInteger, CASE_TEST) {
    using namespace L0007;
    Solution s;

//    EXPECT_EQ(s.reverse(123), 321);
//    EXPECT_EQ(s.reverse(120), 21);
//    EXPECT_EQ(s.reverse(-123), -321);
    EXPECT_EQ(s.reverse(1463847412), 2147483641);
}

#endif //LEET_CODE_0007_REVERSEINTEGER_H_

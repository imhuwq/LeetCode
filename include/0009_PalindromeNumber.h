/*
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 *
 * Example 1:
 *  Input: 121
 *  Output: true
 *
 * Example 2:
 *  Input: -121
 *  Output: false
 *  Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 *
 * Example 3:
 *  Input: 10
 *  Output: false
 *  Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 *
 * Follow up:
 *  Could you solve it without converting the integer to a string?
 */

#ifndef LEET_CODE_0009_PALINDROME_NUMBER_H_
#define LEET_CODE_0009_PALINDROME_NUMBER_H_

#include <gtest/gtest.h>

namespace L0009 {
    class Solution {
    public:
        Solution() = default;

        bool isPalindrome(int x) {
            if (x < 0 || (x % 10 == 0 && x != 0)) return false;

            int z = 0;
            while (x > z) {
                z = z * 10 + x % 10;
                x /= 10;
            }

            return x == z || x == z / 10;
        }
    };
}


TEST(L0009_PALINDROME_NUMBER, CASE_TEST) {
    L0009::Solution s;
    EXPECT_TRUE(s.isPalindrome(1221));
    EXPECT_FALSE(s.isPalindrome(-1221));
    EXPECT_FALSE(s.isPalindrome(10));
    EXPECT_FALSE(s.isPalindrome(2147483647));
}

#endif //LEET_CODE_0009_PALINDROME_NUMBER_H_

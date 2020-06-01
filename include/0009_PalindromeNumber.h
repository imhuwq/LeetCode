/*
 * 
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 * 
 * Example 1:
 * Input: 121
 * Output: true
 * 
 * Example 2:
 * Input: -121
 * Output: false
 * 
 * Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 * 
 * Example 3:
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 * 
 * Follow up:
 * Coud you solve it without converting the integer to a string?
 * 
 */

#ifndef LEET_CODE_0009_PALINDROMENUMBER_H_
#define LEET_CODE_0009_PALINDROMENUMBER_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0009 {
    class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) return false;
            else if (x < 10) return true;
            else if (x % 10 == 0) return false;

            int reverted = 0;
            while (reverted < x) {
                reverted = reverted * 10 + x % 10;
                x = x / 10;
            }

            return reverted == x or reverted / 10 == x;
        }
    };
}

TEST(L0009_PalindromeNumber, CASE_TEST) {
    using namespace L0009;
    Solution s;

    EXPECT_EQ(s.isPalindrome(123), false);
    EXPECT_EQ(s.isPalindrome(121), true);
    EXPECT_EQ(s.isPalindrome(-121), false);
    EXPECT_EQ(s.isPalindrome(10), false);
    EXPECT_EQ(s.isPalindrome(1001), true);
    EXPECT_EQ(s.isPalindrome(100), false);
    EXPECT_EQ(s.isPalindrome(22), true);
    EXPECT_EQ(s.isPalindrome(1235321), true);
}

#endif //LEET_CODE_0009_PALINDROMENUMBER_H_

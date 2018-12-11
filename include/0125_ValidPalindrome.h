/*
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid palindrome.
 * 
 * Example 1:
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * Example 2:
 * Input: "race a car"
 * Output: false
 */

#ifndef LEET_CODE_0125_VALID_PALINDROME_H_
#define LEET_CODE_0125_VALID_PALINDROME_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0125 {

    class Solution {
    public:
        bool isPalindrome(string s) {
            for (int beg = 0, end = s.size() - 1; beg < end; beg++, end--) {
                while (isalnum(s[beg]) == false && beg < end) beg++;
                while (isalnum(s[end]) == false && end > beg) end--;
                if (tolower(s[beg]) != tolower(s[end])) return false;
            }
            return true;
        }
    };

}

TEST(L0125_VALID_PALINDROME, CASE_TEST) {
    using namespace L0125;
    Solution s;

    EXPECT_TRUE(s.isPalindrome("A man, a plan, a canal: Panama"));
    EXPECT_TRUE(s.isPalindrome(".,"));
    EXPECT_FALSE(s.isPalindrome("ab"));
    EXPECT_FALSE(s.isPalindrome("race a car"));
    EXPECT_FALSE(s.isPalindrome("0P"));
}

#endif //LEET_CODE_0125_VALID_PALINDROME_H_

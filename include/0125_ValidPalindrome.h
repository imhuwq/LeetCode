/*
 * 
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
 * 
 * 
 * Constraints:
 * s consists only of printable ASCII characters.
 * 
 */

#ifndef LEET_CODE_0125_VALIDPALINDROME_H_
#define LEET_CODE_0125_VALIDPALINDROME_H_

#include <map>
#include <stack>
#include <queue>
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
            char *ss = new char[s.size()];
            int ss_len = 0;
            for (uint8_t c:s) {
                if (c >= 65 && c <= 90) ss[ss_len++] = c + 32;
                else if (c >= 97 && c <= 122) ss[ss_len++] = c;
                else if (c >= 48 && c<= 57) ss[ss_len++] = c;
            }
            int l = 0, r = ss_len-1;

            while (l < r) {
                if (ss[l++] != ss[r--]) {
                    delete [] ss;
                    return false;
                }
            }
            delete[] ss;
            return true;
        }
    };
}

TEST(L0125_ValidPalindrome, CASE_TEST) {
    using namespace L0125;
    Solution s;

    EXPECT_EQ(s.isPalindrome("0P"), false);
    EXPECT_EQ(s.isPalindrome(""), true);
    EXPECT_EQ(s.isPalindrome("A man, a plan, a canal: Panama"), true);
    EXPECT_EQ(s.isPalindrome("race a car"), false);

}

#endif //LEET_CODE_0125_VALIDPALINDROME_H_

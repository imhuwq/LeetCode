/*
 * 
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * Example 2:
 * Input: "cbbd"
 * Output: "bb"
 * 
 */

#ifndef LEET_CODE_0005_LONGEST_PALINDROMIC_SUBSTRING_H_
#define LEET_CODE_0005_LONGEST_PALINDROMIC_SUBSTRING_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0005 {
    class Solution {
    public:
        string longestPalindrome(string s) {
            int len = s.size();
            if (len == 0) return "";
            if (len == 1) return s;

            int head = 0;
            int tail = 0;
            int curr = 0;

            while ((len - curr - 1) * 2 + 1 > (tail - head + 1)) {
                int h = curr;
                int t = curr;
                char c = s[curr];
                while (t < len - 1 && s[t + 1] == c) t++;
                if (t == len) t--;

                int l = t - h - 1;

                while (s[h] == s[t]) {
                    l += 2;
                    h--;
                    t++;
                    if (h <= -1 || t >= len) break;
                }

                if (tail - head + 1 < l) {
                    head = h + 1;
                    tail = t - 1;
                }

                curr++;
            }

            return s.substr(head, tail - head + 1);
        }
    };
}

TEST(L0005_LONGEST_PALINDROMIC_SUBSTRING, CASE_TEST) {
    using namespace L0005;
    Solution s;

    string a = "babad";
    EXPECT_EQ("bab", s.longestPalindrome(a));

    string b = "cbbd";
    EXPECT_EQ("bb", s.longestPalindrome(b));

    string c = "";
    EXPECT_EQ("", s.longestPalindrome(c));

    string d = "a";
    EXPECT_EQ("a", s.longestPalindrome(d));

    string e = "ab";
    EXPECT_EQ("a", s.longestPalindrome(e));

    string f = "aa";
    EXPECT_EQ("aa", s.longestPalindrome(f));

    string g = "abcdasdfghjkldcba";
    EXPECT_EQ("a", s.longestPalindrome(g));

    string h = "aaaa";
    EXPECT_EQ("aaaa", s.longestPalindrome(h));

}

#endif //LEET_CODE_0005_LONGEST_PALINDROMIC_SUBSTRING_H_

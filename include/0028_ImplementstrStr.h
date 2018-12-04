/*
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * 
 * Example 1:
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * Example 2:
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * Clarification:
 * What should we return when needle is an empty string? This is a great question to ask during an interview.
 */

#ifndef LEET_CODE_0028_IMPLEMENT_STRSTR_H_
#define LEET_CODE_0028_IMPLEMENT_STRSTR_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0028 {

    class Solution {
    public:
        int strStr(string haystack, string needle) {
            if (needle.empty()) return 0;

            int haystack_len = haystack.size();
            int needle_len = needle.size();
            bool found = true;

            for (int h_index = 0; h_index < haystack_len; h_index++) {
                if (h_index + needle_len > haystack_len) return -1;

                for (int n_index = 0; n_index < needle_len; n_index++) {
                    if (haystack[h_index + n_index] != needle[n_index]) {
                        found = false;
                        break;
                    }
                }

                if (found) return h_index;
                found = true;
            }

            return -1;
        }
    };

}

TEST(L0028_IMPLEMENT_STRSTR, CASE_TEST) {
    L0028::Solution s;

    string haystack1 = "hello", needle1 = "ll";
    EXPECT_EQ(s.strStr(haystack1, needle1), 2);

    string haystack2 = "aaaaa", needle2 = "bba";
    EXPECT_EQ(s.strStr(haystack2, needle2), -1);

    string haystack3 = "", needle3 = "s";
    EXPECT_EQ(s.strStr(haystack3, needle3), -1);

    string haystack4 = "s", needle4 = "";
    EXPECT_EQ(s.strStr(haystack4, needle4), 0);
}

#endif //LEET_CODE_0028_IMPLEMENT_STRSTR_H_

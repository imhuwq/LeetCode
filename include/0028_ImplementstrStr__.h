/*
 * 
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
 * For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
 * 
 * 
 */

#ifndef LEET_CODE_0028_IMPLEMENTSTRSTR___H_
#define LEET_CODE_0028_IMPLEMENTSTRSTR___H_

#include <map>
#include <stack>
#include <queue>
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
            if (haystack.size() < needle.size()) return -1;

            bool flag;
            int haystack_idx = 0, needle_idx = 0;
            int haystack_max_idx = haystack.size() - needle.size();
            while (haystack_idx <= haystack_max_idx) {
                flag = true;
                while (needle_idx < needle.size()) {
                    flag = needle[needle_idx] == haystack[haystack_idx + needle_idx];
                    if (not flag) break;
                    needle_idx++;
                }
                if (flag) return haystack_idx;
                haystack_idx++;
                needle_idx = 0;
            }
            return -1;
        }
    };

}

TEST(L0028_ImplementstrStr__, CASE_TEST) {
    using namespace L0028;
    Solution s;

//    EXPECT_EQ(s.strStr("hello", ""), 0);
//    EXPECT_EQ(s.strStr("hello", "ll"), 2);
//    EXPECT_EQ(s.strStr("aaaaa", "baa"), -1);
//    EXPECT_EQ(s.strStr("llllo", "llla"), -1);
//    EXPECT_EQ(s.strStr("aaa", "aaaa"), -1);
//    EXPECT_EQ(s.strStr("012300123468", "01234"), 5);
//    EXPECT_EQ(s.strStr("llllollla", "llla"), 5);
    EXPECT_EQ(s.strStr("mississippi", "issip"), 4);
}

#endif //LEET_CODE_0028_IMPLEMENTSTRSTR___H_

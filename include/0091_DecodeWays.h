/*
 * 
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given a non-empty string containing only digits, determine the total number of ways to decode it.
 * 
 * Example 1:
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * Example 2:
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 * 
 */

#ifndef LEET_CODE_0091_DECODEWAYS_H_
#define LEET_CODE_0091_DECODEWAYS_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0091 {
    class Solution {
    public:
        int numDecodings(string s) {
            // 17
            if (s.empty() || s[0] == '0') return 0;
            int num_pre = 1;
            int num_pre_pre = 1;
            for (int i = 1; i < s.size(); i++) {
                int num_cur = 0;
                if (s[i] != '0') num_cur += num_pre;
                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) num_cur += num_pre_pre;
                if (num_cur == 0) return 0;
                num_pre_pre = num_pre;
                num_pre = num_cur;
            }
            return num_pre;
        }
    };
}

TEST(L0091_DecodeWays, CASE_TEST) {
    using namespace L0091;
    Solution s;

    EXPECT_EQ(s.numDecodings("12"), 2);
}

#endif //LEET_CODE_0091_DECODEWAYS_H_

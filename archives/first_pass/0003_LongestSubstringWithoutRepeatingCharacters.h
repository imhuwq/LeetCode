/*
 * 
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * Example 2:
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * 
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * 
 */

#ifndef LEET_CODE_0003_LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_H_
#define LEET_CODE_0003_LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0003 {
    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if (s.size() <= 1) return s.size();

            vector<int> table(256, -1);

            int beg = 0, end;
            int result = -1;
            for (end = 0; end < s.size(); end++) {
                uint8_t c = s[end];
                if (table[c] != -1) {
                    result = max(result, end - beg);
                    beg = max(beg, table[c] + 1);
                }
                table[c] = end;
            }

            return max(result, end - beg);
        }
    };

}

TEST(L0003_LongestSubstringWithoutRepeatingCharacters, CASE_TEST) {
    using namespace L0003;
    Solution s;

    EXPECT_EQ(s.lengthOfLongestSubstring("pwwkew"), 3);
}

#endif //LEET_CODE_0003_LONGESTSUBSTRINGWITHOUTREPEATINGCHARACTERS_H_

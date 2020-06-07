/*
 * 
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
 * return the length of last word (last word means the last appearing word if we loop from left to right) in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a maximal substring consisting of non-space characters only.
 * 
 * Example:
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */

#ifndef LEET_CODE_0058_LENGTHOFLASTWORD_H_
#define LEET_CODE_0058_LENGTHOFLASTWORD_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0058 {
    class Solution {
    public:
        int lengthOfLastWord(string s) {
            if (s.empty()) return 0;

            int len = 0;
            bool is_word = false;
            for (int idx = s.size() - 1; idx >= 0; idx--) {
                if (s[idx] == ' ') {
                    if (is_word) return len;
                    is_word = false;
                } else {
                    is_word = true;
                    len++;
                }
            }

            return len;
        }
    };


}

TEST(L0058_LengthofLastWord, CASE_TEST) {
    using namespace L0058;
    Solution s;

    EXPECT_EQ(s.lengthOfLastWord("H"), 1);
    EXPECT_EQ(s.lengthOfLastWord("H "), 1);
    EXPECT_EQ(s.lengthOfLastWord("Hello World"), 5);
    EXPECT_EQ(s.lengthOfLastWord("Hello a"), 1);
    EXPECT_EQ(s.lengthOfLastWord("Hello  "), 5);
    EXPECT_EQ(s.lengthOfLastWord("Hello  aaa"), 3);
    EXPECT_EQ(s.lengthOfLastWord("Hello  aaa  bbb"), 3);
}

#endif //LEET_CODE_0058_LENGTHOFLASTWORD_H_

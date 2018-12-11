/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * 
 * Example:
 * Input: "Hello World"
 */

#ifndef LEET_CODE_0058_LENGTH_OF_LAST_WORD_H_
#define LEET_CODE_0058_LENGTH_OF_LAST_WORD_H_

#include <stack>
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

            int length = 0;
            bool wordFinished = true;
            for (const auto &c: s) {
                if (c == ' ') wordFinished = true;
                else {
                    if (wordFinished) {
                        wordFinished = false;
                        length = 0;
                    }
                    length++;
                }
            }
            return length;
        }
    };

}

TEST(L0058_LENGTH_OF_LAST_WORD, CASE_TEST) {
    L0058::Solution s;

    EXPECT_EQ(s.lengthOfLastWord(""), 0);
    EXPECT_EQ(s.lengthOfLastWord(" "), 0);
    EXPECT_EQ(s.lengthOfLastWord("Hello "), 5);
    EXPECT_EQ(s.lengthOfLastWord("Hello     "), 5);
    EXPECT_EQ(s.lengthOfLastWord(" World"), 5);
    EXPECT_EQ(s.lengthOfLastWord("Hello World"), 5);
}

#endif //LEET_CODE_0058_LENGTH_OF_LAST_WORD_H_


/*
 * 
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 * 2: abc
 * 3: def
 * 4: ghi
 * 5: jkl
 * 6: mno
 * 7: pqrs
 * 8: tuv
 * 9: wxyz
 * 
 * Example:
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 * 
 */

#ifndef LEET_CODE_0017_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H_
#define LEET_CODE_0017_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0017 {
    class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            map<char, string> mapper = {{'2', "abc"},
                                        {'3', "def"},
                                        {'4', "ghi"},
                                        {'5', "jkl"},
                                        {'6', "mno"},
                                        {'7', "pqrs"},
                                        {'8', "tuv"},
                                        {'9', "wxyz"}};
            size_t count = digits.size();
            if (count == 0) return {};

            size_t num_combinations = 1;
            size_t num_all_letters = 0;
            for (auto c:digits) {
                num_combinations *= mapper.at(c).size();
                num_all_letters += mapper.at(c).size();
            }

            vector<string> rt(num_combinations, "");
            size_t len_section = num_combinations;
            size_t combination_idx = 0;
            for (char digit:digits) {
                combination_idx = 0;
                string &letters = mapper.at(digit);
                len_section = len_section / letters.size();
                while (combination_idx < num_combinations) {
                    for (char letter:letters) {
                        for (size_t idx = 0; idx < len_section; idx++) {
                            rt[combination_idx++].push_back(letter);
                        }
                    }
                }
            }
            return rt;
        }
    };
}

TEST(L0017_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER, CASE_TEST) {
    using namespace L0017;
    Solution s;

    EXPECT_EQ(s.letterCombinations("2"), 3);
    EXPECT_EQ(s.letterCombinations("23"), 9);
    EXPECT_EQ(s.letterCombinations("237"), 36);
}

#endif //LEET_CODE_0017_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H_

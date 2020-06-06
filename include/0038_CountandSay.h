/*
 * 
 * The count-and-say sequence is the sequence of integers with the first five terms as following:
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 6.     312211
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
 * You can do so recursively, in other words from the previous member read off the digits,
 * counting the number of digits in groups of the same digit.
 * 
 * Note: Each term of the sequence of integers will be represented as a string.
 * 
 * 
 * 
 * Example 1:
 * Input: 1
 * Output: "1"
 * Explanation: This is the base case.
 * 
 * Example 2:
 * Input: 4
 * Output: "1211"
 * Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" which means frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation of "12" and "11" which is "1211".
 * 
 */

#ifndef LEET_CODE_0038_COUNTANDSAY_H_
#define LEET_CODE_0038_COUNTANDSAY_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0038 {
    class Solution {
    public:
        string countAndSay(int target_n) {
            int current_n = 1;
            string tmp_say;
            string final_say = "1";

            while (current_n < target_n) {
                tmp_say = "";
                int idx = 1;
                int count = 1;

                while (idx <= final_say.size()) {
                    if (idx == final_say.size()) {
                        tmp_say.push_back('0' + count);
                        tmp_say.push_back(final_say[idx - 1]);
                        break;
                    }

                    if (final_say[idx] != final_say[idx - 1]) {
                        tmp_say.push_back('0' + count);
                        tmp_say.push_back(final_say[idx - 1]);
                        count = 1;
                    } else {
                        count += 1;
                    }

                    idx++;
                }

                final_say = tmp_say;
                current_n++;
            }
            return final_say;
        }
    };
}

TEST(L0038_CountandSay, CASE_TEST) {
    using namespace L0038;
    Solution s;

    EXPECT_EQ(s.countAndSay(1), "1");
    EXPECT_EQ(s.countAndSay(2), "11");
    EXPECT_EQ(s.countAndSay(3), "21");
    EXPECT_EQ(s.countAndSay(4), "1211");
    EXPECT_EQ(s.countAndSay(5), "111221");
    EXPECT_EQ(s.countAndSay(6), "312211");
    EXPECT_EQ(s.countAndSay(7), "13112221");
}

#endif //LEET_CODE_0038_COUNTANDSAY_H_

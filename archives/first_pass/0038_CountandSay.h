/*
 * The count-and-say sequence is the sequence of integers with the first five terms as following:
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a string.
 *  
 * 
 * Example 1:
 * Input: 1
 * Output: "1"
 * 
 * Example 2:
 * Input: 4
 */

#ifndef LEET_CODE_0038_COUNT_AND_SAY_H_
#define LEET_CODE_0038_COUNT_AND_SAY_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0038 {

    class Solution {
    public:
        string countAndSay(int n) {
            vector<int> say = {1};
            if (n == 1) return "1";

            vector<int> count = {};
            int last = 1;
            while (n > 1) {
                int num = 0;
                for (size_t i = 0; i < say.size(); i++) {
                    if (say[i] != last) {
                        count.push_back(num);
                        count.push_back(last);
                        last = say[i];
                        num = 1;
                    } else num++;
                }

                count.push_back(num);
                count.push_back(last);
                last = count[0];

//              swap vector without copy
                say.resize(count.size());
                move(count.begin(), count.end(), say.begin());
                count.clear();

                n--;
            }

//            stringify
            string str = "";
            for (const auto &s:say) {
                str.push_back(s + '0');
            }

            return str;
        }
    };

}

TEST(L0038_COUNT_AND_SAY, CASE_TEST) {
    L0038::Solution s;

    EXPECT_EQ(s.countAndSay(1), "1");
    EXPECT_EQ(s.countAndSay(1), "1");
    EXPECT_EQ(s.countAndSay(2), "11");
    EXPECT_EQ(s.countAndSay(3), "21");
    EXPECT_EQ(s.countAndSay(4), "1211");
    EXPECT_EQ(s.countAndSay(5), "111221");
    EXPECT_EQ(s.countAndSay(6), "312211");
    EXPECT_EQ(s.countAndSay(7), "13112221");
    EXPECT_EQ(s.countAndSay(8), "1113213211");
    EXPECT_EQ(s.countAndSay(9), "31131211131221");
    EXPECT_EQ(s.countAndSay(10), "13211311123113112211");
}

#endif //LEET_CODE_0038_COUNT_AND_SAY_H_

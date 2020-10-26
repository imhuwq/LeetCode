/*
 * 
 * Write a function to find the longest common prefix string amongst an array of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * Example 2:
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 */

#ifndef LEET_CODE_0014_LONGESTCOMMONPREFIX_H_
#define LEET_CODE_0014_LONGESTCOMMONPREFIX_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0014 {
    class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if (strs.empty()) return "";

            int shortest_idx = 0;
            int shortest_len = strs[0].size();

            for (int idx=0; idx < strs.size(); idx++) {
                if (strs[idx].size() < shortest_len) {
                    shortest_idx = idx;
                }
            }
            string& shortest_str = strs[shortest_idx];

            for (int idx=0; idx < shortest_str.size(); idx++) {
                char cha = shortest_str[idx];
                for (string &str:strs) {
                    if (str[idx] != cha) {
                        return shortest_str.substr(0, idx);
                    }
                }
            }

            return shortest_str;
        }
    };
}

TEST(L0014_LongestCommonPrefix, CASE_TEST) {
    using namespace L0014;
    Solution s;

    vector<string> input = {"flower", "flow", "flight"};
    EXPECT_EQ(s.longestCommonPrefix(input), "fl");

    input = {};
    EXPECT_EQ(s.longestCommonPrefix(input), "");

    input = {"dog","racecar","car"};
    EXPECT_EQ(s.longestCommonPrefix(input), "");

    input = {"racecar", "racecar", "racecar"};
    EXPECT_EQ(s.longestCommonPrefix(input), "racecar");

    input = {"ca", "a"};
    EXPECT_EQ(s.longestCommonPrefix(input), "");
}

#endif //LEET_CODE_0014_LONGESTCOMMONPREFIX_H_

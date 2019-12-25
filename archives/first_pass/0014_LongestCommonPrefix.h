/*
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
 * Note:
 * All given inputs are in lowercase letters a-z.
 */

#ifndef LEET_CODE_0014_LONGEST_COMMON_PREFIX_H_
#define LEET_CODE_0014_LONGEST_COMMON_PREFIX_H_

#include <vector>
#include <string>
#include <climits>
#include <gtest/gtest.h>

using namespace std;

namespace L0014 {
    class Solution {
    public:
        Solution() = default;

        string longestCommonPrefix(vector<string> &strs) {
            if (strs.empty()) return "";
            int shortest_idx = 0;
            size_t shortest_len = SIZE_MAX;
            int counter = 0;
            for (const auto &str:strs) {
                if (str.size() < shortest_len) {
                    shortest_idx = counter;
                    shortest_len = str.size();
                }
                counter ++;
            }

            if (shortest_len == 0) return "";
            string &shortest_str = strs[shortest_idx];

            int last_index = 0;
            bool broken = true;
            char current_char;
            for (int i = shortest_len - 1; i >= 0; i--) {
                current_char = shortest_str[i];
                if (broken) {
                    last_index = i;
                    broken = false;
                }
                for (const string &str: strs) {
                    if (current_char != str[i]) {
                        broken = true;
                        break;
                    }
                }
            }
            if (broken) return "";
            string result = string(shortest_str.begin(), shortest_str.begin() + last_index + 1);
            return result;
        }
    };
}


TEST(L0014_LONGEST_COMMON_PREFIX, CASE_TEST) {
    vector<string> strs1 = {"flower", "flow", "flight"};
    vector<string> strs2 = {"dog", "racecar", "car"};
    vector<string> strs3 = {"ca", "a"};

    L0014::Solution s;
    EXPECT_EQ(s.longestCommonPrefix(strs3), "");
    EXPECT_EQ(s.longestCommonPrefix(strs1), "fl");
    EXPECT_EQ(s.longestCommonPrefix(strs2), "");
}

#endif //LEET_CODE_0014_LONGEST_COMMON_PREFIX_H_

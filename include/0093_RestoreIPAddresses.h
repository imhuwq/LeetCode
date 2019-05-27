/*
 * 
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 * Example:
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 */

#ifndef LEET_CODE_0093_RESTOREIPADDRESSES_H_
#define LEET_CODE_0093_RESTOREIPADDRESSES_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0093 {
    class Solution {

    public:
        void join(vector<string> &inputs, string &out) {
            out.reserve(12);
            for (int i = 0; i < 3; i++) {
                out.insert(out.end(), inputs[i].begin(), inputs[i].end());
                out.push_back('.');
            }
            out.insert(out.end(), inputs[3].begin(), inputs[3].end());
        }

        void restoreIpAddresses(string &str, int str_pos, int ip_section,
                                vector<string> &result, vector<string> &results) {
            if (result.size() == 4) {
                string ip;
                join(result, ip);
                results.push_back(ip);
                return;
            }

            auto str_cursor = str.begin() + str_pos;
            int left_ip_sections = 4 - ip_section;
            int left_charaters = str.size() - str_pos;
            bool one_is_ok, two_is_ok, three_is_ok;

            // using one character
            left_charaters--; // consume first
            one_is_ok = left_charaters >= left_ip_sections && left_charaters <= left_ip_sections * 3;
            if (one_is_ok) {
                result.emplace_back(string(str_cursor, str_cursor + 1));
                restoreIpAddresses(str, str_pos + 1, ip_section + 1, result, results);
                result.pop_back();
            }

            // using two characters
            left_charaters--;  // consume second
            two_is_ok = left_charaters >= left_ip_sections && left_charaters <= left_ip_sections * 3;
            two_is_ok = two_is_ok && (str[str_pos] != '0');
            if (two_is_ok) {
                result.emplace_back(string(str_cursor, str_cursor + 2));
                restoreIpAddresses(str, str_pos + 2, ip_section + 1, result, results);
                result.pop_back();
            }

            //using three characters
            left_charaters--;  // consume third
            three_is_ok = left_charaters >= left_ip_sections && left_charaters <= left_ip_sections * 3;
            three_is_ok = three_is_ok && (str[str_pos] != '0');
            int value = (str[str_pos] - '0') * 100 + (str[str_pos + 1] - '0') * 10 + (str[str_pos + 2] - '0');
            three_is_ok = three_is_ok && (value <= 255);
            if (three_is_ok) {
                result.emplace_back(string(str_cursor, str_cursor + 3));
                restoreIpAddresses(str, str_pos + 3, ip_section + 1, result, results);
                result.pop_back();
            }

        }

        vector<string> restoreIpAddresses(string s) {
            vector<string> result;
            vector<string> results;
            restoreIpAddresses(s, 0, 1, result, results);
            return results;
        }
    };

}

TEST(L0093_RestoreIPAddresses, CASE_TEST) {
    using namespace L0093;
    Solution s;
    vector<string> ans = {"255.255.11.135", "255.255.111.35"};
    vector<string> out = s.restoreIpAddresses("25525511135");
    EXPECT_EQ(out, ans);
}

#endif //LEET_CODE_0093_RESTOREIPADDRESSES_H_

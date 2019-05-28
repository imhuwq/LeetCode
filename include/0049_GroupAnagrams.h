/*
 * 
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 *   ["ate","eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * Note:
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 */

#ifndef LEET_CODE_0049_GROUP_ANAGRAMS_H_
#define LEET_CODE_0049_GROUP_ANAGRAMS_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0049 {
    class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string> &strs) {
            vector<vector<string>> results;
            vector<string> result;

            string key;
            map<string, vector<string>> map;
            for (string &str:strs) {
                key = str;
                std::sort(key.begin(), key.end());
                map[key].push_back(str);
            }

            results.reserve(map.size());
            for (auto &pair:map) results.push_back(pair.second);
            return results;
        }
    };

}

TEST(L0049_GROUP_ANAGRAMS, CASE_TEST) {
    using namespace L0049;
    Solution s;

    vector<string> vec1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ret1 = s.groupAnagrams(vec1);
    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0049_GROUP_ANAGRAMS_H_

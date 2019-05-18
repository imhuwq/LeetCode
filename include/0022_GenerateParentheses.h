/*
 * 
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * For example, given n = 3, a solution set is:
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 * 
 */

#ifndef LEET_CODE_0022_GENERATE_PARENTHESES_H_
#define LEET_CODE_0022_GENERATE_PARENTHESES_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0022 {
    class Solution {
    public:
        void generateParenthesis(int n, vector<string> &rt, string current, int left_count, int right_count) {
            if (current.size() == n * 2) {
                rt.push_back(current);
                return;
            }
            if (left_count < n) generateParenthesis(n, rt, current + "(", left_count + 1, right_count);
            if (right_count < left_count) generateParenthesis(n, rt, current + ")", left_count, right_count + 1);
        }

        vector<string> generateParenthesis(int n) {
            vector<string> rt;
            generateParenthesis(n, rt, "", 0, 0);
            return rt;
        }
    };

}

TEST(L0022_GENERATE_PARENTHESES, CASE_TEST) {
    using namespace L0022;
    Solution s;
    vector<string> rt = s.generateParenthesis(3);
    vector<string> ep = {"((()))",
                         "(()())",
                         "(())()",
                         "()(())",
                         "()()()"};
    EXPECT_EQ(rt, ep);
}

#endif //LEET_CODE_0022_GENERATE_PARENTHESES_H_

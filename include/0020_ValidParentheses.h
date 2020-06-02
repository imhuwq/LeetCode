/*
 * 
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * Input: "()"
 * Output: true
 * 
 * Example 2:
 * Input: "()[]{}"
 * Output: true
 * 
 * Example 3:
 * Input: "(]"
 * Output: false
 * 
 * Example 4:
 * Input: "([)]"
 * Output: false
 * 
 * Example 5:
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */

#ifndef LEET_CODE_0020_VALIDPARENTHESES_H_
#define LEET_CODE_0020_VALIDPARENTHESES_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0020 {
    class Solution {
    public:
        bool isValid(string s) {
            stack<char> stack;

            for (char c:s) {
                if (c == ')') {
                    if (stack.empty()) return false;
                    if (stack.top() != '(') return false;
                    stack.pop();
                } else if (c == '}') {
                    if (stack.empty()) return false;
                    if (stack.top() != '{') return false;
                    stack.pop();

                } else if (c == ']') {
                    if (stack.empty()) return false;
                    if (stack.top() != '[') return false;
                    stack.pop();

                } else {
                    stack.push(c);
                }
            }

            return stack.empty();
        }
    };
}

TEST(L0020_ValidParentheses, CASE_TEST) {
    using namespace L0020;
    Solution s;

    EXPECT_EQ(s.isValid("()"), true);
    EXPECT_EQ(s.isValid("()[]{}"), true);
    EXPECT_EQ(s.isValid("(]"), false);
    EXPECT_EQ(s.isValid("([)]"), false);
    EXPECT_EQ(s.isValid("{[]}"), true);
}

#endif //LEET_CODE_0020_VALIDPARENTHESES_H_

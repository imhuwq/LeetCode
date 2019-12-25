/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.

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
 */

#ifndef LEET_CODE_0020_VALID_PARENTHESES_H_
#define LEET_CODE_0020_VALID_PARENTHESES_H_

#include <stack>
#include <string>
#include <climits>
#include <gtest/gtest.h>

using namespace std;

namespace L0020 {
    class Solution {
    public:
        Solution() = default;

        bool isValid(const string &s) {
            if (s.empty()) return true;
            if ((s.size() & 1) == 1) return false;

            stack<char> parentheses;

            for (const char &c:s) {
                switch (c){
                    case ')':
                        if (parentheses.empty()) return false;
                        if (parentheses.top() == '(') parentheses.pop() ;
                        break;
                    case ']':
                        if (parentheses.empty()) return false;
                        if (parentheses.top() == '[') parentheses.pop();
                        break;
                    case '}':
                        if (parentheses.empty()) return false;
                        if (parentheses.top() == '{') parentheses.pop();
                        break;
                    default:
                        parentheses.push(c);
                }
            }
            return parentheses.empty();
        }
    };
}


TEST(L0020_VALID_PARENTHESES, CASE_TEST) {
    string input1 = "()";
    string input2 = "()[]{}";
    string input3 = "(]";
    string input4 = "([)]";
    string input5 = "{[]}";
    string input6 = "(()])}[}[}[]][}}[}{})][[(]({])])}}(])){)((){";


    L0020::Solution s;
    EXPECT_TRUE(s.isValid(input1));
    EXPECT_TRUE(s.isValid(input2));
    EXPECT_FALSE(s.isValid(input3));
    EXPECT_FALSE(s.isValid(input4));
    EXPECT_TRUE(s.isValid(input5));
    EXPECT_FALSE(s.isValid(input6));
}

#endif //LEET_CODE_0020_VALID_PARENTHESES_H_

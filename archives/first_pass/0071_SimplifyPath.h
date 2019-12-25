/*
 * 
 * Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.
 * In a UNIX-style file system, a period . refers to the current directory.
 * Furthermore, a double period .. moves the directory up a level.
 * For more information, see: Absolute path vs relative path in Linux/Unix
 * 
 * Note that the returned canonical path must always begin with a slash /,
 * and there must be only a single slash / between two directory names.
 * The last directory name (if it exists) must not end with a trailing /.
 * Also, the canonical path must be the shortest string representing the absolute path.
 * 
 * Example 1:
 * 
 * Input: "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory name.
 * 
 * Example 2:
 * Input: "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
 * 
 * Example 3:
 * Input: "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
 * 
 * Example 4:
 * Input: "/a/./b/../../c/"
 * Output: "/c"
 * 
 * Example 5:
 * Input: "/a/../../b/../c//.//"
 * Output: "/c"
 * 
 * Example 6:
 * Input: "/a//b////c/d//././/.."
 * Output: "/a/b/c"
 * 
 */

#ifndef LEET_CODE_0071_SIMPLIFYPATH_H_
#define LEET_CODE_0071_SIMPLIFYPATH_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0071 {
    class Solution {
    public:
        string simplifyPath(string path) {
            vector<string> words;
            string word;
            char dot = '.';
            char slash = '/';
            char last = '/';

            int len = path.size();
            for (int i = 0; i < len; i++) {
                char c = path[i];
                if (c == slash) {
                    if (!word.empty()) {
                        words.push_back(word);
                        word.clear();
                    } else if (last == slash) {
                        last = slash;
                    } else if (last == dot) {
                        last = slash;
                    }
                } else if (c == dot) {
                    if (!word.empty()) {
                        word += ".";
                    } else if (last == slash) {
                        last = dot;
                    } else if (last == dot) {
                        if ((i < len - 1 && path[i + 1] == slash) || i == len - 1) { // only two dots
                            if (!words.empty()) words.pop_back();
                            last = slash;
                        } else {
                            word = "..";
                            last = slash;
                        }
                    }
                } else {
                    if (last == dot) word.push_back(dot);
                    word.push_back(c);
                    last = slash;
                }
            }
            if (!word.empty()) words.push_back(word);

            string result = "/";
            result.reserve(len);
            for (string &w:words) {
                result.insert(result.end(), w.begin(), w.end());
                result.push_back('/');
            }
            if (!words.empty()) result.pop_back();
            return result;
        }
    };
}

TEST(L0071_SimplifyPath, CASE_TEST) {
    using namespace L0071;
    Solution s;

    EXPECT_EQ(s.simplifyPath("/home/"), "/home");
    EXPECT_EQ(s.simplifyPath("/../"), "/");
    EXPECT_EQ(s.simplifyPath("/home//foo/"), "/home/foo");
    EXPECT_EQ(s.simplifyPath("/a/./b/../../c/"), "/c");
    EXPECT_EQ(s.simplifyPath("/a/../../b/../c//.//"), "/c");
    EXPECT_EQ(s.simplifyPath("/a//b////c/d//././/.."), "/a/b/c");
    EXPECT_EQ(s.simplifyPath("/..."), "/...");
    EXPECT_EQ(s.simplifyPath("/..hidden"), "/..hidden");
}

#endif //LEET_CODE_0071_SIMPLIFYPATH_H_

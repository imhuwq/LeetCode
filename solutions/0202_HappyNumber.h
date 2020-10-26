/*
 * 
 * Write an algorithm to determine if a number n is "happy".
 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number by
 * the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay),
 * or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 * Return True if n is a happy number, and False if not.
 * 
 * Example:
 * Input: 19
 * Output: true
 * 
 * Explanation:
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 
 */

#ifndef LEET_CODE_0202_HAPPYNUMBER_H_
#define LEET_CODE_0202_HAPPYNUMBER_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0202 {
    class Solution {
    public:
        bool isHappy(int n) {
            map<int, bool> record;

            int tmp, rem;
            while (true) {
                tmp = 0;
                while (n > 0) {
                    rem = n % 10;
                    tmp += rem * rem;
                    n = n / 10;
                }
                n = tmp;
                if (n == 1) return true;
                else if (record.find(n) != record.end()) return false;
                record[n] = true;
            }
        }
    };

}

TEST(L0202_HappyNumber, CASE_TEST) {
    using namespace L0202;
    Solution s;

    EXPECT_EQ(s.isHappy(19), true);
}

#endif //LEET_CODE_0202_HAPPYNUMBER_H_

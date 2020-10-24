/*
 * 
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Follow up: Could you write a solution that works in logarithmic time complexity?
 * 
 * 
 * 
 * Example 1:
 * Input: n = 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 * 
 * Example 2:
 * Input: n = 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 * 
 * Example 3:
 * Input: n = 0
 * Output: 0
 * 
 * 
 * Constraints:
 * 1 <= n <= 104
 * 
 */

#ifndef LEET_CODE_0172_FACTORIALTRAILINGZEROES_H_
#define LEET_CODE_0172_FACTORIALTRAILINGZEROES_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0172 {
    class Solution {
    public:
        int trailingZeroes(int n) {
            int factor = 5;
            int result = 0;
            while (factor <= n) {
                result += n / factor;
                factor *= 5;
            }
            return result;
        }
    };

}

TEST(L0172_FactorialTrailingZeroes, CASE_TEST) {
    using namespace L0172;
    Solution s;

    EXPECT_EQ(s.trailingZeroes(3), 0);
    EXPECT_EQ(s.trailingZeroes(5), 1);
    EXPECT_EQ(s.trailingZeroes(0), 0);

}

#endif //LEET_CODE_0172_FACTORIALTRAILINGZEROES_H_

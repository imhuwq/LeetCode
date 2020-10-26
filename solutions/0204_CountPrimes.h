/*
 * 
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * 
 * Example 1:
 * Input: n = 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * Example 2:
 * Input: n = 0
 * Output: 0
 * 
 * Example 3:
 * Input: n = 1
 * Output: 0
 * 
 * Constraints:
 * 0 <= n <= 5 * 106
 * 
 */

#ifndef LEET_CODE_0204_COUNTPRIMES_H_
#define LEET_CODE_0204_COUNTPRIMES_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0204 {
    class Solution {
    public:
        int countPrimes(int n) {

        }
    };
}

TEST(L0204_CountPrimes, CASE_TEST) {
    using namespace L0204;
    Solution s;

    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0204_COUNTPRIMES_H_

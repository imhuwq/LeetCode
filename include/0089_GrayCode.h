/*
 * 
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 * Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code.
 * A gray code sequence must begin with 0.
 * 
 * Example 1:
 * Input: 2
 * Output: [0,1,3,2]
 * 
 * Explanation:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * 
 * For a given n, a gray code sequence may not be uniquely defined.
 * For example, [0,2,3,1] is also a valid gray code sequence.
 * 
 * 00 - 0
 * 10 - 2
 * 11 - 3
 * 01 - 1
 * 
 * Example 2:
 * Input: 0
 * Output: [0]
 * Explanation: We define the gray code sequence to begin with 0.
 *              A gray code sequence of n has size = 2**n, which for n = 0 the size is 2**0 = 1.
 *              Therefore, for n = 0 the gray code sequence is [0].
 * 
 */

#ifndef LEET_CODE_0089_GRAYCODE_H_
#define LEET_CODE_0089_GRAYCODE_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0089 {
    class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> result = {0};
            int max_count = 1 << n;
            result.reserve(max_count);

            for (int i = 0; i < n; i++) {
                uint32_t mask = 1 << i;
                for (int idx = result.size() - 1; idx >= 0; idx--) {
                    result.push_back(result[idx] | mask);
                }
            }

            return result;
        }
    };
}

TEST(L0089_GrayCode, CASE_TEST) {
    using namespace L0089;
    Solution s;
    s.grayCode(2);
    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0089_GRAYCODE_H_

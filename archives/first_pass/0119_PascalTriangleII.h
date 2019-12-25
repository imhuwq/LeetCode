/*
 * Given a non-negative index k where k ≤ 33, return the k-th index row of the Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly above it.
 * 
 * Example:
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * Follow up:
 * Could you optimize your algorithm to use only O(k) extra space?
 */

#ifndef LEET_CODE_0119_PASCAL_TRIANGLE_II_H_
#define LEET_CODE_0119_PASCAL_TRIANGLE_II_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0119 {

    class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int> result(rowIndex + 1, 1);

            if (rowIndex == 0) return result;
            for (size_t i = 1; i < rowIndex + 1; i++) {
                int last = 1;
                int tmp = 1;
                for (size_t j = 1; j < i; j++) {
                    tmp = result[j] + last;
                    last = result[j];
                    result[j] = tmp;
                }
                result[i] = 1;
            }
            return move(result);
        }
    };

}

TEST(L0119_PASCAL_TRIANGLE_II, CASE_TEST) {
    using namespace L0119;
    Solution s;

    vector<int> result = {1, 3, 3, 1};
    EXPECT_EQ(s.getRow(3), result);
}

#endif //LEET_CODE_0119_PASCAL'S_TRIANGLE_II_H_

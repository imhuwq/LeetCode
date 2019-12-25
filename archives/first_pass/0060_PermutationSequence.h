/*
 * 
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 * 
 * Note:
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * Example 1:
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * Example 2:
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 */

#ifndef LEET_CODE_0060_PERMUTATIONSEQUENCE_H_
#define LEET_CODE_0060_PERMUTATIONSEQUENCE_H_

#include <list>
#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0060 {
    class Solution {
    public:
        int fract(int n) {
            if (n == 0) return 1;
            int result = n;
            while (n > 1) result *= --n;
            return result;
        }

        string getPermutation(int n, int k) {
            vector<int> sequence(n, 0);
            for (int i = 0; i < n; i++) sequence[i] = i + 1;

            string result;
            while (!sequence.empty()) {
                int width = sequence.size() - 1;
                int cnt = fract(width);
                int idx = k / cnt;

                k %= cnt;
                if (k == 0) {
                    result.push_back('0' + sequence[idx - 1]);
                    for (int i = width; i >= 0; i--) {
                        if (i == idx - 1) continue;
                        result.push_back('0' + sequence[i]);
                    }
                    return result;
                }

                result.push_back('0' + sequence[idx]);
                sequence.erase(sequence.begin() + idx);
            }

            for (auto s:sequence) result.push_back('0' + s);
            return result;
        }
    };
}

TEST(L0060_PermutationSequence, CASE_TEST) {
    using namespace L0060;
    Solution s;

    EXPECT_EQ(s.getPermutation(3, 3), "213");
    EXPECT_EQ(s.getPermutation(3, 5), "312");
    EXPECT_EQ(s.getPermutation(2, 2), "21");
    EXPECT_EQ(s.getPermutation(3, 2), "132");
    EXPECT_EQ(s.getPermutation(3, 4), "231");
}

#endif //LEET_CODE_0060_PERMUTATIONSEQUENCE_H_

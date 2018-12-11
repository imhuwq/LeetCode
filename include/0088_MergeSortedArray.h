/*
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * 
 * Note:
 * 
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
 *
 * Example:
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 */

#ifndef LEET_CODE_0088_MERGE_SORTED_ARRAY_H_
#define LEET_CODE_0088_MERGE_SORTED_ARRAY_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0088 {
    class Solution {
    public:
        void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
            if (n == 0) return;

            int pos = m + n - 1;
            int num1, num2;
            while (pos >= 0) {
                if (m == 0) {
                    nums1[pos] = nums2[n - 1];
                    n--;
                } else if (n == 0) {
                    nums1[pos] = nums1[m - 1];
                    m--;
                } else if (nums1[m - 1] >= nums2[n - 1]) {
                    nums1[pos] = nums1[m - 1];
                    m--;
                } else {
                    nums1[pos] = nums2[n - 1];
                    n--;
                }
                pos--;
            }
        }
    };
}

TEST(L0088_MERGE_SORTED_ARRAY, CASE_TEST) {
    L0088::Solution s;

    vector<int> nums11 = {1, 2, 3, 0, 0, 0};
    vector<int> nums21 = {2, 5, 6};
    vector<int> numsr1 = {1, 2, 2, 3, 5, 6};
    s.merge(nums11, 3, nums21, 3);
    EXPECT_EQ(nums11, numsr1);

    vector<int> nums12 = {-1, 0, 0, 3, 3, 3, 0, 0, 0};
    vector<int> nums22 = {1, 2, 2};
    vector<int> numsr2 = {-1, 0, 0, 1, 2, 2, 3, 3, 3};
    s.merge(nums12, 6, nums22, 3);
    EXPECT_EQ(nums12, numsr2);
}

#endif //LEET_CODE_0088_MERGE_SORTED_ARRAY_H_


/*
 * 
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * 
 * Note:
 * 
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
 * 
 * Example:
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * Output: [1,2,2,3,5,6]
 * 
 */

#ifndef LEET_CODE_0088_MERGESORTEDARRAY_H_
#define LEET_CODE_0088_MERGESORTEDARRAY_H_

#include <map>
#include <stack>
#include <queue>
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
            int back_idx = m + n - 1;
            int num1_idx = m - 1;
            int num2_idx = n - 1;
            while (num1_idx >= 0 or num2_idx >= 0) {
                if (num1_idx < 0) {
                    nums1[back_idx--] = nums2[num2_idx--];
                } else if (num2_idx < 0) {
                    nums1[back_idx--] = nums1[num1_idx--];
                } else if (nums1[num1_idx] > nums2[num2_idx]) {
                    nums1[back_idx--] = nums1[num1_idx--];
                } else {
                    nums1[back_idx--] = nums2[num2_idx--];
                }
            }
        }
    };

}

TEST(L0088_MergeSortedArray, CASE_TEST) {
    using namespace L0088;
    Solution s;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    vector<int> output = {1, 2, 2, 3, 5, 6};
    s.merge(nums1, 3, nums2, 3);
    EXPECT_EQ(nums1, output);

    nums1 = {0};
    nums2 = {1};
    output = {1};
    s.merge(nums1, 0, nums2, 1);
    EXPECT_EQ(nums1, output);
}

#endif //LEET_CODE_0088_MERGESORTEDARRAY_H_

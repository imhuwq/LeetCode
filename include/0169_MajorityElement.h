/*
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always exist in the array.
 * 
 * Example 1:
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 */

#ifndef LEET_CODE_0169_MAJORITY_ELEMENT_H_
#define LEET_CODE_0169_MAJORITY_ELEMENT_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0169 {
    class Solution {
    public:
        int majorityElement(vector<int> &nums) {
            int s = nums.size();
            int lo = 0;
            int hi = s - 1;
            return majorityElement(nums, lo, hi);
        }

    private:
        int selectByCounting(vector<int> &nums, int left, int right, int lo, int hi) {
            int leftCount = 0;
            int rightCount = 0;

            for (int i = lo; i <= hi; i++) {
                if (nums[i] == left) leftCount++;
                else if (nums[i] == right) rightCount++;
            }

            return leftCount > rightCount ? left : right;
        }

        int majorityElement(vector<int> &nums, int lo, int hi) {
            if (hi - lo <= 1) return nums[lo];

            int mid = (lo + hi) / 2;
            int left = majorityElement(nums, lo, mid);
            int right = majorityElement(nums, mid + 1, hi);

            if (left == right) return left;
            return selectByCounting(nums, left, right, lo, hi);
        }
    };
}

TEST(L0169_MAJORITY_ELEMENT, CASE_TEST) {
    using namespace L0169;
    Solution s;
    vector<int> v1 = {3, 2, 1};
    vector<int> v2 = {2, 2, 1, 1, 1, 2, 2};
    EXPECT_EQ(s.majorityElement(v1), 3);
    EXPECT_EQ(s.majorityElement(v2), 2);
}

#endif //LEET_CODE_0169_MAJORITY_ELEMENT_H_

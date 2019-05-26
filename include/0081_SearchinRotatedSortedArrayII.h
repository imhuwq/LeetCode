/*
 * 
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return true, otherwise return false.
 * 
 * Example 1:
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * 
 * Example 2:
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 * 
 * Follow up:
 * This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 * 
 */

#ifndef LEET_CODE_0081_SEARCHINROTATEDSORTEDARRAYII_H_
#define LEET_CODE_0081_SEARCHINROTATEDSORTEDARRAYII_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0081 {
    class Solution {
    public:
        bool search(vector<int> &nums, int lo, int hi, int target) {
            if (lo > hi) return false;
            if (lo == hi) return nums[lo] == target;

            int mid = (lo + hi) / 2;
            if (nums[mid] > target) {  // 中点比 target 大
                // 优先搜寻左边
                bool found = search(nums, lo, mid - 1, target);
                // 左边找不到，右边不是递增的情况下，也有可能在右边
                if (!found && nums[mid] >= nums[hi]) found = (search(nums, mid + 1, hi, target));
                return found;
            } else if (nums[mid] < target) {
                // 优先搜寻右边
                bool found = search(nums, mid + 1, hi, target);
                // 右边没找到，左边不是递增的情况下，也有可能在左边
                if (!found && nums[lo] >= nums[mid]) found = search(nums, lo, mid - 1, target);
                return found;
            } else {
                return true;
            }
        }

        bool search(vector<int> &nums, int target) {
            return search(nums, 0, nums.size() - 1, target);
        }
    };

}

TEST(L0081_SearchinRotatedSortedArrayII, CASE_TEST) {
    using namespace L0081;
    Solution s;

    vector<int> vec = {2, 5, 6, 0, 0, 1, 2};
    EXPECT_EQ(s.search(vec, 3), false);

    vec = {1, 3, 1, 1, 1};
    EXPECT_EQ(s.search(vec, 3), false);
}

#endif //LEET_CODE_0081_SEARCHINROTATEDSORTEDARRAYII_H_

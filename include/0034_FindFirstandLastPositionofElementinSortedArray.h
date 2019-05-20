/*
 * 
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */

#ifndef LEET_CODE_0034_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H_
#define LEET_CODE_0034_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0034 {
    class Solution {
    public:
        int binary_search(vector<int> &nums, int lo, int hi, int target) {
            int mid;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (nums[mid] == target) return mid;
                else if (nums[mid] < target) lo = mid + 1;
                else hi = mid - 1;
            }

            return -1;
        }

        vector<int> searchRange(vector<int> &nums, int target) {
            int mid = -1, lo = 0, hi = nums.size() - 1;

            mid = binary_search(nums, 0, hi, target);
            if (mid == -1) return {-1, -1};

            int left = mid;
            int left_lo = lo;
            int left_hi = mid - 1;
            while (left_lo <= left_hi) {
                mid = binary_search(nums, left_lo, left_hi, target);
                if (mid != -1) {
                    left = mid;
                    left_hi = mid - 1;
                } else break;
            }

            int right = mid;
            int right_lo = mid + 1;
            int right_hi = hi;
            while (right_lo <= right_hi) {
                mid = binary_search(nums, right_lo, right_hi, target);
                if (mid != -1) {
                    right = mid;
                    right_lo = mid + 1;
                } else break;
            }

            return {left, right};
        }
    };

}

TEST(L0034_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY, CASE_TEST) {
    using namespace L0034;
    Solution s;

    vector<int> vec1 = {5, 7, 7, 8, 8, 10};
    vector<int> ans1 = {3, 4};
    EXPECT_EQ(s.searchRange(vec1, 8), ans1);

    vector<int> vec2 = {5, 7, 7, 8, 8, 10};
    vector<int> ans2 = {-1, -1};
    EXPECT_EQ(s.searchRange(vec2, 6), ans2);

    vector<int> vec3 = {2, 2};
    vector<int> ans3 = {0, 1};
    EXPECT_EQ(s.searchRange(vec3, 2), ans3);
}

#endif //LEET_CODE_0034_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H_

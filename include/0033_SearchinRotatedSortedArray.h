/*
 * 
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */

#ifndef LEET_CODE_0033_SEARCH_IN_ROTATED_SORTED_ARRAY_H_
#define LEET_CODE_0033_SEARCH_IN_ROTATED_SORTED_ARRAY_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0033 {
    class Solution {
    public:
        int search(vector<int> &nums, int target) {
            int lo = 0;
            int hi = nums.size() - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) {
                    if (nums[mid] < nums[hi]) hi = mid - 1;     // if right is mono ascending, target cannot be right
                    else if (nums[lo] <= target) hi = mid - 1;  // if left is mono ascending, target can be left only if min(left) <= target
                    else lo = mid + 1;
                } else {
                    if (nums[lo] < nums[mid]) lo = mid + 1;     // if left is mono ascending, target cannot be left
                    else if (nums[hi] >= target) lo = mid + 1;  // if right is mono ascending, target can be right only if max(right) >= target
                    else hi = mid - 1;
                }
            }

            return -1;
        }
    };

}

TEST(L0033_SEARCH_IN_ROTATED_SORTED_ARRAY, CASE_TEST) {
    using namespace L0033;
    Solution s;

    vector<int> vec1 = {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(s.search(vec1, 0), 4);

    vector<int> vec2 = {4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(s.search(vec2, 3), -1);
}

#endif //LEET_CODE_0033_SEARCH_IN_ROTATED_SORTED_ARRAY_H_

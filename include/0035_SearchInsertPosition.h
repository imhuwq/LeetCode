/*
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * Example 2:
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * Example 3:
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * Example 4:
 * Input: [1,3,5,6], 0
 * Output: 0
 */

#ifndef LEET_CODE_0035_SEARCH_INSERT_POSITION_H_
#define LEET_CODE_0035_SEARCH_INSERT_POSITION_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0035 {

    class Solution {
    public:
        int searchInsert(vector<int> &nums, int target) {
            if (nums.empty()) return 0;

            int beg = 0;
            int end = nums.size() - 1;
            int mid = 0;

            while (beg < end - 1) {
                mid = (beg + end) / 2;
                if (target > nums[mid]) beg = mid;
                else if (target < nums[mid]) end = mid;
                else return mid;
            }

            if (target > nums[beg]) return target > nums[end] ? end + 1 : beg + 1;
            else if (target < nums[beg]) return max(beg - 1, 0);
            else return beg;
        }
    };

}

TEST(L0035_SEARCH_INSERT_POSITION, CASE_TEST) {
    L0035::Solution s;

    vector<int> nums1 = {1, 3, 5, 6};
    EXPECT_EQ(s.searchInsert(nums1, 5), 2);

    vector<int> nums2 = {1, 3, 5, 6};
    EXPECT_EQ(s.searchInsert(nums2, 2), 1);

    vector<int> nums3 = {1, 3, 5, 6};
    EXPECT_EQ(s.searchInsert(nums3, 7), 4);

    vector<int> nums4 = {1, 3, 5, 6};
    EXPECT_EQ(s.searchInsert(nums4, 0), 0);

}

#endif //LEET_CODE_0035_SEARCH_INSERT_POSITION_H_

/*
 * 
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
 * 
 * 
 */

#ifndef LEET_CODE_0035_SEARCHINSERTPOSITION_H_
#define LEET_CODE_0035_SEARCHINSERTPOSITION_H_

#include <map>
#include <stack>
#include <queue>
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

            int left = 0, right = nums.size() - 1;

            while (left < right) {
                int mid = (left + right) / 2;
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            if (nums[left] >= target) return left;
            return left + 1;
        }
    };

}

TEST(L0035_SearchInsertPosition, CASE_TEST) {
    using namespace L0035;
    Solution s;

    vector<int> input;

//    input = {1, 3, 5, 6};
//    EXPECT_EQ(s.searchInsert(input, 5), 2);

//    input = {1};
//    EXPECT_EQ(s.searchInsert(input, 1), 0);

    input = {1, 3};
    EXPECT_EQ(s.searchInsert(input, 0), 0);

    input = {1, 3, 5, 6};
    EXPECT_EQ(s.searchInsert(input, 2), 1);

    input = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(s.searchInsert(input, 9), 9);

    input = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(s.searchInsert(input, 11), 11);

    input = {0, 1, 2, 3, 4, 5, 6, 7, 9, 9, 10};
    EXPECT_EQ(s.searchInsert(input, 8), 8);
}

#endif //LEET_CODE_0035_SEARCHINSERTPOSITION_H_

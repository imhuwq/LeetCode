/*
 * 
 * Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
 * 
 * Note:
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may not use the same element twice.
 * 
 * 
 * Example 1:
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 * Example 2:
 * Input: numbers = [2,3,4], target = 6
 * Output: [1,3]
 * 
 * Example 3:
 * Input: numbers = [-1,0], target = -1
 * Output: [1,2]
 * 
 * 
 * Constraints:
 * 2 <= nums.length <= 3 * 104
 * -1000 <= nums[i] <= 1000
 * nums is sorted in increasing order.
 * -1000 <= target <= 1000
 * 
 */

#ifndef LEET_CODE_0167_TWOSUMII_INPUTARRAYISSORTED_H_
#define LEET_CODE_0167_TWOSUMII_INPUTARRAYISSORTED_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0167 {
    class Solution {
    public:

        int binSearch(vector<int> &numbers, int start, int end, int target) {
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (numbers[mid] == target) return mid;
                else if (numbers[mid] > target) end = mid - 1;
                else if (numbers[mid] < target) start = mid + 1;
            }
            return -1;
        }

        vector<int> twoSum(vector<int> &numbers, int target) {
            for (int i = 0; i < numbers.size() - 1; i++) {
                int j = binSearch(numbers, i + 1, numbers.size() - 1, target - numbers[i]);
                if (j != -1) return {i + 1, j + 1};
            }

            return {0, 0};
        }

        vector<int> twoSum(vector<int> &&numbers, int target) {
            return twoSum(numbers, target);
        }
    };
}

TEST(L0167_TwoSumII_Inputarrayissorted, CASE_TEST) {
    using namespace L0167;
    Solution s;

    EXPECT_EQ(s.twoSum({2, 7, 11, 15}, 9), vector<int>({1, 2}));
    EXPECT_EQ(s.twoSum({2, 3, 4}, 6), vector<int>({1, 3}));
    EXPECT_EQ(s.twoSum({-1, 0}, -1), vector<int>({1, 2}));

}

#endif //LEET_CODE_0167_TWOSUMII_INPUTARRAYISSORTED_H_

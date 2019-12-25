/*
 * 
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 * 
 * Note:
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 * 
 */

#ifndef LEET_CODE_0015_3SUM_H_
#define LEET_CODE_0015_3SUM_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

namespace L0015 {
    class Solution {
    public:
        static int Divide(vector<int> &nums, int lo, int hi) {
            int key = nums[lo];
            int left = lo;
            int right = hi + 1;
            while (true) {
                while (nums[++left] <= key) {
                    if (left == hi) {
                        std::swap(nums[lo], nums[left]);
                        return left;
                    }
                }
                while (nums[--right] > key) {
                    if (right == left + 1) {
                        return left;
                    }
                }
                if (left < right) std::swap(nums[left], nums[right]);
                else break;
            }

            std::swap(nums[lo], nums[right]);
            return right;
        }

        static void QuickSort(vector<int> &nums, int lo, int hi) {
            if (lo >= hi) return;
            int divide = Divide(nums, lo, hi);
            QuickSort(nums, lo, divide - 1);
            QuickSort(nums, divide + 1, hi);
        }

        static void QuickSort(vector<int> &nums) {
            int divide = Divide(nums, 0, nums.size() - 1);
            QuickSort(nums, 0, divide - 1);
            QuickSort(nums, divide + 1, nums.size() - 1);
        }

        vector<vector<int>> threeSum(vector<int> &nums) {
            vector<vector<int>> rt;
            if (nums.size() < 3) return rt;
            std::sort(nums.begin(), nums.end());

            for (int first_idx = 0; first_idx <= nums.size() - 2; first_idx++) {
                int first_num = nums[first_idx];
                int second_idx = first_idx + 1;
                int third_idx = nums.size() - 1;
                while (second_idx < third_idx) {
                    int second_num = nums[second_idx];
                    int third_num = nums[third_idx];
                    int two_sum = second_num + third_num;
                    if (two_sum + first_num > 0) third_idx--;
                    else if (two_sum + first_num < 0) second_idx++;
                    else {
                        vector<int> three_num = {nums[first_idx], nums[second_idx], nums[third_idx]};
                        rt.push_back(three_num);
                        while (second_idx < third_idx && nums[second_idx] == second_num) { second_idx++; }
                        while (second_idx < third_idx && nums[third_idx] == third_num) { third_idx--; }
                    }
                }
                while (first_idx < nums.size() - 2 && nums[first_idx + 1] == first_num) { first_idx++; }
            }

            std::sort(rt.begin(), rt.end());
            return rt;
        }
    };
}

TEST(L0015_3SUM, CASE_TEST) {
    using namespace L0015;
    Solution s;
    vector<int> vec1{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ret1 = s.threeSum(vec1);
    vector<vector<int>> ept1 = {{-1, 0,  1},
                                {-1, -1, 2}};
    std::sort(ept1.begin(), ept1.end());
    EXPECT_EQ(ret1, ept1);
}

#endif //LEET_CODE_0015_3SUM_H_

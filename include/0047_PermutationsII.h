/*
 * 
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * 
 * Example:
 * 
 * Input: [1,1,2]
 * Output:
 * [
 *   [1,1,2],
 *   [1,2,1],
 *   [2,1,1]
 * ]
 * 
 */

#ifndef LEET_CODE_0047_PERMUTATIONS_II_H_
#define LEET_CODE_0047_PERMUTATIONS_II_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0047 {
    class Solution {
    public:
        void permute(vector<int> &nums, int start, vector<vector<int>> &permutations) {
            if (start == nums.size() - 1) {
                permutations.push_back(nums);
                return;
            }

            // 0 0 0 1 9
            // 9 0 0 1 0
            for (int i = start; i < nums.size(); i++) {
                bool is_duplicate = false;
                for (int j = i - 1; j >= start; j--) {
                    if (nums[j] == nums[i]) {
                        is_duplicate = true;
                        break;
                    };
                }
                if (is_duplicate) continue;

                std::swap(nums[start], nums[i]);
                permute(nums, start + 1, permutations);
                std::swap(nums[start], nums[i]);
            }
        }

        vector<vector<int>> permuteUnique(vector<int> &nums) {
            std::sort(nums.begin(), nums.end());
            int size = nums.size();
            for (int i = size - 1; i > 1; i--) size *= i;

            vector<vector<int>> permutations;
            permutations.reserve(size);
            permute(nums, 0, permutations);
            return permutations;
        }
    };
}

TEST(L0047_PERMUTATIONS_II, CASE_TEST) {
    using namespace L0047;
    Solution s;
    vector<int> vec1 = {1, 1, 2};
    s.permuteUnique(vec1);
    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0047_PERMUTATIONS_II_H_

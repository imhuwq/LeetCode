/*
 * 
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * Input: [1,2,2]
 * Output:
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 * 
 */

#ifndef LEET_CODE_0090_SUBSETSII_H_
#define LEET_CODE_0090_SUBSETSII_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0090 {
    class Solution {
    public:
        void subsetsWithDup(vector<int> &nums, int start, vector<int> &subset, vector<vector<int>> &subsets) {
            subsets.push_back(subset);
            for (int idx = start; idx < nums.size(); idx++) {
                if (idx > start && nums[idx] == nums[idx - 1]) continue;
                subset.push_back(nums[idx]);
                subsetsWithDup(nums, idx + 1, subset, subsets);
                subset.pop_back();
            }
        }

        vector<vector<int>> subsetsWithDup(vector<int> &nums) {
            vector<int> subset;
            vector<vector<int>> subsets;
            std::sort(nums.begin(), nums.end());
            subsetsWithDup(nums, 0, subset, subsets);
            return subsets;
        }
    };

}

TEST(L0090_SubsetsII, CASE_TEST) {
    using namespace L0090;
    Solution s;
    vector<int> vec = {1, 2, 2};
    s.subsetsWithDup(vec);
    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0090_SUBSETSII_H_

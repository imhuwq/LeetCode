/*
 * 
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * Example 1:
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 *   [1, 7],
 *   [1, 2, 5],
 *   [2, 6],
 *   [1, 1, 6]
 * ]
 * 
 * Example 2:
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 *   [1,2,2],
 *   [5]
 * ]
 * 
 */

#ifndef LEET_CODE_0040_COMBINATION_SUM_II_H_
#define LEET_CODE_0040_COMBINATION_SUM_II_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0040 {
    class Solution {
    public:
        void combinationSum2(vector<int> &candidates, int begin, int target, vector<int> &combination, vector<vector<int>> &combinations) {
            if (target == 0) {
                combinations.push_back(combination);
                return;
            }

            for (int idx = begin; idx < candidates.size(); idx++) {
                if (idx > begin && candidates[idx] == candidates[idx - 1]) continue;
                int candidate = candidates[idx];
                if (candidate > target) break;
                combination.push_back(candidate);
                combinationSum2(candidates, idx + 1, target - candidate, combination, combinations);
                combination.pop_back();
            }
        }

        vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
            std::sort(candidates.begin(), candidates.end());

            vector<int> combination;
            vector<vector<int>> combinations;
            combinationSum2(candidates, 0, target, combination, combinations);
            return combinations;
        }
    };

}

TEST(L0040_COMBINATION_SUM_II, CASE_TEST) {
    using namespace L0040;
    Solution s;

    vector<int> vec1 = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> ret1 = s.combinationSum2(vec1, 8);
    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0040_COMBINATION_SUM_II_H_

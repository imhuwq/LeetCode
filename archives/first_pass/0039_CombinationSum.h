/*
 * 
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
 * find all unique combinations in candidates where the candidate numbers sums to target.
 * The same repeated number may be chosen from candidates unlimited number of times.
 * 
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * Example 1:
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 *   [7],
 *   [2,2,3]
 * ]
 * 
 * Example 2:
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 *   [2,2,2,2],
 *   [2,3,3],
 *   [3,5]
 * ]
 * 
 */

#ifndef LEET_CODE_0039_COMBINATION_SUM_H_
#define LEET_CODE_0039_COMBINATION_SUM_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0039 {
    class Solution {
    public:
        static void PrintVector(vector<int> &vec) {
            for (auto n:vec) cout << n << " ";
            cout << endl;
        }

        void combinationSum(vector<int> &candidates, int begin, int target, vector<int> &combination, vector<vector<int>> &combinations) {
            if (target == 0) {
                combinations.push_back(combination);  // if target is 0, then combination is valid, add it to result and finish this search
                return;
            }

            // continues search with left candidates
            for (int idx = begin; idx < candidates.size(); idx++) {
                int candidate = candidates[idx];
                if ( candidate > target) break;  // no possible combinations since the smallest candidate is greater than target
                combination.push_back(candidate);  // add candidate to combination
                combinationSum(candidates, idx, target - candidate, combination, combinations); // search deeper for smaller target
                combination.pop_back();  // pop candidate, if the candidate is valid, it is added to result in deeper searchs
            }
        }

        vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
            std::sort(candidates.begin(), candidates.end());
            vector<vector<int>> combinations;
            vector<int> combination;
            combinationSum(candidates, 0, target, combination, combinations);
            return combinations;
        }
    };

}

TEST(L0039_COMBINATION_SUM, CASE_TEST) {
    using namespace L0039;
    Solution s;

    vector<int> qes1 = {2, 3, 5};
    vector<vector<int>> ans = s.combinationSum(qes1, 8);
    EXPECT_EQ(1, 1);
}

#endif //LEET_CODE_0039_COMBINATION_SUM_H_

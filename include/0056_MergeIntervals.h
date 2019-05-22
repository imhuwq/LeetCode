/*
 * 
 * Given a collection of intervals, merge all overlapping intervals.
 * Example 1:
 * Input: {{1,3},{2,6},{8,10},{15,18}}
 * Output: {{1,6},{8,10},{15,18}}
 * Explanation: Since intervals {1,3} and {2,6} overlaps, merge them into {1,6}.
 * 
 * Example 2:
 * Input: {{1,4},{4,5}}
 * Output: {{1,5}}
 * Explanation: Intervals {1,4} and {4,5} are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
 * 
 */

#ifndef LEET_CODE_0056_MERGEINTERVALS_H_
#define LEET_CODE_0056_MERGEINTERVALS_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0056 {
    class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>> &intervals) {
            if (intervals.empty()) return {};
            std::sort(intervals.begin(), intervals.end());
            vector<vector<int>> result;

            int left = intervals[0][0];
            int right = intervals[0][1];

            for (vector<int> &interval:intervals) {
                if (interval[0] > right) {
                    result.push_back({left, right});
                    left = interval[0];
                    right = interval[1];
                } else if (interval[0] == right) {
                    right = interval[1];
                } else if (interval[0] >= left) {
                    if (interval[1] > right) right = interval[1];
                }
            }

            result.push_back({left, right});
            return result;
        }
    };

}

TEST(L0056_MergeIntervals, CASE_TEST) {
    using namespace L0056;
    Solution s;

    vector<vector<int>> vec1 = {{1,  3},
                                {2,  6},
                                {8,  10},
                                {15, 18}};
    vector<vector<int>> ret1 = {{1,  6},
                                {8,  10},
                                {15, 18}};
    EXPECT_EQ(s.merge(vec1), ret1);

    vector<vector<int>> vec2 = {{1, 4},
                                {0, 1}};
    vector<vector<int>> ret2 = {{0, 4}};
    EXPECT_EQ(s.merge(vec2), ret2);
}

#endif //LEET_CODE_0056_MERGEINTERVALS_H_

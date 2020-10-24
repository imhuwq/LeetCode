/*
 * 
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always exist in the array.
 * Example 1:
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 */

#ifndef LEET_CODE_0169_MAJORITYELEMENT_H_
#define LEET_CODE_0169_MAJORITYELEMENT_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0169 {
    class Solution {
    public:
        int majorityElement(vector<int> &nums) {
            if (nums.empty()) return 0;

            int major = nums[0], count = 0;
            for (int num:nums) {
                if (count == 0) major = num;
                count += (num == major ? 1 : -1);
            }
            return major;
        }

        int majorityElement(vector<int> &&nums) {
            return majorityElement(nums);
        }
    };

}

TEST(L0169_MajorityElement, CASE_TEST) {
    using namespace L0169;
    Solution s;

    EXPECT_EQ(s.majorityElement({3, 2, 3}), 3);
    EXPECT_EQ(s.majorityElement({2, 2, 1, 1, 1, 2, 2}), 2);
}

#endif //LEET_CODE_0169_MAJORITYELEMENT_H_

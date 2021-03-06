/*
 * Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 *
 * Example 1:
 * Given nums = [1,1,2],
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the returned length.
 *
 * Example 2:
 * Given nums = [0,0,1,1,1,2,2,3,3,4],
 * Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
 * It doesn't matter what values are set beyond the returned length.
 */

#ifndef LEET_CODE_0022_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H_
#define LEET_CODE_0022_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H_

#include <stack>
#include <string>
#include <climits>
#include <gtest/gtest.h>

using namespace std;

namespace L0026 {
    class Solution {
    public:
        Solution() = default;

        int removeDuplicates(vector<int> &nums) {
            if (nums.size() <= 1) return nums.size();

            int num_duplicate = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == nums[i - 1]) num_duplicate++;
                else nums[i - num_duplicate] = nums[i];
            }
            return nums.size() - num_duplicate;
        }
    };
}


TEST(L0026_REMOVE_DUPLICATES_FROM_SORTED_ARRAY, CASE_TEST) {
    L0026::Solution s;

    vector<int> v1 = {1, 1, 2};
    vector<int> v2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    EXPECT_EQ(s.removeDuplicates(v1), 2);
    EXPECT_EQ(s.removeDuplicates(v2), 5);
}

#endif //LEET_CODE_0022_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H_

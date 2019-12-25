/*
 * 
 * Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 * Given nums = [1,1,1,2,2,3],
 * Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
 * It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * Given nums = [0,0,1,1,1,1,2,3,3],
 * Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
 * It doesn't matter what values are set beyond the returned length.
 * 
 * Clarification:
 * Confused why the returned value is an integer but your answer is an array?
 * Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
 * 
 * Internally you can think of this:
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 * 
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len elements.
 * for (int i = 0; i < len; i++) {
 *     print(nums[i]);
 * }
 * 
 */

#ifndef LEET_CODE_0080_REMOVEDUPLICATESFROMSORTEDARRAYII_H_
#define LEET_CODE_0080_REMOVEDUPLICATESFROMSORTEDARRAYII_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0080 {
    class Solution {
    public:
        int removeDuplicates(vector<int> &nums) {
            if (nums.size() <= 2) return nums.size();

            int cursor = 1;
            for (int idx = 2; idx < nums.size(); idx++) {
                if (nums[cursor] == nums[cursor - 1] && nums[idx] == nums[cursor]) continue;
                nums[++cursor] = nums[idx];
            }
            return cursor + 1;
        }
    };

}

TEST(L0080_RemoveDuplicatesfromSortedArrayII, CASE_TEST) {
    using namespace L0080;
    Solution s;

    vector<int> vec = {1, 1, 1, 2, 2, 3};
    vector<int> ans = {1, 1, 2, 2, 3, 3};
    int len = s.removeDuplicates(vec);
    EXPECT_EQ(len, 5);
    EXPECT_EQ(vec, ans);
}

#endif //LEET_CODE_0080_REMOVEDUPLICATESFROMSORTEDARRAYII_H_

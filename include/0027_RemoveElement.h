/*
 * Given an array nums and a value val, remove all instances of that value in-place and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * 
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 * 
 * Example 1:
 * Given nums = [3,2,2,3], val = 3,
 * Your function should return length = 2, with the first two elements of nums being 2.
 * It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * Given nums = [0,1,2,2,3,0,4,2], val = 2,
 * Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
 * Note that the order of those five elements can be arbitrary.
 */

#ifndef LEET_CODE_0027_REMOVE_ELEMENT_H_
#define LEET_CODE_0027_REMOVE_ELEMENT_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0027 {

    class Solution {
    public:
        int removeElement(vector<int> &nums, int val) {
            int pos = 0;
            int end = 0;
            while (pos < nums.size()) {
                if (nums[pos] != val) {
                    nums[end++] = nums[pos];
                }
                pos++;
            }
            return end;
        }
    };
}

TEST(L0027_REMOVE_ELEMENT, CASE_TEST) {
    L0027::Solution s;

    vector<int> nums1 = {3, 2, 2, 3};
    int len1 = s.removeElement(nums1, 3);
    EXPECT_EQ(len1, 2);

    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int len2 = s.removeElement(nums2, 2);
    EXPECT_EQ(len2, 5);

    vector<int> nums3 = {4, 5};
    int len3 = s.removeElement(nums3, 4);
    EXPECT_EQ(len3, 1);

    vector<int> nums4 = {1};
    int len4 = s.removeElement(nums4, 1);
    EXPECT_EQ(len4, 0);

    vector<int> nums5 = {3, 3};
    int len5 = s.removeElement(nums5, 3);
    EXPECT_EQ(len5, 0);

    vector<int> nums6 = {4, 5};
    int len6 = s.removeElement(nums6, 5);
    EXPECT_EQ(len6, 1);
}

#endif //LEET_CODE_0027_REMOVE_ELEMENT_H_

/*
 * 
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * Input: [2, 3, 1, 1, 4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Example 2:
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 */

#ifndef LEET_CODE_0055_JUMPGAME_H_
#define LEET_CODE_0055_JUMPGAME_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0055 {
    class Solution {
    public:
        bool canJump(vector<int> &nums, int from, int to) {
            if (from == to) return true;
            if (nums[from] + from >= to) return true;
            for (int middle = to - 1; middle > from; middle--) {
                on++;
                if (nums[middle] + middle >= to) return (canJump(nums, from, middle));
            }
            return false;
        }

        bool canJump(vector<int> &nums) {
            return canJump(nums, 0, nums.size() - 1);
        }
    };

}

TEST(L0055_JumpGame, CASE_TEST) {
    using namespace L0055;
    Solution s;

    vector<int> vec1 = {2, 3, 1, 1, 4};
    vector<int> vec2 = {3, 2, 1, 0, 4};
    EXPECT_TRUE(s.canJump(vec1));
    EXPECT_FALSE(s.canJump(vec2));
}

#endif //LEET_CODE_0055_JUMPGAME_H_

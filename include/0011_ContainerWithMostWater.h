/*
 * 
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines
 * are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
 * forms a container, such that the container contains the most water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * Example:
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * 
 */

#ifndef LEET_CODE_0011_CONTAINER_WITH_MOST_WATER_H_
#define LEET_CODE_0011_CONTAINER_WITH_MOST_WATER_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0011 {
    class Solution {
    public:
        int maxArea(vector<int> &height) {
            if (height.size() <= 1) return 0;
            int left = 0, right = height.size() - 1;
            int left_height = height[left];
            int right_height = height[right];
            int max_area = min(left_height, right_height) * (right - left);
            int tmp_area = 0;
            while (left < right - 1) {
                if (left_height <= right_height) {
                    left++;
                    left_height = height[left];
                } else {
                    right--;
                    right_height = height[right];
                }
                max_area = max(max_area, min(left_height, right_height)*  (right - left));
            }
            return max_area;
        }
    };

}

TEST(L0011_CONTAINER_WITH_MOST_WATER, CASE_TEST) {
    using namespace L0011;
    Solution s;

    vector<int> vec1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    EXPECT_EQ(s.maxArea(vec1), 49);
}

#endif //LEET_CODE_0011_CONTAINER_WITH_MOST_WATER_H_

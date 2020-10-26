/*
 * 
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 *              Not 7-1 = 6, as selling price needs to be larger than buying price.
 * 
 * Example 2:
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 */

#ifndef LEET_CODE_0121_BESTTIMETOBUYANDSELLSTOCK_H_
#define LEET_CODE_0121_BESTTIMETOBUYANDSELLSTOCK_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0121 {
    class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            if (prices.empty()) return 0;

            int lowest_price = prices[0];
            int max_profit = 0;

            for (int price : prices) {
                if (price < lowest_price) lowest_price = price;
                else max_profit = max(max_profit, price - lowest_price);
            }
            return max(max_profit, 0);
        }

        int maxProfit(vector<int> &&prices) {
            return maxProfit(prices);
        }
    };
}

TEST(L0121_BestTimetoBuyandSellStock, CASE_TEST) {
    using namespace L0121;
    Solution s;

    EXPECT_EQ(s.maxProfit(vector<int>({3, 2, 6, 5, 0, 3})), 4);
    EXPECT_EQ(s.maxProfit(vector<int>({7, 6, 4, 3, 1})), 0);
    EXPECT_EQ(s.maxProfit(vector<int>({7, 1, 5, 3, 6, 4})), 5);
    EXPECT_EQ(s.maxProfit(vector<int>({7, 4, 5, 3, 6, 4})), 3);
    EXPECT_EQ(s.maxProfit(vector<int>({7, 2, 7, 4, 7, 7})), 5);
    EXPECT_EQ(s.maxProfit(vector<int>({7, 6, 5, 4, 7, 7, 8, 10, 9})), 6);
    EXPECT_EQ(s.maxProfit(vector<int>({2, 6, 5, 4, 1, 7, 8, 10, 9})), 9);


}

#endif //LEET_CODE_0121_BESTTIMETOBUYANDSELLSTOCK_H_

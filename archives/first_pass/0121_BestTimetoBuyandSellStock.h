/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 *              Not 7-1 = 6, as selling price needs to be larger than buying price.
 *
 * Example 2:
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */

#ifndef LEET_CODE_0121_BEST_TIME_TO_BUY_AND_SELL_STOCK_H_
#define LEET_CODE_0121_BEST_TIME_TO_BUY_AND_SELL_STOCK_H_

#include <stack>
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
            if (prices.size() <= 1) return 0;

            int profit = 0;
            int lowPrice = prices[0];
            for (size_t i = 0; i < prices.size(); i++) {
                if (prices[i] < lowPrice) lowPrice = prices[i];
                else profit = max(profit, prices[i] - lowPrice);
            }
            return max(profit, 0);
        }
    };

}

TEST(L0121_BEST_TIME_TO_BUY_AND_SELL_STOCK, CASE_TEST) {
    using namespace L0121;
    Solution s;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    EXPECT_EQ(s.maxProfit(prices1), 5);

    vector<int> prices2 = {7, 6, 4, 3, 1};
    EXPECT_EQ(s.maxProfit(prices2), 0);
}

#endif //LEET_CODE_0121_BEST_TIME_TO_BUY_AND_SELL_STOCK_H_

/*
 * Say you have an array for which the i-th element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 * 
 * Example 1:
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
 *              Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
 *              
 * Example 2:
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 *              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
 *              engaging multiple transactions at the same time. You must sell before buying again.
 *              
 * Example 3:
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */

#ifndef LEET_CODE_0122_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_H_
#define LEET_CODE_0122_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0122 {

    class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            if (prices.size() <= 1) return 0;
            int profit = 0;
            int buyPrice = prices[0];
            int lastPrice = prices[0];
            for (size_t i = 1; i < prices.size(); i++) {
                if (prices[i] < lastPrice) {
                    profit += (lastPrice - buyPrice);
                    buyPrice = prices[i];
                }
                lastPrice = prices[i];
            }
            return profit + (lastPrice - buyPrice);
        }
    };

}

TEST(L0122_BEST_TIME_TO_BUY_AND_SELL_STOCK_II, CASE_TEST) {
    using namespace L0122;
    Solution s;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4, 6, 1};
    vector<int> prices2 = {1, 2, 3, 4, 5};
    vector<int> prices3 = {7, 6, 4, 3, 1};

    EXPECT_EQ(s.maxProfit(prices1), 9);
    EXPECT_EQ(s.maxProfit(prices2), 4);
    EXPECT_EQ(s.maxProfit(prices3), 0);
}

#endif //LEET_CODE_0122_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_H_

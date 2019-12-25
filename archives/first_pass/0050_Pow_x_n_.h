/*
 * 
 * Implement pow(x, n), which calculates x raised to the power n (x**n).
 * 
 * Example 1:
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * Example 2:
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * Example 3:
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2**-2 = 1/2**2 = 1/4 = 0.25
 * 
 * Note:
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2**31, 2**31 − 1]
 * 
 */

#ifndef LEET_CODE_0050_POW_X__N__H_
#define LEET_CODE_0050_POW_X__N__H_

#include <stack>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0050 {
    class Solution {
    public:
        double myPow(double x, int n) {
            if (n == 0) return 1;

            bool reverse = false;
            if (n < 0) reverse = true;

            double result = 1;
            for (int i = n; i; i /=2 ) {
                if (i & 1) result *= x;
                x *= x;
            }
            // 以上实际上把 n 拆解成了若干个 2 的 m 次方幂的和
            // 即 result = x**p * x**q * ... x**k * x**m = x**(p+q+...+k+m) 且 p+q+...+k+m = n, p,q...k,m 都是 2 的幂
            // 为什么会这样？
            // 我们先假设 m = i * k, i 初始值为 1,k 为 m, 意为 m 由 k 个 i 组成。
            // 然后我们把 k 除以 2，i 的值乘以 2，意为 m 由 k/2 个 2i 组成。
            // 如果 k 恰好为 2 的倍数的话，这个过程可以平滑过渡。但是如果 k 为奇数的话，k/2 个 2i 比之前少了一个 i
            // 也就是说当 k 为奇数时，m 由 1 个 i 和 k/2 个 2i 组成。
            // 所以在上面的循环中，当 i 为奇数时，要把将遗失的那单个 “i” 保存起来。

            result = reverse ? 1.0 / result : result;
            return result;
        }
    };

}

TEST(L0050_POW_X__N_, CASE_TEST) {
    using namespace L0050;
    Solution s;

    EXPECT_DOUBLE_EQ(s.myPow(2.0, 10), 1024.0);
    EXPECT_DOUBLE_EQ(s.myPow(2.1, 3), 9.261);
}

#endif //LEET_CODE_0050_POW_X__N__H_

/*
 * 
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * Note:
 * Note that in some languages such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
 * In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.
 * Follow up:
 * 
 * If this function is called many times, how would you optimize it?
 * 
 * 
 * Example 1:
 * Input: n = 00000010100101000001111010011100
 * Output:    964176192 (00111001011110000010100101000000)
 * Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
 * 
 * Example 2:
 * Input: n = 11111111111111111111111111111101
 * Output:   3221225471 (10111111111111111111111111111111)
 * Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.
 * 
 * Constraints:
 * The input must be a binary string of length 32
 * 
 */

#ifndef LEET_CODE_0190_REVERSEBITS_H_
#define LEET_CODE_0190_REVERSEBITS_H_

#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

namespace L0190 {
    class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            n = (n >> 16) | (n << 16);
            n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
            n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
            n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
            n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
            return n;
        }
    };

}

TEST(L0190_ReverseBits, CASE_TEST) {
    using namespace L0190;
    Solution s;

    EXPECT_EQ(s.reverseBits(0b00000000000000000000000000000001), 0b10000000000000000000000000000000);
    EXPECT_EQ(s.reverseBits(0b00000010100101000001111010011100), 0b00111001011110000010100101000000);
}

#endif //LEET_CODE_0190_REVERSEBITS_H_

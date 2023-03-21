/*************************************************
Author: wenhaofang
Date: 2023-03-21
Description: leetcode461 - Hamming Distance
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：位运算
 */

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int c = 0;
        while (z) {
            z &= (z - 1); // 消除最后一个 1
            c++;
        }
        return c;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int x = 1;
    int y = 4;
    int ans = solution -> hammingDistance(x, y);
    cout << ans << endl;
}
/*************************************************
Author: wenhaofang
Date: 2023-03-21
Description: leetcode279 - Perfect Squares
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：动态规划
 * 
 * 理论时间复杂度：O(n * sqrt(n))，其中 n 为数字大小
 * 理论空间复杂度：O(n)          ，其中 n 为数字大小
 */

class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for (int i = 1; i <= sqrt(n); i++) {
            nums.push_back(i * i);
        }
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int num: nums) {
                if (num <= i) {
                    dp[i] = min(dp[i], dp[i - num] + 1);
                }
            }
        }
        return dp[n];
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int n = 12;
    int ans = solution -> numSquares(n);
    cout << ans << endl;
}
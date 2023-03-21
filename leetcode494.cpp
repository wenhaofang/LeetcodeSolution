/*************************************************
Author: wenhaofang
Date: 2023-03-21
Description: leetcode494 - Target Sum
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：深度优先搜索
 * 
 * 理论时间复杂度：O(2^n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)  ，其中 n 为数组大小
 */

// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         return dfs(nums, target, 0, 0);
//     }

//     int dfs(vector<int>& nums, int target, int curIdx, int curSum) {
//         if (curIdx == nums.size()) {
//             return curSum == target ? 1 : 0;
//         }
//         return (
//             dfs(nums, target, curIdx + 1, curSum + nums[curIdx]) +
//             dfs(nums, target, curIdx + 1, curSum - nums[curIdx])
//         );
//     }
// };

/**
 * 方法二：转换 + 动态规划
 * 
 * 理论时间复杂度：O(n * x)，其中 n 为数组大小，x 为 (target + sum(nums)) / 2
 * 理论空间复杂度：O(n * x)，其中 n 为数组大小，x 为 (target + sum(nums)) / 2
 */
/**
 * 思路
 * 
 * 问题可转换为：找出数组中一个正子集 P、一个负子集 N，使得总和等于 target
 * 
 * 即 sum(P) - sum(N) = target
 * 
 * 有 sum(P) - sum(N) + sum(P) + sum(N) = target + sum(P) + sum(N)
 * 
 * 有 sum(P) * 2  = target + sum(nums) // 注意 target + sum(nums) 一定是正偶数
 * 
 * 问题可转换为：数组中存在多少正子集 P，使得 sum(P) = (target + sum(nums)) / 2，也即 0-1 背包问题
 */

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + target) % 2 != 0) {
            return 0;
        }
        if ((sum + target) < 0) {
            return 0;
        }
        // dp[i][j] 表示 nums[0..i] 中和为 j 的有多少
        int m = nums.size();
        int n = (sum + target) / 2;
        vector<vector<int>> dp(m, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int j = 0; j <= n; j++) {
            if (nums[0] == j) {
                dp[0][j] += 1;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j <= n; j++) {
                if (nums[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp[m - 1][n];
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int ans = solution -> findTargetSumWays(nums, target);
    cout << ans << endl;
}
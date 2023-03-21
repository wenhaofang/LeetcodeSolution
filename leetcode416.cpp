/*************************************************
Author: wenhaofang
Date: 2023-03-21
Description: leetcode416 - Partition Equal Subset Sum
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：转换 + 深度优先搜索
 * 
 * 理论时间复杂度：O(2^n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)  ，其中 n 为数组大小
 */
/**
 * 思路
 * 
 * 转换：在数组中选出一个子集，使得和为 sum(nums) / 2
 * 
 * 每个元素有选与不选两种状态
*/

// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         if (sum % 2 != 0) {
//             return false;
//         }
//         return dfs(nums, sum / 2, 0, 0);
//     }

//     bool dfs(vector<int>& nums, int allSum, int i, int curSum) {
//         if (curSum == allSum) {
//             return true;
//         }
//         if (curSum > allSum) {
//             return false;
//         }
//         if (i == nums.size()) {
//             return false;
//         }
//         return (
//             dfs(nums, allSum, i + 1, curSum) ||
//             dfs(nums, allSum, i + 1, curSum + nums[i])
//         );
//     }
// };

/**
 * 方法二：转换 + 动态规划
 * 
 * 理论时间复杂度：O(n * x)，其中 n 为数组大小、x 为 sum(nums) / 2
 * 理论空间复杂度：O(n * x)，其中 n 为数组大小、x 为 sum(nums) / 2
 */
/**
 * 思路
 * 
 * 转换：在数组中选出一个子集，使得和为 sum(nums) / 2，也即 0-1 背包问题
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        // dp[i][j] 表示 nums[0..i] 中和为 j 的有多少
        int m = nums.size();
        int n = sum / 2;
        vector<vector<bool>> dp(m, vector<bool>(n + 1, false));
        dp[0][0] = true; // 不选
        for (int j = 0; j <= n; j++) {
            if (nums[0] == j) { // 选
                dp[0][j] = true;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j <= n; j++) {
                if (nums[i] > j) {
                    dp[i][j] = dp[i - 1][j]; // 不选
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]]; // 不选 || 选
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
    vector<int> nums = {1, 5, 11, 5};
    bool ans = solution -> canPartition(nums);
    cout << ans << endl;
}
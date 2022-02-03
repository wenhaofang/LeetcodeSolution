/*************************************************
Author: wenhaofang
Date: 2022-02-07
Description: leetcode64 - Minimum Path Sum
*************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>

using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::stack;
using std::queue;
using std::priority_queue;
using std::max;
using std::min;
using std::swap;
using std::pair;
using std::cin;
using std::cout;
using std::endl;

/**
 * 方法一：动态规划
 * 
 * 理论时间复杂度：O(mn)
 * 理论空间复杂度：O(mn)
 * 
 * 实际时间复杂度：Runtime: 8 ms, faster than 88.21% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 10 MB, less than 50.07% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 设置二维 dp 数组，dp[i][j] 表示从 (0, 0) 到坐标 (i, j) 的值
 * 
 * 状态转移方程为：dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
 * 
 * 备注：能使用动态规划的问题，需要满足以下两个条件
 * 
 *        重叠子问题：一个大问题的解包含小问题的解
 * 
 *        最优子结构：一个大问题的最优解包含小问题的最优解，一般目标函数具有单调性都可以考虑，如求最大或最小值
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 确定边界
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        // 逐步填表
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        // 读取结果
        return dp[m - 1][n - 1];
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    int ans = solution -> minPathSum(grid);
    cout << ans << endl;
}
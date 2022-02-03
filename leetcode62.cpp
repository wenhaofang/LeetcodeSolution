/*************************************************
Author: wenhaofang
Date: 2022-02-05
Description: leetcode62 - Unique Paths
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
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.6 MB, less than 24.09% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 设置二维 dp 数组，dp[i][j] 表示从起点走到坐标 (i, j) 的路径数量
 * 
 * 状态转移方程为：dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
 */
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         // 确定边界
//         for (int i = 0; i < m; i++) {
//             dp[i][0] = 1;
//         }
//         for (int j = 0; j < n; j++) {
//             dp[0][j] = 1;
//         }
//         // 逐步填表
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         // 读取结果
//         return dp[m - 1][n - 1];
//     }
// };

/**
 * 方法二：动态规划 + 滚动数组
 * 
 * 理论时间复杂度：O(mn)
 * 理论空间复杂度：O(min(m, n))
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.6 MB, less than 24.09% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 在填表过程中，当前要计算的值只跟左边和上边的值相关
 * 
 * 所以动态规划数组只需一个维度即可
 */
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<int> dp(n);
//         // 确定边界
//         for (int j = 0; j < n; j++) {
//             dp[j] = 1;
//         }
//         // 逐步填表
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 dp[j] = dp[j] + dp[j - 1];
//             }
//         }
//         // 读取结果
//         return dp[n - 1];
//     }
// };

/**
 * 方法三：数学方法
 * 
 * 理论时间复杂度：O(min(m, n))
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6 MB, less than 69.89% of C++ online submissions
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 计算初始值
        // int p = m - 1 + n - 1; // 到达目标要走 p 步
        // int q = min(m, n) - 1; // 向右或向下走 q 步
        // 计算组合数
        // C(p, q) = p! / [ q! · (p - q)! ]
        //         = (m + n - 2)! / [ (m - 1)! · (n - 1)! ]
        // 例子找规律
        // 如果 m = 7、n = 3，那么 C = (8 * 7) / (2 * 1)
        // 如果 m = 5、n = 5，那么 C = (8 * 7 * 6 * 5) / (4 * 3 * 2 * 1)
        long long int ans = 1;
        // 错误计算方法：因为分母无法整除，所以产生计算误差
        // 例子一：C = (8 * 7) / (2 * 1) = (8 / 2) * (7 / 1)
        // 例子二：C = (8 * 7 * 6 * 5) / (4 * 3 * 2 * 1) = (8 / 4) * (7 / 3) * (6 / 2) * (5 / 1)
        // for (int x = m + n - 2, y = min(m - 1, n - 1); y > 0; x--, y--) {
        //     ans = ans * x / y;
        // }
        // 正确计算方法
        // 例子一：C = (8 * 7) / (2 * 1) = (7 / 1) * (8 / 2)
        // 例子二：C = (8 * 7 * 6 * 5) / (4 * 3 * 2 * 1) = (5 / 1) * (6 / 2) * (7 / 3) * (8 / 4)
        for (int x = max(m, n), y = 1; y < min(m, n); x++, y++) {
            ans = ans * x / y;
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int m = 3;
    int n = 7;
    int ans = solution -> uniquePaths(m, n);
    cout << ans << endl;
}
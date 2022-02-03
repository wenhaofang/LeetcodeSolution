/*************************************************
Author: wenhaofang
Date: 2022-02-06
Description: leetcode63 - Unique Paths II
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
 * 实际时间复杂度：Runtime: 3 ms, faster than 77.73% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7.9 MB, less than 11.43% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 与上一题解题的思路基本一致，只是在填充数组时增加障碍判断
 */
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         // 确定边界
//         if (
//             obstacleGrid[0][0] == 1 ||
//             obstacleGrid[m - 1][n - 1] == 1 // 剪枝
//         ) {
//             return 0;
//         } else {
//             dp[0][0] = 1;
//         }
//         for (int i = 1; i < m; i++) {
//             if (obstacleGrid[i][0] == 0) {
//                 dp[i][0] = 1;
//             } else break; // 剪枝
//         }
//         for (int j = 1; j < n; j++) {
//             if (obstacleGrid[0][j] == 0) {
//                 dp[0][j] = 1;
//             } else break; // 剪枝
//         }
//         // 逐步填表
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 if (obstacleGrid[i][j] == 1) {
//                     dp[i][j] = 0;
//                 } else {
//                     dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//                 }
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
 * 实际空间复杂度：Memory Usage: 7.6 MB, less than 68.88% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 在填表过程中，当前要计算的值只跟左边和上边的值相关
 * 
 * 所以动态规划数组只需一个维度即可
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n);
        // 确定边界
        dp[0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        // 逐步填表
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j >= 1) {
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        // 读取结果
        return dp[n - 1];
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    int ans = solution -> uniquePathsWithObstacles(obstacleGrid);
    cout << ans << endl;
}
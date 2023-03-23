/*************************************************
Author: wenhaofang
Date: 2023-03-23
Description: leetcode221 - Maximal Square
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：动态规划
 * 
 * 理论时间复杂度：O(mn)，其中 m、n 分别为数组行数和列数
 * 理论空间复杂度：O(mn)，其中 m、n 分别为数组行数和列数
 */

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // dp[i][j] 表示从 (0, 0) 到 (i, j) 的矩阵中只包含 1 的最大正方形
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
            }
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == '1') {
                dp[0][j] = 1;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != '1') {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    int ans = solution -> maximalSquare(matrix);
    cout << ans << endl;
}
/*************************************************
Author: wenhaofang
Date: 2023-05-07
Description: leetcode304 - Range Sum Query 2D - Immutable
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：前缀和
 * 
 * 理论时间复杂度：
 * 理论空间复杂度：
 */

class NumMatrix {
public:
    vector<vector<int>> sums;

    NumMatrix(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        sums.resize(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + nums[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1];
    }
};

/**
 * 测试
 */
int main() {

}
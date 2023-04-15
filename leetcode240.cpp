/*************************************************
Author: wenhaofang
Date: 2023-04-15
Description: leetcode240 - Search a 2D Matrix II
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：二分查找
 * 
 * 理论时间复杂度：
 * 理论空间复杂度：O(1)
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        return recursive(matrix, target, 0, 0, m - 1, n - 1);
    }

    bool recursive(vector<vector<int>>& matrix, int target, int x1, int y1, int x2, int y2) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (
            x1 < 0 || x1 >= m ||
            x2 < 0 || x2 >= m ||
            y1 < 0 || y1 >= n ||
            y2 < 0 || y2 >= n ||
            x1 > x2 ||
            y1 > y2
        ) {
            return false;
        }
        int xm = (x1 + x2) / 2;
        int ym = (y1 + y2) / 2;
        if (matrix[xm][ym] == target) {
            return true;
        }
        else if (matrix[xm][ym] > target) {
            return (
                recursive(matrix, target, xm, y1, x2, ym - 1) ||
                recursive(matrix, target, x1, y1, xm - 1, y2)
            );
        }
        else if (matrix[xm][ym] < target) {
            return (
                recursive(matrix, target, x1, ym + 1, xm, y2) ||
                recursive(matrix, target, xm + 1, y1, x2, y2)
            );
        }
        return false;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<vector<int>> matrix = {
        {1 , 4 , 7 , 11, 15},
        {2 , 5 , 8 , 12, 19},
        {3 , 6 , 9 , 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;
    bool ans = solution -> searchMatrix(matrix, target);
    cout << ans << endl;
}
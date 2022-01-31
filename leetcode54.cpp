/*************************************************
Author: wenhaofang
Date: 2022-01-28
Description: leetcode54 - Spiral Matrix
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
 * 方法一：暴力模拟
 * 
 * 理论时间复杂度：O(mn)，其中 m、n 分别为数组行数和列数
 * 理论空间复杂度：O(mn)，其中 m、n 分别为数组行数和列数
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7 MB, less than 29.74% of C++ online submissions
 */
// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         // 特判
//         if (
//             matrix.size() == 0 ||
//             matrix[0].size() == 0
//         ) {
//             return {};
//         }
//         // 处理
//         int rowNum = matrix.size();    // 矩阵行数
//         int colNum = matrix[0].size(); // 矩阵列数
//         vector<vector<bool>> visited(rowNum, vector<bool>(colNum, false));    // 元素是否已被遍历
//         vector<vector< int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 方向变换顺序，可减少代码量
//         vector<int> ans(rowNum * colNum); // 答案
//         int curRow = 0;       // 当前行数
//         int curCol = 0;       // 当前列数
//         int curDirection = 0; // 当前方向
//         for (int i = 0; i < rowNum * colNum; i++) {
//             ans[i] = matrix[curRow][curCol];
//             visited[curRow][curCol] = true ;
//             int nextRow = curRow + directions[curDirection][0];
//             int nextCol = curCol + directions[curDirection][1];
//             if (
//                 nextRow < 0 ||
//                 nextCol < 0 ||
//                 nextRow >= rowNum ||
//                 nextCol >= colNum ||
//                 visited[nextRow][nextCol] == true
//             ) {
//                 curDirection = (curDirection + 1) % 4;
//             }
//             curRow = curRow + directions[curDirection][0];
//             curCol = curCol + directions[curDirection][1];
//         }
//         return ans;
//     }
// };

/**
 * 方法二：暴力模拟
 * 
 * 理论时间复杂度：O(mn)，其中 m、n 分别为数组行数和列数
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.8 MB, less than 92.71% of C++ online submissions
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 特判
        if (
            matrix.size() == 0 ||
            matrix[0].size() == 0
        ) {
            return {};
        }
        // 处理
        int rowNum = matrix.size();    // 矩阵行数
        int colNum = matrix[0].size(); // 矩阵列数
        int l = 0;          // 左
        int t = 0;          // 上
        int r = colNum - 1; // 右
        int b = rowNum - 1; // 下
        int k = rowNum * colNum;
        vector<int> ans;
        while (k >= 1) {
            for (int i = l; i <= r && k >= 1; i++) {
                ans.emplace_back(matrix[t][i]);
                k--;
            }
            t++;
            for (int i = t; i <= b && k >= 1; i++) {
                ans.emplace_back(matrix[i][r]);
                k--;
            }
            r--;
            for (int i = r; i >= l && k >= 1; i--) {
                ans.emplace_back(matrix[b][i]);
                k--;
            }
            b--;
            for (int i = b; i >= t && k >= 1; i--) {
                ans.emplace_back(matrix[i][l]);
                k--;
            }
            l++;
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<vector<int>> matrix = {
        {1, 2 , 3 , 4 },
        {5, 6 , 7 , 8 },
        {9, 10, 11, 12}
    };
    vector<int> ans = solution -> spiralOrder(matrix);
    for (auto item: ans) {
        cout << item << " ";
    }
}
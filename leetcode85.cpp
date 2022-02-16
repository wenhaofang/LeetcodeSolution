/*************************************************
Author: wenhaofang
Date: 2022-02-26
Description: leetcode85 - Maximal Rectangle
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
 * 理论时间复杂度：O(m * n * n)，其中 m、n 分别为矩阵的长和宽
 * 理论空间复杂度：O(m * n)，其中 m、n 分别为矩阵的长和宽
 * 
 * 实际时间复杂度：Runtime: 110 ms, faster than 19.54% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 12.9 MB, less than 82.58% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 本来是逐一枚举矩阵左上角和右下角，判断是否符合要求
 * 
 * 现在是先预处理原矩阵构造累加矩阵，再逐一枚举矩阵的右下角
 */
// class Solution {
// public:
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         // 累加矩阵
//         vector<vector<int>> heights(m, vector<int>(n, 0));
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (matrix[i][j] == '1') {
//                     heights[i][j] = i == 0 ? 1 : heights[i - 1][j] + 1;
//                 }
//             }
//         }
//         // 枚举
//         int ans = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (matrix[i][j] == '1') {
//                     int width = 1;
//                     int height = heights[i][j];
//                     int area = width * height;
//                     for (int k = j - 1; k >= 0; k--) {
//                         width = j - k + 1;
//                         height = min(height, heights[i][k]);
//                         area = max(area, width * height);
//                     }
//                     ans = max(ans, area);
//                 }
//             }
//         }
//         return ans;
//     }
// };

/**
 * 方法二：单调栈
 * 
 * 理论时间复杂度：O(m * n)，其中 m、n 分别为矩阵的长和宽
 * 理论空间复杂度：O(m * n)，其中 m、n 分别为矩阵的长和宽
 * 
 * 实际时间复杂度：Runtime: 44 ms, faster than 82.08% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 15.7 MB, less than 29.80% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 遍历每行，构造高度数组，转化为 leetcode84 的问题
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 累加矩阵
        vector<vector<int>> heights(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[i][j] = i == 0 ? 1 : heights[i - 1][j] + 1;
                }
            }
        }
        // 高度数组
        int tmp = 0;
        int ans = 0;
        for (int i = 0; i < m; i++) {
            tmp = largestRectangleArea(heights[i]);
            ans = max(ans, tmp);
        }
        return ans;
    }

    // leetcode84
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // 同时计算每个高度左右边界
        vector<int> l_vec(n, 0); // 储存左边界的数组
        vector<int> r_vec(n, n); // 储存右边界的数组
        stack <int> stk;         // 单调栈
        for (int i = 0; i < n; i++) {
            while (
                !stk.empty() &&
                heights[stk.top()] >= heights[i]
            ) {
                // 在出栈时确定右边界
                r_vec[stk.top()] = i;
                stk.pop();
            }
            l_vec[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        // 答案
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, (r_vec[i] - l_vec[i] - 1) * heights[i]);
        }
        return ans;
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
    int ans = solution -> maximalRectangle(matrix);
    cout << ans << endl;
}
/*************************************************
Author: wenhaofang
Date: 2022-02-16
Description: leetcode73 - Set Matrix Zeroes
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
 * 方法一：暴力模拟（使用标记数组）
 * 
 * 理论时间复杂度：O(m * n)，其中 m、n 分别为矩阵的长和宽
 * 理论空间复杂度：O(m + n)，其中 m、n 分别为矩阵的长和宽
 * 
 * 实际时间复杂度：Runtime: 25 ms, faster than 30.47% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 13.3 MB, less than 53.73% of C++ online submissions
 */
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         // 设置标志
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<bool> rowTag(m, false); // 行标志
//         vector<bool> colTag(n, false); // 列标志
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (matrix[i][j] == 0) {
//                     rowTag[i] = true;
//                     colTag[j] = true;
//                 }
//             }
//         }
//         // 修改矩阵
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (rowTag[i] || colTag[j]) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }
// };

/**
 * 方法二：暴力模拟（使用标记变量）
 * 
 * 理论时间复杂度：O(m * n)，其中 m、n 分别为矩阵的长和宽
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 24 ms, faster than 33.64% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 13.1 MB, less than 81.98% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 将矩阵的第一行和第一列作为上面所说的行标志和列标志
 * 
 * 在这种情况下，需要用额外两个变量保存第一行和第一列的情况
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 设置标志
        int m = matrix.size();
        int n = matrix[0].size();
        bool row0Tag = false; // 第一行变量标志
        bool col0Tag = false; // 第一列变量标志
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                row0Tag = true;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                col0Tag = true;
                break;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // 行标志
                    matrix[0][j] = 0; // 列标志
                }
            }
        }
        // 修改矩阵
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (
                    matrix[i][0] == 0 ||
                    matrix[0][j] == 0
                ) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row0Tag) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (col0Tag) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };
    solution -> setZeroes(matrix);
    for (vector<vector<int>>::iterator outer_iter = matrix.begin(); outer_iter != matrix.end(); outer_iter++) {
        for (vector<int>::iterator inner_iter = (*outer_iter).begin(); inner_iter != (*outer_iter).end(); inner_iter++) {
            cout << (*inner_iter) << " ";
        }
        cout << "\n";
    }
}
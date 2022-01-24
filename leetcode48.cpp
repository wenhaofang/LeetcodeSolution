/*************************************************
Author: wenhaofang
Date: 2022-01-24
Description: leetcode48 - Rotate Image
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
 * 方法一：找规律
 * 
 * 理论时间复杂度：O(n^2)，其中 n 为矩阵边长
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7 MB, less than 73.59% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 观察发现，矩阵中四个值的旋转可以归为一组：
 * 
 * 1. matrix[i][j] = matrix[n - j - 1][i];
 * 2. matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
 * 3. matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
 * 4. matrix[j][n - i - 1] = matrix[i][j];
 * 
 * 那么下一个问题自然就是应该把哪些位置作为初始点呢？
 * 
 * 1. 若 n 为偶数，则需枚举    n    / 2 行    n    / 2 列
 * 2. 若 n 为奇数，则需枚举 (n − 1) / 2 行 (n + 1) / 2 列
 * -> 综上所述，n / 2 行 (n + 1) / 2 列
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
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
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    solution -> rotate(matrix);
    for (vector<vector<int>>::iterator outer_iter = matrix.begin(); outer_iter != matrix.end(); outer_iter++) {
        for (vector<int>::iterator inner_iter = (*outer_iter).begin(); inner_iter != (*outer_iter).end(); inner_iter++) {
            cout << (*inner_iter) << " ";
        }
        cout << "\n";
    }
}
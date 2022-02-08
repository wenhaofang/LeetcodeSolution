/*************************************************
Author: wenhaofang
Date: 2022-02-17
Description: leetcode74 - Search a 2D Matrix
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
 * 方法一：二分查找
 * 
 * 理论时间复杂度：O(log(mn))，其中 m、n 分别为矩阵的长和宽
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 3 ms, faster than 84.86% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 9.6 MB, less than 52.05% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 将矩阵扁平化之后就是一维数组，可以使用二分查找的思路
 * 
 * 只不过需要多一步将向量索引转成矩阵索引
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int p1 = 0;
        int p2 = m * n - 1;
        while (p1 <= p2) {
            int mid = p1 + (p2 - p1) / 2;
            int val = matrix[mid / n][mid % n]; // 将向量索引转成矩阵索引
            if (val == target) {
                return true;
            } else if (val < target) {
                p1 = mid + 1;
            } else if (val > target) {
                p2 = mid - 1;
            }
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
        { 1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 13;
    bool ans = solution -> searchMatrix(matrix, target);
    cout << ans << endl;
}
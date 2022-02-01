/*************************************************
Author: wenhaofang
Date: 2022-02-02
Description: leetcode59 - Spiral Matrix II
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
 * 理论时间复杂度：O(n^2)，其中 n 为数组行数和列数
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.5 MB, less than 63.96% of C++ online submissions
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int l = 0;     // 左
        int t = 0;     // 上
        int r = n - 1; // 右
        int b = n - 1; // 下
        int k = 1;
        int m = n * n;
        while (k <= m) {
            for (int i = l; i <= r && k <= m; i++) {
                ans[t][i] = k;
                k++;
            }
            t++;
            for (int i = t; i <= b && k <= m; i++) {
                ans[i][r] = k;
                k++;
            }
            r--;
            for (int i = r; i >= l && k <= m; i--) {
                ans[b][i] = k;
                k++;
            }
            b--;
            for (int i = b; i >= t && k <= m; i--) {
                ans[i][l] = k;
                k++;
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
    int n = 3;
    vector<vector<int>> ans = solution -> generateMatrix(n);
    for (vector<vector<int>>::iterator outer_iter = ans.begin(); outer_iter != ans.end(); outer_iter++) {
        for (vector<int>::iterator inner_iter = (*outer_iter).begin(); inner_iter != (*outer_iter).end(); inner_iter++) {
            cout << (*inner_iter) << " ";
        }
        cout << "\n";
    }
}
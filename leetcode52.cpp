/*************************************************
Author: wenhaofang
Date: 2021-06-24
Description: leetcode52 - N-Queens II
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
using std::pair;
using std::cin;
using std::cout;
using std::endl;

/**
 * 方法一：回溯 + 哈希映射
 * 
 * 理论时间复杂度：O(N!)，其中 N 为皇后数量
 * 理论空间复杂度：O(N)，其中 N 为皇后数量
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6 MB, less than 68.65% of C++ online submissions
 */
class Solution {
public:
    int totalNQueens(int n) {
        bool* row = new bool[n]();
        bool* col = new bool[n]();
        bool* slash1 = new bool[2 * n - 1]();
        bool* slash2 = new bool[2 * n - 1]();
        vector<string> cur;
        for (int i = 0; i < n; i++) {
            cur.push_back(string(n, '.'));
        }
        int ans = backtrack(cur, 0, n, row, col, slash1, slash2);
        return ans;
    }

    int backtrack(
        vector<string>& cur,
        int r,
        int n,
        bool* row,
        bool* col,
        bool* slash1,
        bool* slash2
    ) {
        if (r == n) {
            return 1;
        }

        int count = 0;
        for (int c = 0; c < n; c++) {
            if (
                row[r] == true ||
                col[c] == true ||
                slash1[r + c] == true ||
                slash2[r - c + n - 1] == true
            ) {
                continue;
            }
            cur[r][c] = 'Q';
            row[r] = true;
            col[c] = true;
            slash1[r + c] = true;
            slash2[r - c + n - 1] = true;
            count += backtrack(cur, r + 1, n, row, col, slash1, slash2);
            cur[r][c] = '.';
            row[r] = false;
            col[c] = false;
            slash1[r + c] = false;
            slash2[r - c + n - 1] = false;
        }
        return count;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int n = 4;
    int ans = solution -> totalNQueens(n);
    cout << ans << endl;
}
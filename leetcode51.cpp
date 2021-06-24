/*************************************************
Author: wenhaofang
Date: 2021-06-23
Description: leetcode51 - N-Queens
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
 * 方法一：回溯
 * 
 * 理论时间复杂度：O(N!)，其中 N 为皇后数量
 * 理论空间复杂度：O(N)，其中 N 为皇后数量
 * 
 * 实际时间复杂度：Runtime: 8 ms, faster than 64.40% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7.2 MB, less than 77.08% of C++ online submissions
 */
// class Solution {
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> cur;
//         for (int i = 0; i < n; i++) {
//             cur.push_back(string(n, '.'));
//         }
//         backtrack(ans, cur, 0, n);
//         return ans;
//     }

//     void backtrack(
//         vector<vector<string>>& ans,
//         vector<string>& cur,
//         int r,
//         int n
//     ) {
//         if (r == n) {
//             ans.push_back(cur);
//             return;
//         }

//         for (int c = 0; c < n; c++) {
//             if (!isValid(cur, r, c, n)) {
//                 continue;
//             }
//             cur[r][c] = 'Q';
//             backtrack(ans, cur, r + 1, n);
//             cur[r][c] = '.';
//         }
//     }

//     bool isValid(
//         vector<string>& cur,
//         int i,
//         int j,
//         int n
//     ) {
//         for (int k = 0; k < n; k++){
//             if (cur[i][k] == 'Q') return false;
//             if (cur[k][j] == 'Q') return false;
//             if (i + k < n && j + k < n && cur[i + k][j + k] == 'Q') return false;
//             if (i + k < n && j - k >= 0 && cur[i + k][j - k] == 'Q') return false;
//             if (i - k >= 0 && j + k < n && cur[i - k][j + k] == 'Q') return false;
//             if (i - k >= 0 && j - k >= 0 && cur[i - k][j - k] == 'Q') return false;
//         }
//         return true;
//     }
// };

/**
 * 方法二：回溯 + 哈希映射
 * 
 * 理论时间复杂度：O(N!)，其中 N 为皇后数量
 * 理论空间复杂度：O(N)，其中 N 为皇后数量
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7.2 MB, less than 77.08% of C++ online submissions
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        bool* row = new bool[n]();
        bool* col = new bool[n]();
        bool* slash1 = new bool[2 * n - 1]();
        bool* slash2 = new bool[2 * n - 1]();
        vector<vector<string>> ans;
        vector<string> cur;
        for (int i = 0; i < n; i++) {
            cur.push_back(string(n, '.'));
        }
        backtrack(ans, cur, 0, n, row, col, slash1, slash2);
        return ans;
    }

    void backtrack(
        vector<vector<string>>& ans,
        vector<string>& cur,
        int r,
        int n,
        bool* row,
        bool* col,
        bool* slash1,
        bool* slash2
    ) {
        if (r == n) {
            ans.push_back(cur);
            return;
        }

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
            backtrack(ans, cur, r + 1, n, row, col, slash1, slash2);
            cur[r][c] = '.';
            row[r] = false;
            col[c] = false;
            slash1[r + c] = false;
            slash2[r - c + n - 1] = false;
        }
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int n = 4;
    vector<vector<string>> ans = solution -> solveNQueens(n);
    for (vector<vector<string>>::iterator outer_iter = ans.begin(); outer_iter != ans.end(); outer_iter++) {
        for (vector<string>::iterator inner_iter = (*outer_iter).begin(); inner_iter != (*outer_iter).end(); inner_iter++) {
            cout << (*inner_iter) << endl;
        }
        cout << endl;
    }
}
/*************************************************
Author: wenhaofang
Date: 2022-11-11
Description: leetcode130 - Surrounded Regions
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
 * 方法一：深度优先搜索
 * 
 * 理论时间复杂度：O(m * n)，其中 m、n 分别为矩阵的宽和长
 * 理论空间复杂度：O(m * n)，其中 m、n 分别为矩阵的宽和长
 * 
 * 实际时间复杂度：Runtime: 11 ms, faster than 96.66% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 9.9 MB, less than 82.22% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 题目中说，任何边界上的 'O' 都不会填充为 'X'，因为这些 'O' 没有被 'X' 所围绕
 * 
 * 换句话说，与边界相连的 'O' 都继续保持为 'O'，而其它的 'O' 则会被 'X' 所填充
 * 
 * 解题思路如下，其中第 2 步使用深度优先搜索实现：
 * 
 * 1. 找出边界上的 'O'
 * 
 * 2. 找出与上述的 'O' 相连的 'O'
 * 
 * 3. 将上述找到的 'O' 填充为 'A'
 * 
 * 4. 遍历矩阵，将 'O' 修改为 'X'，将 'A' 修改为 'O'
 * 
 * 由于在原数组中自带有访问标志，所以无需担心重复访问
*/

// class Solution {
// public:
//     void dfs(vector<vector<char>>& board, int x, int y, int m, int n) {
//         if  (
//             x < 0 ||
//             y < 0 ||
//             x >= m ||
//             y >= n ||
//             board[x][y] != 'O'
//         ) {
//             return;
//         }
//         board[x][y] = 'A';
//         dfs(board, x + 1, y, m, n);
//         dfs(board, x - 1, y, m, n);
//         dfs(board, x, y + 1, m, n);
//         dfs(board, x, y - 1, m, n);
//     }

//     void solve(vector<vector<char>>& board) {
//         // 特判
//         int m = board.size();
//         if (m <= 2) {
//             return;
//         }
//         int n = board[0].size();
//         if (n <= 2) {
//             return;
//         }
//         // 1. 找出边界上的 'O'
//         // 2. 找出与上述的 'O' 相连的 'O'
//         // 3. 将上述找到的 'O' 填充为 'A'
//         for (int i = 1; i <= m - 2; i++) {
//             dfs(board, i, 0, m, n);
//             dfs(board, i, n - 1, m, n);
//         }
//         for (int j = 0; j <= n - 1; j++) {
//             dfs(board, 0, j, m, n);
//             dfs(board, m - 1, j, m, n);
//         }
//         // 4. 遍历矩阵，将 'O' 修改为 'X'，将 'A' 修改为 'O'
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (board[i][j] == 'O') {
//                     board[i][j]  = 'X';
//                 }
//                 if (board[i][j] == 'A') {
//                     board[i][j]  = 'O';
//                 }

//             }
//         }
//     }
// };

/**
 * 方法二：广度优先搜索
 * 
 * 理论时间复杂度：O(m * n)，其中 m、n 分别为矩阵的宽和长
 * 理论空间复杂度：O(m * n)，其中 m、n 分别为矩阵的宽和长
 * 
 * 实际时间复杂度：Runtime: 9 ms, faster than 98.07% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 10.1 MB, less than 54.48% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 题目中说，任何边界上的 'O' 都不会填充为 'X'，因为这些 'O' 没有被 'X' 所围绕
 * 
 * 换句话说，与边界相连的 'O' 都继续保持为 'O'，而其它的 'O' 则会被 'X' 所填充
 * 
 * 解题思路如下，其中第 2 步使用广度优先搜索实现：
 * 
 * 1. 找出边界上的 'O'
 * 
 * 2. 找出与上述的 'O' 相连的 'O'
 * 
 * 3. 将上述找到的 'O' 填充为 'A'
 * 
 * 4. 遍历矩阵，将 'O' 修改为 'X'，将 'A' 修改为 'O'
 * 
 * 由于在原数组中自带有访问标志，所以无需担心重复访问
*/

class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    void solve(vector<vector<char>>& board) {
        // 特判
        int m = board.size();
        if (m <= 2) {
            return;
        }
        int n = board[0].size();
        if (n <= 2) {
            return;
        }
        queue<pair<int, int>> q;
        // 1. 找出边界上的 'O'
        // 3. 将上述找到的 'O' 填充为 'A'
        for (int i = 1; i <= m - 2; i++) {
            if (board[i][0] == 'O') {
                board[i][0] =  'A';
                q.emplace(i, 0);
            }
            if (board[i][n - 1] == 'O') {
                board[i][n - 1] =  'A';
                q.emplace(i, n - 1);
            }
        }
        for (int j = 0; j <= n - 1; j++) {
            if (board[0][j] == 'O') {
                board[0][j] =  'A';
                q.emplace(0, j);
            }
            if (board[m - 1][j] == 'O') {
                board[m - 1][j] =  'A';
                q.emplace(m - 1, j);
            }
        }
        // 2. 找出与上述的 'O' 相连的 'O'
        // 3. 将上述找到的 'O' 填充为 'A'
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int kx = x + dx[k];
                int ky = y + dy[k];
                if  (
                    kx < 0 ||
                    ky < 0 ||
                    kx >= m ||
                    ky >= n ||
                    board[kx][ky] != 'O'
                ) {
                    continue;
                }
                board[kx][ky] = 'A';
                q.emplace(kx, ky);
            }
        }
        // 4. 遍历矩阵，将 'O' 修改为 'X'，将 'A' 修改为 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j]  = 'X';
                }
                if (board[i][j] == 'A') {
                    board[i][j]  = 'O';
                }

            }
        }
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
    };
    solution -> solve(board);
    for (vector<vector<char>>::iterator outer_iter = board.begin(); outer_iter != board.end(); outer_iter++) {
        for (vector<char>::iterator inner_iter = (*outer_iter).begin(); inner_iter != (*outer_iter).end(); inner_iter++) {
            cout << (*inner_iter) << " ";
        }
        cout << endl;
    }
}
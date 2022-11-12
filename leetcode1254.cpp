/*************************************************
Author: wenhaofang
Date: 2022-11-12
Description: leetcode1254 - Number of Closed Islands
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
 * 实际时间复杂度：Runtime: 18 ms, faster than 82.46% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 9.4 MB, less than 93.63% of C++ online submissions
 */

// class Solution {
// public:
//     void dfs(vector<vector<int>>& grid, int x, int y, int m, int n) {
//         if  (
//             x < 0 ||
//             y < 0 ||
//             x >= m ||
//             y >= n ||
//             grid[x][y] != 0
//         ) {
//             return;
//         }
//         grid[x][y] = 1;
//         dfs(grid, x + 1, y, m, n);
//         dfs(grid, x - 1, y, m, n);
//         dfs(grid, x, y + 1, m, n);
//         dfs(grid, x, y - 1, m, n);
//     }

//     int closedIsland(vector<vector<int>>& grid) {
//         // 特判
//         int m = grid.size();
//         if (m <= 2) {
//             return 0;
//         }
//         int n = grid[0].size();
//         if (n <= 2) {
//             return 0;
//         }
//         // 1. 找出边界上的 0
//         // 2. 找出与上述的 0 相连的 0 (深度优先搜索)
//         // 3. 将上述找到的 0 填充为 1
//         for (int i = 1; i <= m - 2; i++) {
//             if (grid[i][0] == 0) {
//                 dfs(grid, i, 0, m, n);
//             }
//             if (grid[i][n - 1] == 0) {
//                 dfs(grid, i, n - 1, m, n);
//             }
//         }
//         for (int j = 0; j <= n - 1; j++) {
//             if (grid[0][j] == 0) {
//                 dfs(grid, 0, j, m, n);
//             }
//             if (grid[m - 1][j] == 0) {
//                 dfs(grid, m - 1, j, m, n);
//             }
//         }
//         // 4. 找出矩阵中的 0
//         // 5. 找出与上述的 0 相连的 0 (深度优先搜索)
//         // 6. 将上述找到的 0 填充为 1
//         // 7. 答案加一
//         int ans = 0;
//         for (int i = 1; i < m - 1; i++) {
//             for (int j = 1; j < n - 1; j++) {
//                 if (grid[i][j] == 0) {
//                     dfs(grid, i, j, m, n);
//                     ans += 1;
//                 }
//             }
//         }
//         return ans;
//     }
// };

/**
 * 方法二：广度优先搜索
 * 
 * 理论时间复杂度：O(m * n)，其中 m、n 分别为矩阵的宽和长
 * 理论空间复杂度：O(m * n)，其中 m、n 分别为矩阵的宽和长
 * 
 * 实际时间复杂度：Runtime: 35 ms, faster than 22.50% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 13.9 MB, less than 9.37% of C++ online submissions
 */

// class Solution {
// public:
//     const int dx[4] = {1, -1, 0, 0};
//     const int dy[4] = {0, 0, 1, -1};

//     void bfs(vector<vector<int>>& grid, int x, int y, int m, int n) {
//         queue<pair<int, int>> q;
//         grid[x][y] = 1;
//         q.emplace(x, y);
//         while (!q.empty()) {
//             int nx = q.front().first;
//             int ny = q.front().second;
//             q.pop();
//             for (int k = 0; k < 4; k++) {
//                 int mx = nx + dx[k];
//                 int my = ny + dy[k];
//                 if  (
//                     mx < 0 ||
//                     my < 0 ||
//                     mx >= m ||
//                     my >= n ||
//                     grid[mx][my] != 0
//                 ) {
//                     continue;
//                 }
//                 grid[mx][my] = 1;
//                 q.emplace(mx, my);
//             }
//         }
//     }

//     int closedIsland(vector<vector<int>>& grid) {
//         // 特判
//         int m = grid.size();
//         if (m <= 2) {
//             return 0;
//         }
//         int n = grid[0].size();
//         if (n <= 2) {
//             return 0;
//         }
//         // 1. 找出边界上的 0
//         // 2. 找出与上述的 0 相连的 0 (广度优先搜索)
//         // 3. 将上述找到的 0 填充为 1
//         for (int i = 1; i <= m - 2; i++) {
//             if (grid[i][0] == 0) {
//                 bfs(grid, i, 0, m, n);
//             }
//             if (grid[i][n - 1] == 0) {
//                 bfs(grid, i, n - 1, m, n);
//             }
//         }
//         for (int j = 0; j <= n - 1; j++) {
//             if (grid[0][j] == 0) {
//                 bfs(grid, 0, j, m, n);
//             }
//             if (grid[m - 1][j] == 0) {
//                 bfs(grid, m - 1, j, m, n);
//             }
//         }
//         // 4. 找出矩阵中的 0
//         // 5. 找出与上述的 0 相连的 0 (广度优先搜索)
//         // 6. 将上述找到的 0 填充为 1
//         // 7. 答案加一
//         int ans = 0;
//         for (int i = 1; i < m - 1; i++) {
//             for (int j = 1; j < n - 1; j++) {
//                 if (grid[i][j] == 0) {
//                     bfs(grid, i, j, m, n);
//                     ans += 1;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    int closedIsland(vector<vector<int>>& grid) {
        // 特判
        int m = grid.size();
        if (m <= 2) {
            return 0;
        }
        int n = grid[0].size();
        if (n <= 2) {
            return 0;
        }
        // 1. 找出边界上的 0
        // 2. 找出与上述的 0 相连的 0 (广度优先搜索)
        // 3. 将上述找到的 0 填充为 1
        queue<pair<int, int>> q1;
        for (int i = 1; i <= m - 2; i++) {
            if (grid[i][0] == 0) {
                q1.emplace(i, 0);
            }
            if (grid[i][n - 1] == 0) {
                q1.emplace(i, n - 1);
            }
        }
        for (int j = 0; j <= n - 1; j++) {
            if (grid[0][j] == 0) {
                q1.emplace(0, j);
            }
            if (grid[m - 1][j] == 0) {
                q1.emplace(m - 1, j);
            }
        }
        while (!q1.empty()) {
            int nx = q1.front().first;
            int ny = q1.front().second;
            q1.pop();
            for (int k = 0; k < 4; k++) {
                int mx = nx + dx[k];
                int my = ny + dy[k];
                if  (
                    mx < 0 ||
                    my < 0 ||
                    mx >= m ||
                    my >= n ||
                    grid[mx][my] != 0
                ) {
                    continue;
                }
                grid[mx][my] = 1;
                q1.emplace(mx, my);
            }
        }
        // 4. 找出矩阵中的 0
        // 5. 找出与上述的 0 相连的 0 (广度优先搜索)
        // 6. 将上述找到的 0 填充为 1
        // 7. 答案加一
        int ans = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    ans += 1;
                    queue<pair<int, int>> q2;
                    q2.emplace(i, j);
                    while (!q2.empty()) {
                        int nx = q2.front().first;
                        int ny = q2.front().second;
                        q2.pop();
                        for (int k = 0; k < 4; k++) {
                            int mx = nx + dx[k];
                            int my = ny + dy[k];
                            if  (
                                mx < 0 ||
                                my < 0 ||
                                mx >= m ||
                                my >= n ||
                                grid[mx][my] != 0
                            ) {
                                continue;
                            }
                            grid[mx][my] = 1;
                            q2.emplace(mx, my);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0},
    };
    int ans = solution -> closedIsland(grid);
    cout << ans << endl;
}
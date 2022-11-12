/*************************************************
Author: wenhaofang
Date: 2022-11-12
Description: leetcode695 - Max Area of Island
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
 * 实际时间复杂度：Runtime: 25 ms, faster than 84.93% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 23.2 MB, less than 88.66% of C++ online submissions
 */

// class Solution {
// public:
//     int dfs(vector<vector<int>>& grid, int x, int y, int m, int n) {
//         int area = 0;
//         if  (
//             x < 0 ||
//             y < 0 ||
//             x >= m ||
//             y >= n ||
//             grid[x][y] != 1
//         ) {
//             return area;
//         }
//         grid[x][y] = 0;
//         area += 1;
//         area += dfs(grid, x + 1, y, m, n);
//         area += dfs(grid, x - 1, y, m, n);
//         area += dfs(grid, x, y + 1, m, n);
//         area += dfs(grid, x, y - 1, m, n);
//         return area;
//     }

//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         // 遍历矩阵，找出并标记连通的陆地，同时计算陆地面积
//         int ans = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 1) {
//                     int area = dfs(grid, i, j, m, n);
//                     ans = max(ans, area);
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
 * 实际时间复杂度：Runtime: 18 ms, faster than 95.22% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 26.8 MB, less than 17.47% of C++ online submissions
 */

class Solution {
public:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    int bfs(vector<vector<int>>& grid, int x, int y, int m, int n) {
        int area = 0;
        queue<pair<int, int>> q;
        grid[x][y] = 0;
        q.emplace(x, y);
        area += 1;
        while (!q.empty()) {
            int nx = q.front().first;
            int ny = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int mx = nx + dx[k];
                int my = ny + dy[k];
                if  (
                    mx < 0 ||
                    my < 0 ||
                    mx >= m ||
                    my >= n ||
                    grid[mx][my] != 1
                ) {
                    continue;
                }
                grid[mx][my] = 0;
                q.emplace(mx, my);
                area += 1;
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // 遍历矩阵，找出并标记连通的陆地，同时计算陆地面积
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = bfs(grid, i, j, m, n);
                    ans = max(ans, area);
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
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    };
    int ans = solution -> maxAreaOfIsland(grid);
    cout << ans << endl;
}
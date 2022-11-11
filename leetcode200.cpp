/*************************************************
Author: wenhaofang
Date: 2022-11-12
Description: leetcode200 - Number of Islands
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
 * 实际时间复杂度：Runtime: 50 ms, faster than 80.17% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 12.3 MB, less than 61.43% of C++ online submissions
 */

// class Solution {
// public:
//     void dfs(vector<vector<char>>& grid, int x, int y, int m, int n) {
//         if  (
//             x < 0 ||
//             y < 0 ||
//             x >= m ||
//             y >= n ||
//             grid[x][y] != '1'
//         ) {
//             return;
//         }
//         grid[x][y] = '0';
//         dfs(grid, x + 1, y, m, n);
//         dfs(grid, x - 1, y, m, n);
//         dfs(grid, x, y + 1, m, n);
//         dfs(grid, x, y - 1, m, n);
//     }

//     int numIslands(vector<vector<char>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         // 遍历矩阵
//         // 发现陆地之后，岛屿数量加一，并使用深度优先搜索将相邻的陆地标记
//         int ans = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == '1') {
//                     ans += 1;
//                     dfs(grid, i, j, m, n);
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
 * 实际时间复杂度：Runtime: 52 ms, faster than 78.66% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 18.2 MB, less than 19.77% of C++ online submissions
 */

// class Solution {
// public:
//     const int dx[4] = {1, -1, 0, 0};
//     const int dy[4] = {0, 0, 1, -1};

//     void bfs(vector<vector<char>>& grid, int x, int y, int m, int n) {
//         queue<pair<int, int>> q;
//         grid[x][y] = '0';
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
//                     grid[mx][my] != '1'
//                 ) {
//                     continue;
//                 }
//                 grid[mx][my] = '0';
//                 q.emplace(mx, my);
//             }
//         }
//     }

//     int numIslands(vector<vector<char>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         // 遍历矩阵
//         // 发现陆地之后，岛屿数量加一，并使用广度优先搜索将相邻的陆地标记
//         int ans = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == '1') {
//                     ans += 1;
//                     bfs(grid, i, j, m, n);
//                 }
//             }
//         }
//         return ans;
//     }
// };

/**
 * 方法三：并查集
 * 
 * 理论时间复杂度：O(m * n)，其中 m、n 分别为矩阵的宽和长
 * 理论空间复杂度：O(m * n)，其中 m、n 分别为矩阵的宽和长
 * 
 * 实际时间复杂度：Runtime: 42 ms, faster than 88.12% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 15.8 MB, less than 28.37% of C++ online submissions
 */

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;

public:
    UnionFind(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    count++;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) {
                rank[rootx] += 1;
            }
            count--;
        }
    }

    int getCount() {
        return count;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        UnionFind uf(grid);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    if (i + 1 <  m && grid[i + 1][j] == '1') uf.unite(i * n + j, (i + 1) * n + j);
                    if (i - 1 >= 0 && grid[i - 1][j] == '1') uf.unite(i * n + j, (i - 1) * n + j);
                    if (j + 1 <  n && grid[i][j + 1] == '1') uf.unite(i * n + j, i * n + (j + 1));
                    if (j - 1 >= 0 && grid[i][j - 1] == '1') uf.unite(i * n + j, i * n + (j - 1));
                }
            }
        }
        return uf.getCount();
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
    };
    int ans = solution -> numIslands(grid);
    cout << ans << endl;
}
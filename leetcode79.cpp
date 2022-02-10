/*************************************************
Author: wenhaofang
Date: 2022-02-20
Description: leetcode79 - Word Search
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
 * 方法一：栈
 * 
 * 实际时间复杂度：Time Limit Exceeded
 * 实际空间复杂度：Time Limit Exceeded
 */
/**
 * 基本思路
 * 
 * 要找一个特例可以用深度优先搜索，要找最短路径可以用广度优先搜索
 * 
 * 深度优先搜索可以用栈实现，也可以用回溯算法实现，而广度优先搜索可以用队列实现
 */
// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         int m = board.size();
//         int n = board[0].size();
//         // 由于一个栈难以保存当前状态
//         // 这里使用三个栈保存，其含义分别如下
//         stack<pair<int, int>> curCoords;     // 当前坐标
//         stack<string> curTokens;             // 当前剩余字符
//         stack<unordered_set<int>> hisCoords; // 历史坐标
//         // 初始栈的起始状态
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (board[i][j] == word[0]) {
//                     if (word.length() == 1) {
//                         return true;
//                     }
//                     curCoords.push({i, j});
//                     curTokens.push(word.substr(1));
//                     unordered_set<int> newCoord;
//                     newCoord .insert(i * 10 + j);
//                     hisCoords.push(newCoord);
//                 }
//             }
//         }
//         // 探索方向，即选择列表
//         vector<pair<int, int>> directions = {
//             {0, 1},
//             {1, 0},
//             {0, -1},
//             {-1, 0}
//         };
//         // 循环处理，直至栈为空
//         while (!curCoords.empty()) {
//             // 每次处理一个元素
//             // 还原栈的当前状态
//             pair<int, int> curCoord = curCoords.top();
//             string curToken = curTokens.top();
//             unordered_set<int> hisCoord = hisCoords.top();
//             curCoords.pop();
//             curTokens.pop();
//             hisCoords.pop();
//             // 遍历选择列表
//             for (const auto & direction: directions) {
//                 // 新的坐标
//                 int i = curCoord.first  + direction.first ;
//                 int j = curCoord.second + direction.second;
//                 // 判断新的坐标是否合法
//                 if (
//                     i >= 0 &&
//                     i < m  &&
//                     j >= 0 &&
//                     j < n  &&
//                     hisCoord.find(i * 10 + j) == hisCoord.end() &&
//                     board[i][j] == curToken[0]
//                 ) {
//                     // 如果新的坐标合法，将当前状态入栈
//                     // 如果仅剩最后一个，说明已找到答案
//                     if (curToken.length() == 1) {
//                         return true;
//                     }
//                     curCoords.push({i, j});
//                     curTokens.push(curToken.substr(1));
//                     unordered_set<int> newCoord(hisCoord);
//                     newCoord .insert(i * 10 + j);
//                     hisCoords.push(newCoord);
//                 }
//             }
//         }
//         return false;
//     }
// };

/**
 * 方法二：回溯算法
 * 
 * 实际时间复杂度：Time Limit Exceeded
 * 实际空间复杂度：Time Limit Exceeded
 */
/**
 * 基本思路
 * 
 * 在这里，回溯要优于深度优先搜索
 * 
 * 通过函数调用栈（递归）替代手动维护栈状态
 */
// class Solution {
// public:
//     bool check(
//         vector<vector<char>>& board,
//         vector<vector<int>> & visited,
//         int i, // 当前横坐标
//         int j, // 当前纵坐标
//         int k, // 当前处理到的字符串索引
//         string& s
//     ) {
//         // 结束条件
//         if (board[i][j] != s[k]) {
//             return false;
//         }
//         if (k == s.length() - 1) {
//             return true;
//         }
//         // 做出选择
//         visited[i][j] = true;
//         // 遍历选择列表
//         vector<pair<int, int>> directions = { // 选择列表
//             {0, 1},
//             {0, -1},
//             {1, 0},
//             {-1, 0}
//         };
//         bool result = false;
//         for (const auto & direction: directions) {
//             // 新的坐标
//             int newI = i + direction.first;
//             int newJ = j + direction.second;
//             // 判断新的坐标是否合法
//             if (
//                 newI >= 0 &&
//                 newI < board.size() &&
//                 newJ >= 0 &&
//                 newJ < board[0].size()
//             ) {
//                 if (!visited[newI][newJ]) {
//                     // 如果新的坐标合法
//                     // 那么继续深入探索
//                     bool flag = check(board, visited, newI, newJ, k + 1, s);
//                     if (flag) {
//                         result = true;
//                         break;
//                     }
//                 }
//             }
//         }
//         // 撤销选择
//         visited[i][j] = false;
//         // 返回结果
//         return result;
//     }

//     bool exist(vector<vector<char>>& board, string word) {
//         int m = board.size();
//         int n = board[0].size();
//         vector<vector<int>> visited(m, vector<int>(n, 0));
//         // 遍历每一个可能的起点
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 bool flag = check(board, visited, i, j, 0, word);
//                 if  (flag) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

/**
 * 方法三：回溯算法
 * 
 * 理论时间复杂度：O(m * n * 3^L)，其中 m、n 分别为矩阵的长和宽，L 为字符串长度
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 4 ms, faster than 99.75% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 8 MB, less than 31.65% of C++ online submissions
 */
class Solution {
public:
    bool check(
        vector<vector<char>>& board,
        int i, // 当前横坐标
        int j, // 当前纵坐标
        int k, // 当前处理到的字符串索引
        string& s
    ) {
        // 结束条件
        if (
            i < 0 ||
            j < 0 ||
            i >= board.size() ||
            j >= board[0].size()
        ) {
            return false;
        }
        if (board[i][j] != s[k]) {
            return false;
        }
        if (k == s.length() - 1) {
            return true;
        }
        // 做出选择
        char c = board[i][j];
        board[i][j] = '0'; // 直接在原数组修改，不用额外的标记数组
        // 遍历选择列表
        bool flag = (
            check(board, i + 1, j, k + 1, s) ||
            check(board, i - 1, j, k + 1, s) ||
            check(board, i, j + 1, k + 1, s) ||
            check(board, i, j - 1, k + 1, s)
        );
        // 撤销选择
        board[i][j] = c;
        // 返回结果
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {

        // 针对题目特性的超级预处理，时间从 188ms 提高到 4ms
        int count = 0;
        for (int i = 1; i < word.size(); ++i){
            if (word[i] == word[i - 1]) {
                count += 1;
            } else {
                if (count > 6) {
                    reverse(word.begin(), word.end());
                }
                break;
            }
        }

        int m = board.size();
        int n = board[0].size();
        // 遍历每一个可能的起点
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool flag = check(board, i, j, 0, word);
                if  (flag) {
                    return true;
                }
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
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    bool ans = solution -> exist(board, word);
    cout << ans << endl;
}
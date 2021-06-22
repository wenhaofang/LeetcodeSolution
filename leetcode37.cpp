/*************************************************
Author: wenhaofang
Date: 2021-06-21
Description: leetcode37 - Sudoku Solver
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
 * 理论时间复杂度：O(9 ^ (9 * 9))
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 16 ms, faster than 81.09% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.4 MB, less than 58.52% of C++ online submissions
 */
// class Solution {
// public:
//     void solveSudoku(vector<vector<char>>& board) {
//         backtrack(board, 0, 0);
//     }

//     /**
//      * 回溯
//      */
//     bool backtrack(vector<vector<char>>& board, int i, int j) {
//         // 边界条件，行数超出边框，说明此时找到一个可行解
//         if (i == 9) {
//             return true;
//         }
//         // 边界条件，列数超出边框，换到下一行继续上述过程
//         if (j == 9) {
//             return backtrack(board, i + 1, 0);
//         }
//         // 如果已经有数字，不做处理，并继续尝试下一个位置
//         if (board[i][j] != '.') {
//             return backtrack(board, i, j + 1);
//         }
//         // 逐一尝试填入所有可能选择
//         for (char c = '1'; c <= '9'; c++) {
//             // 如果不能填入，说明当前选择不可行，继续尝试下一个选择
//             if (!isValid(board, i, j, c)) {
//                 continue;
//             }
//             // 填入
//             board[i][j] = c;
//             // 如果可以填入，则继续尝试填写下一个位置
//             if (backtrack(board, i, j + 1)) {
//                 return true;
//             };
//             // 回退
//             board[i][j] = '.';
//         }
//         // 所有尝试都失败
//         return false;
//     }

//     /**
//      * 判断在数独的 (i, j) 位置填入字符 c 是否可行
//      */
//     bool isValid(vector<vector<char>>& board, int i, int j, char c) {
//         for (int k = 0; k < 9; k++) {
//             if (board[i][k] == c) return false;
//             if (board[k][j] == c) return false;
//             if (board[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3] == c) return false;
//         }
//         return true;
//     }
// };

/**
 * 方法二：回溯 + 哈希映射
 * 
 * 理论时间复杂度：O(9 ^ (9 * 9))
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.5 MB, less than 28.58% of C++ online submissions
 */
/**
 * 改进思路
 * 
 * 使用哈希映射记录数字是否出现在行、列、宫格，典型的以空间换时间
 */
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // 记录每行中数字 1 ~ 9 是否出现，共有 9 行
        bool row[9][9] = {false};
        // 记录每列中数字 1 ~ 9 是否出现，共有 9 列
        bool col[9][9] = {false};
        // 记录每宫格数字 1 ~ 9 是否出现，共有 9 个宫格
        bool box[9][9] = {false};
        // 遍历一次所有格，初始化以上数组
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                } else {
                    int k = (i / 3) * 3 + (j / 3);
                    int n = board[i][j] - '0' - 1;
                    row[i][n] = col[j][n] = box[k][n] = true;
                }
            }
        }
        backtrack(board, 0, 0, row, col, box);
    }

    /**
     * 回溯
     */
    bool backtrack(vector<vector<char>>& board, int i, int j, bool row[9][9], bool col[9][9], bool box[9][9]) {
        // 边界条件，行数超出边框，说明此时找到一个可行解
        if (i == 9) {
            return true;
        }
        // 边界条件，列数超出边框，换到下一行继续上述过程
        if (j == 9) {
            return backtrack(board, i + 1, 0, row, col, box);
        }
        // 如果已经有数字，不做处理，并继续尝试下一个位置
        if (board[i][j] != '.') {
            return backtrack(board, i, j + 1, row, col, box);
        }
        // 逐一尝试填入所有可能选择
        for (char c = '1'; c <= '9'; c++) {
            int k = (i / 3) * 3 + (j / 3);
            int n = c - '0' - 1;
            // 如果不能填入，说明当前选择不可行，继续尝试下一个选择
            if (row[i][n] || col[j][n] || box[k][n]) {
                continue;
            }
            // 填入
            board[i][j] = c;
            row[i][n] = col[j][n] = box[k][n] = true;
            // 如果可以填入，则继续尝试填写下一个位置
            if (backtrack(board, i, j + 1, row, col, box)) {
                return true;
            };
            // 回退
            board[i][j] = '.';
            row[i][n] = col[j][n] = box[k][n] = false;
        }
        // 所有尝试都失败
        return false;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<vector<char>> board(9, vector<char>(9));
    char arr[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = arr[i][j];
        }
    }
    solution -> solveSudoku(board);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
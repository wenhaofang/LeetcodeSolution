/*************************************************
Author: wenhaofang
Date: 2021-06-18
Description: leetcode36 - Valid Sudoku
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
 * 方法一：哈希映射
 * 
 * 理论时间复杂度：O(1)
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 12 ms, faster than 98.59% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 17.9 MB, less than 96.50% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 使用哈希映射存储已遍历的数据，典型的以空间换时间，目的是减少遍历次数
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 记录每行中数字 1 ~ 9 是否出现，共有 9 行
        bool row[9][9] = {false};
        // 记录每列中数字 1 ~ 9 是否出现，共有 9 列
        bool col[9][9] = {false};
        // 记录每宫格数字 1 ~ 9 是否出现，共有 9 个宫格
        bool box[9][9] = {false};
        // 遍历一次所有格
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int val = c - '0' - 1;
                    if (
                        row[i][val] == true ||
                        col[j][val] == true ||
                        box[(i / 3) * 3 + j / 3][val] == true
                    ) {
                        return false;
                    } else {
                        row[i][val] = true;
                        col[j][val] = true;
                        box[(i / 3) * 3 + j / 3][val] = true;
                    }
                }
            }
        }
        return true;
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
    bool ans = solution -> isValidSudoku(board);
    cout << ans << endl;
}
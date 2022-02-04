/*************************************************
Author: wenhaofang
Date: 2022-02-08
Description: leetcode65 - Valid Number
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
 * 方法一：有限状态机
 * 
 * 理论时间复杂度：O(n)，其中 n 为字符串长度
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 8 ms, faster than 20.73% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 9.2 MB, less than 8.78% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 由于状态转移图不方便在代码文件中展示，所以这里用状态转移表来代替
 * 
 * |------------------------------------------------
 * |     |                  |        状态转换       |
 * | 状态      状态含义       -----------------------
 * |     |                  |  . | +/- | e/E | 0-9 |
 * |------------------------------------------------
 * |  0  | 开始状态          |  4 |  1  | -1  |  2  |
 * |  1  | 正负符号          |  4 | -1  | -1  |  2  |
 * |  2  | 整数数字          |  3 | -1  |  6  |  2  |
 * |  3  | 小数点，左侧有整数 | -1 | -1  |  6  |  5  |
 * |  4  | 小数点，左侧无整数 | -1 | -1  | -1  |  5  |
 * |  5  | 小数数字          | -1 | -1  |  6  |  5  |
 * |  6  | 指数字母          | -1 |  7  | -1  |  8  |
 * |  7  | 指数符号          | -1 | -1  | -1  |  8  |
 * |  8  | 指数数字          | -1 | -1  | -1  |  8  |
 * |------------------------------------------------
 * 
 */
// class Solution {
// public:
//     bool isNumber(string s) {
//         unordered_map<char, int> mapping = {
//             // 键为输入字符，值对应着状态转移表中的列索引
//             {'.', 0},
//             {'+', 1},
//             {'-', 1},
//             {'e', 2},
//             {'E', 2},
//             {'0', 3},
//             {'1', 3},
//             {'2', 3},
//             {'3', 3},
//             {'4', 3},
//             {'5', 3},
//             {'6', 3},
//             {'7', 3},
//             {'8', 3},
//             {'9', 3},
//         };
//         vector<vector<int>> transfer = {
//             // 行代表状态，列代表输入，值对应着在某一状态下接收某一输入转移到新状态
//             { 4,  1, -1, 2},
//             { 4, -1, -1, 2},
//             { 3, -1,  6, 2},
//             {-1, -1,  6, 5},
//             {-1, -1, -1, 5},
//             {-1, -1,  6, 5},
//             {-1,  7, -1, 8},
//             {-1, -1, -1, 8},
//             {-1, -1, -1, 8}
//         };

//         int state = 0; // 表示当前状态，初始化为开始状态

//         for (char& c: s) {
//             // 前判断：如果输入的字符不合法，那么立即返回 false
//             if (mapping.find(c) == mapping.end()) {
//                 return false;
//             }

//             // 状态转移
//             state = transfer[state][mapping[c]];

//             // 后判断：如果状态转移是错误的，那么立即返回 false
//             if (state == -1) {
//                 return false;
//             }
//         }

//         if (
//             state == 2 ||
//             state == 3 ||
//             state == 5 ||
//             state == 8 // 这些状态可以作为结束状态
//         ) {
//             return true;
//         } else {
//             return false;
//         }
//     }
// };

/**
 * 方法二：暴力模拟
 * 
 * 理论时间复杂度：O(n)，其中 n 为字符串长度
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 5.9 MB, less than 77.83% of C++ online submissions
 */
class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        int i = 0;
        // 整数和小数部分
        int dots = 0;
        int digits = 0;
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }
        while  (i < n) {
            if (s[i] == '.') {
                dots++;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                digits++;
            }
            else {
                break;
            }
            i++;
        }
        if (dots > 1 || digits == 0) {
            return false;
        }
        // 指数部分
        if (s[i] == 'e' || s[i] == 'E') {
            i++;

            digits = 0;
            if (s[i] == '+' || s[i] == '-') {
                i++;
            }
            while  (i < n) {
                if (s[i] >= '0' && s[i] <= '9') {
                    digits++;
                }
                else {
                    break;
                }
                i++;
            }
            if (digits == 0) {
                return false;
            }
        }
        // 返回结果
        return i == n;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string s = "-123.456e789";
    bool ans = solution -> isNumber(s);
    cout << ans << endl;
}
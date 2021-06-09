/*************************************************
Author: wenhaofang
Date: 2021-03-09
Description: leetcode6 - ZigZag Conversion
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
 * 思路一：按题目要求排列图案，之后按顺序读取
 * 
 * 时间复杂度：O(n)，其中 n 为字符串长度
 * 空间复杂度：O(n)，其中 n 为字符串长度
 * 
 * 实际时间复杂度：Runtime: 20 ms, faster than 34.48% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 14 MB, less than 22.56% of C++ online submissions
 */
// class Solution {
// public:
//     string convert(string s, int numRows) {
//         // 前处理，特殊情况
//         // 若只有一行或行数大于等于字符串长度，则直接返回字符串
//         if (numRows == 1 || numRows >= s.size()) {
//             return s;
//         }
//         // 遍历字符串，按题目要求顺序填入二维数组
//         int currRow = 0;        // 当前的字符应该填入的行数
//         bool goDown = false;    // 当前的行数应该移动的方向
//         vector<vector<char>> charArray(numRows, vector<char>());
//         for (char c: s) {
//             // 在二维数组的当前行数填入字符
//             charArray[currRow].push_back(c);
//             // 移动方向达到第一行或最后一行时改变，其余情况保持不变
//             goDown = (currRow == 0 || currRow == numRows - 1) ? !goDown : goDown;
//             // 当前行数按照移动方向移动一行
//             currRow += goDown ? 1 : -1;
//         }
//         // 遍历二维数组，按题目要求顺序读出字符串
//         string ans;  // 用于储存答案字符串
//         vector<vector<char>>::iterator rowIter;
//         for (rowIter = charArray.begin(); rowIter != charArray.end() ; ++rowIter) {
//             for (int column = 0; column < (*rowIter).size(); column++) {
//                 ans += (*rowIter)[column];
//             }
//         }
//         // 返回答案
//         return ans;
//     }
// };

/**
 * 思路二：找规律
 * 
 * 时间复杂度：O(n)，其中 n 为字符串长度
 * 空间复杂度：O(n)，其中 n 为字符串长度
 * 
 * 实际时间复杂度：Runtime: 8 ms, faster than 89.14% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 8.1 MB, less than 94.33% of C++ online submissions
 */
/**
 * 规律如下：
 * 
 * 排序后图案的正数第 1 行 (i = 0)               元素的索引为 k(2 * numRows - 2)
 * 排序后图案的倒数第 1 行 (i = numRows - 1)     元素的索引为 k(2 * numRows - 2) + (numRows - 1)
 * 排序后图案的其它第 i 行 (0 < i < numRows - 1) 元素的索引为 k(2 * numRows - 2) + i 和 k(2 * numRows - 2) + i + 2(numRows - i - 1)
 * 其中 k = 0, 1, 2, ...，令 m = 2 * numRows - 2，则
 * 当 i = 0               时，第 i 行各元素索引为 km + i
 * 当 0 < i < numRows - 1 时，第 i 行各元素索引为 km + i 和 km + m - i
 * 当 i = numRows - 1     时，第 i 行各元素索引为 km + i
 */
class Solution {
public:
    string convert(string s, int numRows) {
        // 前处理，特殊情况
        // 若只有一行或行数大于等于字符串长度，则直接返回字符串
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }
        // 初始变量
        string ans;
        int n = s.size();
        int m = 2 * numRows - 2;
        // 排序后的图形按行填入
        for (int i = 0; i < numRows; i++) {
            // 排序后的图形每行元素索引
            for (int k = 0; k * m + i < n; k++) {
                ans += s[k * m + i];
                if (i != 0 && i != numRows - 1 && k * m + m - i < n) {
                    ans += s[k * m + m - i];
                }
            }
        }
        // 返回答案
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string ans = solution->convert(s, numRows);
    cout << ans << endl;
}
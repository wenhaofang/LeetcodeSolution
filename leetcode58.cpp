/*************************************************
Author: wenhaofang
Date: 2022-02-01
Description: leetcode58 - Length of Last Word
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
 * 方法一：暴力模拟（正向遍历）
 * 
 * 理论时间复杂度：O(n)，其中 n 为字符串长度
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 4 ms, faster than 51.61% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.5 MB, less than 88.99% of C++ online submissions
 */
// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         // 特判
//         int n = s.length();
//         if (n == 0) {
//             return 0;
//         }
//         // 处理，有点像动态规划的思路
//         int ans = s[0] == ' ' ? 0 : 1; // 初始，表示当前位置下最后一个单词的长度
//         for (int i = 1; i < n; i++) {  // 其余，计算其他位置下最后一个单词的长度
//             if (s[i] == ' ') {
//                 // 如果当前字符为空白
//                 // 那么当前位置下最后一个单词的长度不变
//                 continue;
//             }
//             else if (s[i - 1] == ' ') {
//                 // 如果当前字符为字母，并且前一个字符为空白
//                 // 说明是新单词的开头，需要重新来计数
//                 ans = 1;
//             }
//             else if (s[i - 1] != ' ') {
//                 // 如果当前字符为字母，并且前一个字符为字母
//                 // 说明是正处理的单词，答案需要来加一
//                 ans += 1;
//             }
//         }
//         return ans;
//     }
// };

/**
 * 方法二：暴力模拟（反向遍历）
 * 
 * 理论时间复杂度：O(n)，其中 n 为字符串长度
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.5 MB, less than 52.24% of C++ online submissions
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        // 特判
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        // 处理
        int ans = s[n - 1] == ' ' ? 0 : 1;
        bool needToStop = s[n - 1] == ' ' ? false : true; // 增加一个可提前终止的判断条件
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == ' ') {
                if (needToStop) {
                    break;
                } else {
                    continue;
                }
            } else {
                if (s[i + 1] == ' ') {
                    ans = 1;
                } else {
                    ans += 1;
                }
                needToStop = true;
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
    string s = "   fly me   to   the moon  ";
    int ans = solution -> lengthOfLastWord(s);
    cout << ans << endl;
}
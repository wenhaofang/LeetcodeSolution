/*************************************************
Author: wenhaofang
Date: 2022-01-22
Description: leetcode44 - Wildcard Matching
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
 * 方法一：动态规划
 * 
 * 理论时间复杂度：O(mn)，其中 m、n 分别为两个字符串的长度
 * 理论空间复杂度：O(mn)，其中 m、n 分别为两个字符串的长度
 * 
 * 实际时间复杂度：Runtime: 44 ms, faster than 69.26% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 28 MB, less than 13.85% of C++ online submissions
 */
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         // s 为数据字符串，其长度为 m
//         // p 为模式字符串，其长度为 n
//         int m = s.length();
//         int n = p.length();
//         // 二维 dp 数组
//         // 表示字符串 s 的前 i 个字符和字符串 p 的前 j 个字符是否匹配
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//         // 边界条件
//         dp[0][0] = true;
//         for (int j = 1; j <= n; j++) {
//             if (p[j - 1] == '*') {
//                 dp[0][j] = true;
//             } else {
//                 break;
//             }
//         }
//         // 填充数组
//         for (int i = 1; i <= m; i++) {
//             for (int j = 1; j <= n; j++) {
//                 // 若模式字符串的当前字符为星号
//                 // 则数据字符串没有要求，此时有两种情况，使用星号或不使用星号
//                 if (p[j - 1] == '*') {
//                     dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
//                 }
//                 // 若模式字符串的当前字符为问号，或者等于数据字符串的当前字符
//                 // 则取决于之前的状态
//                 else if (
//                     p[j - 1] == '?' ||
//                     p[j - 1] == s[i - 1]
//                 ) {
//                     dp[i][j] = dp[i - 1][j - 1];
//                 }
//             }
//         }
//         // 返回结果
//         return dp[m][n];
//     }
// };

/**
 * 方法二：贪心算法
 * 
 * 理论时间复杂度：O(mn)，其中 m、n 分别为两个字符串的长度
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 4 ms, faster than 97.32% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.6 MB, less than 86.06% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 在模式字符串，问号和字母都对应一个字符，容易处理，难点在于处理星号
 * 
 * 如果模式字符串的形式为 *u_1*u_2*...*u_n*，那么就意味着只需在数据字符串中按顺序找子串 u_1、u_2、...、u_n
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        // 预先处理
        int s1 = 0, s2 = s.length() - 1;
        int p1 = 0, p2 = p.length() - 1;
        // 1. 如果模式字符串开头不是星号
        //    那么先尝试匹配开头其它字符，保证模式字符串从左往右数第一个字符为星号
        while (
            s1 <= s2 &&
            p1 <= p2 &&
            p[p1] != '*'
        ) {
            if (
                p[p1] == '?' ||
                p[p1] == s[s1]
            ) {
                s1++;
                p1++;
            } else {
                return false;
            }
        }
        // 2. 如果模式字符串结尾不是星号
        //    那么先尝试匹配结尾其它字符，保证模式字符串从右往左数第一个字符为星号
        while (
            s1 <= s2 &&
            p1 <= p2 &&
            p[p2] != '*'
        ) {
            if (
                p[p2] == '?' ||
                p[p2] == s[s2]
            ) {
                s2--;
                p2--;
            } else {
                return false;
            }
        }
        // 3. 截取预处理后的数据字符串
        if (s1 <= s2) {
            s = s.substr(s1, s2 - s1 + 1);
        }
        else {
            s = "";
        }
        // 4. 截取预处理后的模式字符串
        if (p1 <= p2) {
            p = p.substr(p1, p2 - p1 + 1);
        }
        else {
            p = "";
        }
        // 5. 如果模式字符串为空，此时有两种情况：
        //    如果数据字符串也为空，则能够匹配
        //    如果数据字符串不为空，则不能匹配
        if (p.empty()) {
            return s.empty();
        }
        // 正式处理
        // s3 表示在 s 中的当前位置，s4 表示在 s 中的起始位置
        // p3 表示在 p 中的当前位置，p4 表示在 p 中的起始位置
        int s3 = 0, s4 = 0, m = s.size();
        int p3 = 0, p4 = 0, n = p.size();
        while (
            s3 < m &&
            p3 < n
        ) {
            if (
                p[p3] == '*'
            ) {
                // 如果模式字符串当前字符为星号
                // 说明已找到当前子串，开始寻找下一个子串
                // 那么模式字符串的当前位置前移一位，并且重新设置起始位置
                p3++;
                s4 = s3;
                p4 = p3;
            }
            else if (
                p[p3] == '?' ||
                p[p3] == s[s3]
            ) {
                // 如果模式字符串当前字符能够匹配数据字符串当前字符
                // 说明已匹配当前字符，准备匹配下一个字符
                // 那么模式字符串和数据字符串的当前位置都前移一位
                s3++;
                p3++;
            }
            else if (
                s4 + 1 < m
            ) {
                // 如果模式字符串当前字符不能匹配数据字符串当前字符
                // 需要枚举数据字符串的下一个起始位置
                // 那么数据字符串的起始位置前移一位，并且重新设置当前位置
                s4++;
                s3 = s4;
                p3 = p4;
            }
            else {
                // 如果当前字符不匹配，并且没有下一个起始位置
                // 表示无法匹配
                return false;
            }
        }
        // 返回结果
        // 如果数据字符串中还有字符，那么没有关系，因为模式字符串中最后一个字符为星号
        // 如果模式字符串中还有字符，那么剩下的字符都必须是星号才能匹配
        for (int i = p3; i < n; i++) {
            if (p[i] != '*') {
                return false;
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
    string s = "aa";
    string p = "*";
    bool ans = solution -> isMatch(s, p);
    cout << ans << endl;
}
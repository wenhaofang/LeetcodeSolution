/*************************************************
Author: wenhaofang
Date: 2021-03-15
Description: leetcode10 - Regular Expression Matching
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
 * 思路一：递归
 * 
 * 时间复杂度：O((m + n) 2^{m + n/2})，其中 m 为数据字符串长度，n 为模式字符串长度
 * 空间复杂度：O((m + n) 2^{m + n/2})，其中 m 为数据字符串长度，n 为模式字符串长度
 * 
 * 实际时间复杂度：Runtime: 152 ms, faster than 15.22% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 13.3 MB, less than 17.91% of C++ online submissions
 */
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         // s: 数据字符串，待匹配的字符串
//         // p: 模式字符串，用于匹配的模式

//         // 递归边界条件:模式字符串为空，此时有两种情况：
//         // 1）如果数据字符串也为空，那么两者匹配
//         // 2）如果数据字符串不为空，那么两者不匹配
//         if (p.empty()) {
//             return s.empty();
//         }
//         // 备用变量，在递归主逻辑中被使用
//         // 模式字符串和数据字符串的第一个字符是否匹配
//         bool isFirstMatch = !s.empty() && (p[0] == s[0] || p[0] == '.');
//         // 递归的主逻辑
//         if (p.size() >= 2 && p[1] == '*') {
//             // 当模式字符串前两位就是 "字符*"，此时会有两种选择：
//             // 1) 模式字符串中的 "字符*" 匹配数据字符串中的零个字符，此时
//             //    模式字符串 "减少" 两位字符，数据字符串 "不变"，变成子问题递归调用此函数
//             // 2) 模式字符串中的 "字符*" 匹配数据字符串中的一个字符，此时
//             //    模式字符串 "不变"，数据字符串 "减少" 一位字符，变成子问题递归调用此函数
//             return isMatch(s, p.substr(2)) || isFirstMatch && isMatch(s.substr(1), p);
//         } else {
//             // 当模式字符串前两位不是 "字符*"，这时只有一种选择：
//             // 1) 模式字符串的第一个字符和数据字符串的第一个字符匹配，此时
//             //    模式字符串和数据字符串都 "减少" 一位字符，变成子问题递归调用此函数
//             return isFirstMatch && isMatch(s.substr(1), p.substr(1));
//         }
//     }
// };

/**
 * 思路二：动态规划
 * 
 * 时间复杂度：O(mn)，其中 m 为数据字符串长度，n 为模式字符串长度
 * 空间复杂度：O(mn)，其中 m 为数据字符串长度，n 为模式字符串长度
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.4 MB, less than 84.78% of C++ online submissions
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        // 为了索引方便，s、p 前各填充一个占位字符
        // 此时 s[i]、p[j] 直接能表示 s 的前 i 个字符和 p 的前 j 个字符
        s.insert(0, "_");
        p.insert(0, "_");
        // dp 二维数组，dp[i][j] 表示 s 的前 i 个字符和 p 的前 j 个字符是否能匹配
        // vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        bool dp[22][32];
        // 1) 第零列第零行，表示 s、p 都为空字符串，此时二者匹配
        dp[0][0] = true;
        // 2) 第零列，表示 p 为空字符串，此时只有 s 也是空字符串才能匹配
        for (int i = 1; i <= m; i++) {
            dp[i][0] = false;
        }
        // 3) 第零行，表示 s 为空字符串，此时只有 p 也是空字符串都是 "字符*"才能匹配
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j % 2 == 0 && p[j] == '*' && dp[0][j - 2];
        }
        // 4) 从上往下、从左往右填写 dp 数组：
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j] != '.' && p[j] != '*') {
                    // 如果 p[j] 为字符，那么只有一种情况
                    // 1) p 中字符匹配 s 中一个字符，那么可以将其转成子问题 dp[i - 1][j - 1]
                    dp[i][j] = s[i] == p[j] && dp[i - 1][j - 1];
                } else if (p[j] == '.') {
                    // 如果 p[j] 为点号，那么只有一种情况
                    // 1) p 中点号匹配 s 中一个字符，那么可以将其转成子问题 dp[i - 1][j - 1]
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j] == '*') {
                    // 如果 p[j] 为星号，那么会有两种情况
                    // 1) p 中 "字符*" 匹配 s 中零个字符，那么可以将其转成子问题 dp[i][j - 2]
                    // 2) p 中 "字符*" 匹配 s 中一个字符，那么可以将其转成子问题 dp[i - 1][j]
                    dp[i][j] = dp[i][j - 2] || ((p[j - 1] == s[i] || p[j - 1] == '.') && dp[i - 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string s = "aa";
    string p = "a";
    bool ans = solution->isMatch(s, p);
    cout << ans << endl;
}
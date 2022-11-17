/*************************************************
Author: wenhaofang
Date: 2022-11-17
Description: leetcode516 - Longest Palindromic Subsequence
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
#include <cstring> // 新增

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
 * 理论时间复杂度：O(n ^ 2)，其中 n 为字符串长度
 * 理论空间复杂度：O(n ^ 2)，其中 n 为字符串长度
 * 
 * 实际时间复杂度：Runtime: 62 ms, faster than 97.32% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 10.6 MB, less than 86.04% of C++ online submissions
 */

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // 特判
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        // 定义数组，dp[i][j] 表示以 s[i] 开头且 s[j] 结尾的子问题的结果，即最长回文子序列的长度，注意，子序列是不要求连续的，而且，i 必须小于等于 j
        int dp[n][n];
        memset(dp, 0, sizeof(dp)); // ?
        // 填充数组
        // 边界情况，dp[i][j] 表示以 s[i] 开头且 s[j] 结尾的子问题的结果，当 i == j 时，结果为1，因为有且只有一个元素
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        // 填充数组
        // 其余情况，dp[i][j] = dp[i + 1][j - 1] + 2            ，当 s[i] == s[j] 时成立
        //          dp[i][j] = max(dp[i + 1][j] , dp[i][j - 1])，当 s[i] != s[j] 时成立
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j] , dp[i][j - 1]);
                }
            }
        }
        // 返回结果
        return dp[0][n - 1];
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string s = "bbbab";
    int ans = solution -> longestPalindromeSubseq(s);
    cout << ans << endl;
}
/*************************************************
Author: wenhaofang
Date: 2022-11-17
Description: leetcode1143 - Longest Common Subsequence
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
 * 理论时间复杂度：O(m * n)，其中 m、n 分别为两个字符串的长度
 * 理论空间复杂度：O(m * n)，其中 m、n 分别为两个字符串的长度
 * 
 * 实际时间复杂度：Runtime: 11 ms, faster than 96.56% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 10.6 MB, less than 87.05% of C++ online submissions
 */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 特判
        int m = text1.size();
        int n = text2.size();
        if (m == 0) {
            return 0;
        }
        if (n == 0) {
            return 0;
        }
        // 定义数组，dp[i][j] 表示当 text1 长度为 i 且 text2 长度为 j 时子问题的结果，即最长公共子序列的长度，注意，子序列是不要求连续的
        int dp[m + 1][n + 1];
        // 填充数组
        // 边界情况，dp[i][0] 表示当 text1 长度为 i 且 text2 长度为 0 时子问题的结果，为零，因为 text2 长度为 0
        //          dp[0][j] 表示当 text1 长度为 0 且 text2 长度为 j 时子问题的结果，为零，因为 text1 长度为 0
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 0;
        }
        // 填充数组
        // 其余情况，dp[i][j] = dp[i - 1][j - 1] + 1            ，当 text1[i - 1] == text2[j - 1] 时成立，注意，由于 text1 和 text2 的长度分别为 i 和 j，所以 text1[i - 1] 和 text2[j - 1] 才表示当前字符
        //          dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1])，当 text1[i - 1] != text2[j - 1] 时成立，注意，由于 text1 和 text2 的长度分别为 i 和 j，所以 text1[i - 1] 和 text2[j - 1] 才表示当前字符
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j]  = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        // 返回结果
        return dp[m][n];
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string text1 = "abcde";
    string text2 = "ace";
    int ans = solution -> longestCommonSubsequence(text1, text2);
    cout << ans << endl;
}
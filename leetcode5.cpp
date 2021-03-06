/*************************************************
Author: wenhaofang
Date: 2021-03-08
Description: leetcode5 - Longest Palindromic Substring
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
 * 思路一：暴力搜索
 * 
 * 时间复杂度：O(n^2)，其中 n 为字符串长度
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 20 ms, faster than 83.07% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.8 MB, less than 99.08% of C++ online submissions
 */
// class Solution {
// public:
//     /**查找以 (left,right) 为中心的回文字符串
//      * 如果 left == right，那么可以查找以单个独立字符为中心的回文字符串
//      * 如果 left != right，那么可以查找以两个相邻字符为中心的回文字符串
//      * 这样就可以将两种情况合并到一个函数中处理
//      */
//     pair<int, int> findPalindromic(const string& s, int left, int right) {
//         while (left >= 0 && right < s.size() && s[left] == s[right]) {
//             left -= 1;
//             right += 1;
//         };
//         // 如果最终 left + 1 <= right - 1，则表示存在符合条件的回文子串，且其始末索引分别为 (left + 1, right - 1)
//         // 如果最终 left + 1 >  right - 1，则表示没有符合条件的回文子串
//         return {left + 1, right - 1};
//     }

//     string longestPalindrome(string s) {
//         int n = s.size();
//         // start: 最长回文子串的开始位置
//         //  end : 最长回文子串的结束位置
//         int start = 0, end = 0;
//         // 对于字符串中的每一个字符处理
//         for (int i = 0; i < n; i++) {
//             // 查找以 i 为中心的回文子串
//             auto [l1, r1] = findPalindromic(s, i, i);
//             if (r1 - l1 > end - start) {
//                 start = l1;
//                 end = r1;
//             }
//             // 查找以 (i, i + 1) 为中心的回文子串
//             auto [l2, r2] = findPalindromic(s, i, i + 1);
//             if (r2 - l2 > end - start) {
//                 start = l2;
//                 end = r2;
//             }
//         }
//         return s.substr(start, end - start + 1);
//     }
// };

/**
 * 思路二：动态规划
 * 
 * 时间复杂度：O(n^2)，其中 n 为字符串长度
 * 空间复杂度：O(n^2)，其中 n 为字符串长度
 * 
 * 实际时间复杂度：Runtime: 748 ms, faster than 8.97% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 47.3 MB, less than 30.72% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 如果 s[i .. j] 是回文字符串，那么 s[i + 1 .. j - 1] 也必是回文字符串
 * 
 * 设 dp(i, j) 表示以 i、j 为始末索引的子串是否为回文字符串
 * 
 * if j == i    , dp(i, j) = true
 * if j == i + 1, dp(i, j) = (s[i] == s[j])
 * otherwise    , dp(i, j) = (dp(i + 1, j - 1) && s[i] == s[j])
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        // dp 二维数组，dp[i][j] 表示以 i、j 为始末索引的子串是否为回文字符串
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // 从下往上、从右往左填写 dp 数组
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= i; j--) {
                if (j == i) {
                    dp[i][j] = true;
                } else if (j == i + 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
                }
                // 若以 i、j 为始末索引的子串为回文字符串
                // 且其长度 j - i + 1 大于 ans.size()，则更新 ans
                if (dp[i][j] && (j - i + 1 > ans.size())) {
                    ans = s.substr(i, j - i + 1);
                }
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
    string s = "babad";
    string ans = solution->longestPalindrome(s);
    cout << ans << endl;
}
/*************************************************
Author: wenhaofang
Date: 2022-02-15
Description: leetcode72 - Edit Distance
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
 * 实际时间复杂度：Runtime: 12 ms, faster than 73.43% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 9 MB, less than 33.28% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 根据题意可知，对一个单词可进行三种操作，分别是插入一个字符、删除一个字符、替换一个字符
 * 
 * 现在题目给定两个单词，因此共有六种操作，但其中有些操作是等价的，归纳起来还是有三种方法
 * 
 * 1. 在单词 A 中插入一个字符，该操作等价于在单词 B 中删除一个字符
 * 
 *    如果我们知道 `hors` 到 `ros` 的编辑距离为 a，那么 `horse` 到 `ros` 的标记距离不会超过 a + 1（在单词 A 最后添加字母 `e`）
 * 
 * 2. 在单词 B 中插入一个字符，该操作等价于在单词 A 中删除一个字符
 * 
 *    如果我们知道 `horse` 到 `ro` 的编辑距离为 b，那么 `horse` 到 `ros` 的标记距离不会超过 b + 1（在单词 B 最后添加字母 `s`）
 * 
 * 3. 在单词 A 中替换一个字符，该操作等价于在单词 B 中替换一个字符
 * 
 *    如果我们知道 `hors` 到 `ros` 的编辑距离为 c，那么 `horse` 到 `ros` 的标记距离不会超过 c + 1（将单词 A 最后一个字母 `e` 替换为 `s`）
 * 
 * 设置二维 dp 数组，dp[i][j] 表示单词 A 前 i 个字符和单词 B 前 j 个字符之间的编辑距离
 * 
 * 状态转移方程为：dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1)
 */
class Solution {
public:
    int myMin(int a, int b, int c) {
        return min(min(a, b), c);
    }

    int minDistance(string word1, string word2) {
        // 特判
        int m = word1.length();
        int n = word2.length();
        if (m == 0) {
            return n;
        }
        if (n == 0) {
            return m;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // 确定边界
        for (int i = 0; i < m + 1; i++) { // word1 为空字符串
            dp[i][0] = i;
        }
        for (int j = 0; j < n + 1; j++) { // word2 为空字符串
            dp[0][j] = j;
        }
        // 逐步填表
        for (int i = 1; i < m + 1; i++) {
            // 这里有一种情况要注意
            // 若两个字符串最后一个字符相等，则无需进行替换操作也是正确的
            // 由于数组在最前面加了空字符串，所以在判断字符是否相等时索引需要减一
            for (int j = 1; j < n + 1; j++) {
                // dp[i][j] = myMin(
                //     dp[i - 1][j] + 1,
                //     dp[i][j - 1] + 1,
                //     dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1)
                // );
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = myMin(
                        dp[i - 1][j] + 1,
                        dp[i][j - 1] + 1,
                        dp[i - 1][j - 1] + 1
                    );
                }
            }
        }
        // 读取结果
        return dp[m][n];
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string word1 = "horse";
    string word2 = "ros";
    int ans = solution -> minDistance(word1, word2);
    cout << ans << endl;
}
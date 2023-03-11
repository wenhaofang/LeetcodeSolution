/*************************************************
Author: wenhaofang
Date: 2023-03-12
Description: leetcode139 - Word Break
*************************************************/

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>

using std::list;
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
using std::atoi;
using std::stoi;
using std::to_string;
using std::cin;
using std::cout;
using std::endl;

/**
 * 方法一：动态规划
 * 
 * 理论时间复杂度：O(n^2)，其中 n 为字符串长度
 * 理论空间复杂度：O(n)  ，其中 n 为字符串长度
 */
/**
 * 思路
 * 
 * 试着用动态规划的思路，设 dp[i] 表示 s[0..i] 是否匹配
 * 
 * 如果 dp[i] 想要匹配，有 dp[j] 为 ture 且 s[j+1..i] 在 wordDict，其中 j < i
 * 
 * 还有两个难点：
 * 
 * 1. 为了统一处理空字符串，dp 数组大小为 s.size() + 1，此时后续处理注意下标对应 ( 类似前驱节点 )
 * 
 * 2. 判断 s[j+1..i] 是否在 wordDict，可以将 wordDict 转为 unordered_set ( 很经典的操作 )
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 特判
        int n = s.size();
        if (n == 0) {
            return true;
        }
        // 哈希集合
        unordered_set<string> set;
        for (string word: wordDict) {
            set.insert(word);
        }
        // 动态规划
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = dp[j] && (set.find(s.substr(j, i - j)) != set.end());
                if (dp[i]) {
                    break;
                }
            }
        }
        // 返回结果
        return dp[n];
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    bool ans = solution -> wordBreak(s, wordDict);
    cout << ans << endl;
}
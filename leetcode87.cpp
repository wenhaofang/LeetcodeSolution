/*************************************************
Author: wenhaofang
Date: 2022-02-28
Description: leetcode87 - Scramble String
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
 * 理论时间复杂度：O(n^4)，其中 n 为字符串长度
 * 理论空间复杂度：O(n^3)，其中 n 为字符串长度
 * 
 * 实际时间复杂度：Runtime: 20 ms, faster than 86.25% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 17.4 MB, less than 72.36% of C++ online submissions
 */
class Solution {
private:
    // 记忆化数组，-1 表示 false、1 表示 true、0 表示未计算
    int memo[30][30][31];
    // 局部变量赋值为全局变量，避免大量的参数传递
    string s1, s2;

public:
    // 判断两个字符串是否存在某个字符出现的次数不相同
    // 字符串 s1 从下标 i 开始，长度为 length
    // 字符串 s2 从下标 j 开始，长度为 length
    bool isSimilar(int i, int j, int length) {
        unordered_map<int, int> freq;
        for (int k = i; k < i + length; k++) {
            freq[s1[k]] += 1;
        }
        for (int k = j; k < j + length; k++) {
            freq[s2[k]] -= 1;
        }
        for (const auto & item: freq) {
            if (item.second != 0) {
                return false;
            }
        }
        return true;
    }

    // 判断两个字符串是否满足题目要求
    // 字符串 s1 从下标 i 开始，长度为 length
    // 字符串 s2 从下标 j 开始，长度为 length
    bool dfs(int i, int j, int length) {
        // 首先搜索记忆化数组
        if (memo[i][j][length]) {
            return memo[i][j][length] == 1;
        }
        // 判断两个子串是否相等
        // 如果相等，则立即返回 true
        if (s1.substr(i, length) == s2.substr(j, length)) {
            memo[i][j][length] = 1;
            return true;
        }
        // 判断两个子串是否存在某个字符出现的次数不相同
        // 如果存在，则立即返回 false
        if (!isSimilar(i, j, length)) {
            memo[i][j][length] = -1;
            return false;
        }
        // 枚举分割位置
        for (int k = 1; k < length; k++) {
            // 不交换的情况
            if (
                dfs(i, j, k) &&
                dfs(i + k, j + k, length - k)
            ) {
                memo[i][j][length] = 1;
                return true;
            }
            // 要交换的情况
            if (
                dfs(i, j + length - k, k) &&
                dfs(i + k, j, length - k)
            ) {
                memo[i][j][length] = 1;
                return true;
            }
        }
        // 在其余情况下
        memo[i][j][length] = -1;
        return false;
    }

    bool isScramble(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        if (m != n) {
            return false;
        }
        memset(memo, 0, sizeof(memo));
        this -> s1 = s1;
        this -> s2 = s2;
        return dfs(0, 0, m);
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string s1 = "great";
    string s2 = "rgeat";
    bool ans = solution -> isScramble(s1, s2);
    cout << ans << endl;
}
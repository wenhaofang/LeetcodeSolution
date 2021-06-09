/*************************************************
Author: wenhaofang
Date: 2021-03-19
Description: leetcode14 - Longest Common Prefix
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
 * 思路一：暴力模拟，纵向比较
 * 
 * 时间复杂度：O(mn)，其中 m 是字符串的数量，n 是字符串的平均长度
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 9 MB, less than 92.57% of C++ online submissions
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 前处理，特殊情况
        // 若字符串数组为空，那么没有最长公共前缀
        int strSize = strs.size();
        if (strSize == 0) {
            return "";
        }
        // 计算字符串数组中最长字符串的长度
        // 这也是最长公共前缀的最长长度
        int maxSize = 201;
        for (int j = 0; j < strSize; j++) {
            if (maxSize > strs[j].size()) {
                maxSize = strs[j].size();
            }
        }
        // 顺序比较字符串数组中同一索引的字符
        // 其中 i 表示字符索引，j 表示字符串索引
        string ans;
        for (int i = 0; i < maxSize; i++) {
            char c = strs[0][i];
            for (int j = 0; j < strSize; j++) {
                if (strs[j][i] != c) {
                    return ans;
                }
            }
            ans += c;
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<string> strs = {"flower", "flow", "flight"};
    string ans = solution->longestCommonPrefix(strs);
    cout << ans << endl;
}
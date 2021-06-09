/*************************************************
Author: wenhaofang
Date: 2021-03-11
Description: leetcode8 - String to Integer (atoi)
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
 * 思路一：暴力模拟
 * 
 * 时间复杂度：O(n)，其中 n 为字符串长度
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7 MB, less than 81.75% of C++ online submissions
 */
class Solution {
public:
    int myAtoi(string s) {
        int ptr = 0; // 指针
        int pos = 0; // 符号
        int ans = 0; // 答案
        // 去除前导空格
        while (isspace(s[ptr])) {
            ptr++;
        }
        // 判断符号
        if (s[ptr] != '+' && s[ptr] != '-') {
            pos = 1;
        } else if (s[ptr] == '+') {
            pos = 1;
            ptr++;
        } else if (s[ptr] == '-') {
            pos = -1;
            ptr++;
        }
        // 读取数字
        while (isdigit(s[ptr])) {
            // 将当前字符转成数字
            int cur = pos * (s[ptr] - '0');
            // 判断是否溢出，如果溢出则截断后立即返回
            if (pos == 1  && ans > (INT_MAX - cur) / 10) return INT_MAX;
            if (pos == -1 && ans < (INT_MIN - cur) / 10) return INT_MIN;
            // 如果没有溢出，将当前数字加入到答案
            ans = ans * 10 + cur;
            ptr++;
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string s = "42";
    int ans = solution->myAtoi(s);
    cout << ans << endl;
}
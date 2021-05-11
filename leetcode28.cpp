/*************************************************
Author: wenhaofang
Date: 2021-05-10
Description: leetcode28 - Implement strStr()
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
 * 方法一：暴力模拟
 * 
 * 时间复杂度：O(m * n)，其中 m、n 分别是 haystack、needle 字符串的长度
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.8 MB, less than 62.02% of C++ online submissions
 */
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int m = haystack.size();
//         int n = needle.size();
//         // 前处理
//         if (n == 0) {
//             return 0;
//         }
//         // 以文本字符串的每一个字符作为起始字符
//         for (int i = 0; i <= m - n; i++) {
//             // 特判，加速
//             if (haystack[i] != needle[0]) {
//                 continue;
//             }
//             // 与模式字符串的每一个字符进行比较
//             bool isMatch = true;
//             for (int j = 0; j < n; j++) {
//                 if (haystack[i + j] != needle[j]) {
//                     isMatch = false;
//                     break;
//                 }
//             }
//             if (isMatch) {
//                 return i;
//             }
//         }
//         // 后处理
//         return -1;
//     }
// };

/**
 * 方法二：Knuth-Morris-Pratt (KMP)
 * 
 * 理论时间复杂度：O(m + n)，其中 m、n 分别是 haystack、needle 字符串的长度
 * 理论空间复杂度：O(n)，其中 n 是 needle 字符串的长度
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7.1 MB, less than 12.72% of C++ online submissions
 */
/**
 * 该算法有两个关键步骤：一是对模式字符串构建前缀数组，二是根据前缀数组来匹配文本字符串和模式字符串
 * 
 * 1、对模式字符串构建前缀数组
 * 
 * 定义前缀函数 f(i)，对于长度为 n 的字符串 s，f(i)(0 <= i < n) 表示子串 s[0:i] 最长的相等的真前缀与真后缀的长度
 * 
 * 举个例子：对于字符串 aabaaab，求前缀数组
 * 
 * f(0) = 0，因为 s[0:0] = a
 * f(1) = 1，因为 s[0:1] = (a)(a)
 * f(2) = 0，因为 s[0:2] = aab
 * f(3) = 1，因为 s[0:3] = (a)ab(a)
 * f(4) = 2，因为 s[0:4] = (aa)b(aa)
 * f(5) = 2，因为 s[0:5] = (aa)ba(aa)
 * f(6) = 3，因为 s[0:6] = (aab)a(aab)
 * 
 * 2、根据前缀数组来匹配文本字符串和模式字符串
 * 
 * 在原始思路中，当以下标 i 为起始字符的文本字符子串与模式字符串不匹配时，下标后移一位继续比较
 * 
 * 即比较以下标 i + 1 为起始字符的文本字符子串与模式字符串，若还是不匹配，重复上述过程直到末尾
 * 
 * 使用前缀数组，可以在文本字符子串与模式字符串不匹配时，根据前缀数组的指示前移若干位继续比较，从而极大地减少重复的比较
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        // 前处理
        if (n == 0) {
            return 0;
        }
        // 1、构建前缀数组
        vector<int> prefix(n);
        for (int i = 1, j = 0; i < n; i++) {
            // 状态回退
            while (j > 0 && needle[i] != needle[j]) {
                j = prefix[j - 1];
            }
            // 当前字符是否相等
            if (needle[i] == needle[j]) {
                j++;
            }
            // 填写数组
            prefix[i] = j;
        }
        // 2、匹配
        for (int i = 0, j = 0; i < m; i++) {
            // 状态回退
            while (j > 0 && haystack[i] != needle[j]) {
                j = prefix[j - 1];
            }
            // 当前字符是否相等
            if (haystack[i] == needle[j]) {
                j++;
            }
            // 是否到达模式字符串末尾
            if (j == n) {
                return i - n + 1;
            }
        }
        // 后处理
        return -1;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string haystack = "hello";
    string needle = "ll";
    int ans = solution->strStr(haystack, needle);
    cout << ans << endl;
}
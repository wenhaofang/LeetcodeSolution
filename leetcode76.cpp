/*************************************************
Author: wenhaofang
Date: 2022-02-19
Description: leetcode76 - Minimum Window Substring
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
 * 方法一：滑动窗口
 * 
 * 理论时间复杂度：O(m + n)，其中 m、n 分别为字符串的长度
 * 理论空间复杂度：O(m + n)，其中 m、n 分别为字符串的长度
 * 
 * 实际时间复杂度：Runtime: 127 ms, faster than 12.93% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7.9 MB, less than 40.33% of C++ online submissions
 */
// class Solution {
// public:
//     bool check(
//         unordered_map<char, int>& output,
//         unordered_map<char, int>& expect
//     ) {
//         for (const auto & item: expect) {
//             if (output[item.first] < item.second) {
//                 return false;
//             }
//         }
//         return true;
//     }

//     string minWindow(string s, string t) {
//         // 一、初始化辅助数据结构
//         // 哈希集合和哈希映射通常搭配双指针使用
//         // 这里用于快速判断当前子串是否符合要求
//         unordered_map<char, int> output; // 目前子串的字符数量，对应字符串 s
//         unordered_map<char, int> expect; // 目标要求的字符数量，对应字符串 t
//         for (char & c: t) {
//             expect[c] += 1;
//         }

//         // 二、初始化指针值和答案
//         int n = s.length();
//         int p1 = 0 ; // 左指针
//         int p2 = -1; // 右指针
//         int len = INT_MAX; // 目前答案长度
//         int ansL = -1;     // 目前答案的左索引
//         int ansR = -1;     // 目前答案的右索引

//         // 三、主循环，右指针到达字符串末尾停止
//         while (p2 < n) {
//             // 右指针前移一步
//             p2++;
//             // 将右指针指向的值加入集合
//             output[s[p2]] += 1;

//             while  (p1 <= p2 && check(output, expect)) {
//                 // 更新答案
//                 if (len > p2 - p1 + 1) {
//                     len = p2 - p1 + 1;
//                     ansL = p1;
//                     ansR = p2;
//                 }
//                 // 将左指针指向的值从集合中删除
//                 output[s[p1]] -= 1;
//                 // 左指针前移一步
//                 p1++;
//             }
//         }

//         // 四、返回答案
//         return len == INT_MAX ? "" : s.substr(ansL, len);
//     }
// };

/**
 * 方法二：滑动窗口
 * 
 * 理论时间复杂度：O(m + n)，其中 m、n 分别为字符串的长度
 * 理论空间复杂度：O(C)，其中 C 为字符集大小
 * 
 * 实际时间复杂度：Runtime: 4 ms, faster than 98.75% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7.5 MB, less than 93.99% of C++ online submissions
 */
class Solution {
public:
    string minWindow(string s, string t) {
        // 一、初始化辅助数据结构
        vector<int> expect(123, 0); // 字符对应的整型：'A' -> 65, 'Z' -> 90, 'a' -> 97, 'z' -> 122
        for (char & c: t) {
            expect[c] += 1;
        }

        // 二、初始化指针值和答案
        int n = s.length(); // 字符串 s 的长度
        int m = t.length(); // 字符串 t 的长度
        int p1 = 0 ; // 左指针
        int p2 = -1; // 右指针
        int sumLen = 0;       // 合法字符数量
        int ansLen = INT_MAX; // 目前答案长度
        int ansL = -1;     // 目前答案的左索引
        int ansR = -1;     // 目前答案的右索引

        // 三、主循环，右指针到达字符串末尾停止
        while(p2 < n) {
            if(sumLen < m) {
                // 若合法字符数量小于目标字符串，说明当前子串不合法
                // 则右指针必须前移一步继续寻找，同时更新计数数组和合法字符数量
                p2++;
                expect[s[p2]] -= 1;
                if (expect[s[p2]] >= 0) {
                    sumLen += 1;
                }
            } else {
                // 若合法字符数量大于等于目标字符串，说明当前子串合法
                // 则可以更新答案，然后根据贪心策略，左指针前移一步，同时更新计数数组和合法字符数量
                if (ansLen > p2 - p1 + 1) {
                    ansLen = p2 - p1 + 1;
                    ansL = p1;
                    ansR = p2;
                }
                if (expect[s[p1]] >= 0) {
                    sumLen -= 1;
                }
                expect[s[p1]] += 1;
                p1++;
            }
        }

        // 四、返回答案
        return ansLen == INT_MAX ? "" : s.substr(ansL, ansLen);
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string ans = solution -> minWindow(s, t);
    cout << ans << endl;
}
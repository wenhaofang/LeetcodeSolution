/*************************************************
Author: wenhaofang
Date: 2021-03-06
Description: leetcode3 - Longest Substring Without Repeating Characters
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
 * 思路一：滑动窗口 + 哈希集合
 * 
 * 时间复杂度：O(n)，其中 n 是字符串长度
 * 空间复杂度：O(min(m, n))，其中 n 是字符串长度，m 是词典大小
 * 
 * 实际时间复杂度：Runtime: 12 ms, faster than 77.31% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 8.9 MB, less than 38.40% of C++ online submissions
 */
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int num = s.size();
//         // 字符集合，用于维护左右指针间的字符
//         unordered_set<char> hashSet;
//         // ans: 当前无重复字符的最长子串长度
//         // lp : 滑动窗口的左指针
//         // rp : 滑动窗口的右指针
//         int ans = 0, lp = -1, rp = -1;
//         // 右指针每次向右移动一个字符，直至到达字符串末尾
//         while (++rp < num) {
//             // 判断右指针指向的字符是否在集合中
//             if (!hashSet.count(s[rp])) {
//                 // 若字符不在集合中，则把该字符加入集合
//                 hashSet.insert(s[rp]);
//             } else {
//                 // 如果字符在集合中，左指针向右移动直至到达相同字符
//                 // 同时，把从左指针开始移动位置到左指针结束移动位置间的字符从集合中删除
//                 while (s[++lp] != s[rp]) {
//                     hashSet.erase(s[lp]);
//                 }
//             }
//             // 计算当前无重复字符的最长子串长度
//             ans = max(ans, int(hashSet.size()));
//         }
//         return ans;
//     }
// };

/**
 * 思路二：滑动窗口 + 哈希映射
 * 
 * 时间复杂度：O(n)，其中 n 是字符串长度
 * 空间复杂度：O(min(m, n))，其中 n 是字符串长度，m 是词典大小
 * 
 * 实际时间复杂度：Runtime: 8 ms, faster than 89.09% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 8.3 MB, less than 67.70% of C++ online submissions
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int num = s.size();
        // 字符映射，用于维护右指针扫过的字符及其最后一次出现的位置
        unordered_map<char, int> hashMap;
        // ans: 当前无重复字符的最长子串长度
        // lp : 滑动窗口的左指针
        // rp : 滑动窗口的右指针
        int ans = 0, lp = 0, rp = -1;
        // 右指针每次向右移动一个字符，直至到达字符串末尾
        while (++rp < num) {
            // 判断右指针指向的字符是否在映射中
            auto res = hashMap.find(s[rp]);
            // 如果字符在映射中且其最后一次出现的位置不在左指针指向位置的左边
            // 那么直接将左指针移到该字符最后一次出现位置的右边一位
            if (res != hashMap.end() && res->second >= lp) {
                lp = res->second + 1;
            }
            // 更新字符映射
            hashMap[s[rp]] = rp;
            // 计算当前无重复字符的最长子串长度
            ans = max(ans, rp - lp + 1);
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string s = "abcabcbb";
    int ans = solution->lengthOfLongestSubstring(s);
    cout << ans << endl;
}
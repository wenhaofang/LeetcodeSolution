/*************************************************
Author: wenhaofang
Date: 2022-12-05
Description: leetcode438 - Find All Anagrams in a String
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
 * 理论时间复杂度：O(m + n + a)，其中 m 为字符串 s 的长度、n 为字符串 p 的长度、a 为字符数
 * 理论空间复杂度：O(a)        ，其中 a 为字符数
 * 
 * 实际时间复杂度：Runtime: 17 ms, faster than 85.34% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 8.7 MB, less than 39.50% of C++ online submissions
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size();
        int n = p.size();
        if (m < n) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> cnt(26);

        for (int i = 0; i < n; i++) {
            --cnt[p[i] - 'a'];
        }
        for (int i = 0; i < n; i++) {
            ++cnt[s[i] - 'a'];
        }

        int var = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) {
                var++;
            }
        }
        if (var == 0) {
            ans.emplace_back(0);
        }

        int p1 = 0;
        int p2 = n - 1;
        while (true) {
            p1++;
            p2++;
            if (p2 >= m) {
                break;
            }

            if (cnt[s[p1 - 1] - 'a'] == 0) {
                var++;
            }
            if (cnt[s[p1 - 1] - 'a'] == 1) {
                var--;
            }
            --cnt[s[p1 - 1] - 'a'];

            if (cnt[s[p2] - 'a'] == 0) {
                var++;
            }
            if (cnt[s[p2] - 'a'] == -1) {
                var--;
            }
            ++cnt[s[p2] - 'a'];

            if (var == 0) {
                ans.emplace_back(p1);
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
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> ans = solution -> findAnagrams(s, p);
    for (auto item: ans) {
        cout << item << " ";
    }
}
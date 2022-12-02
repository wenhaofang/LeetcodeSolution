/*************************************************
Author: wenhaofang
Date: 2022-12-02
Description: leetcode763 - Partition Labels
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
 * 方法一：贪心算法
 * 
 * 理论时间复杂度：O(n)，其中 n 为字符串长度
 * 理论空间复杂度：O(m)，其中 m 为字符集数量
 * 
 * 实际时间复杂度：Runtime: 4 ms, faster than 82.78% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.7 MB, less than 48.30% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 题目要求将字符串划分成最多数量的区间使得同一字母只出现在一个区间
 * 
 * 也就是说区间要尽可能小，但是要保证同一个字母出现在同一个区间
 */

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        // 遍历一次字符串
        // 找出每个字符最后一次出现的位置
        unordered_map<char, int> map;
        for (int i = 0; i < n; i++) {
            map[s[i]] = i;
        }
        // 遍历一次字符串
        // 找出每个区间最少划分距离
        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            end = max(end, map[s[i]]);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        // 返回结果
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string s = "ababcbacadefegdehijhklij";
    vector<int> ans = solution -> partitionLabels(s);
    for (auto item: ans) {
        cout << item << "\n";
    }
}
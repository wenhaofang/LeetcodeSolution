/*************************************************
Author: wenhaofang
Date: 2022-12-03
Description: leetcode738 - Monotone Increasing Digits
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
 * 理论时间复杂度：O(logn)，其中 n 为数字位数
 * 理论空间复杂度：O(logn)，其中 n 为数字位数
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 5.8 MB, less than 78.51% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 从折线图的角度来看，从左往后找第一个谷顶，将这个数字减去一，将后面数字改为九，如 13542 -> 13499
 * 
 * 若第一个谷顶是平的，则找谷顶最左边的位置，将这个数字减去一，将后面数字改为九，如 15542 -> 14999
 */

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if (n < 10) {
            return n;
        }
        string s = std::to_string(n);
        int m = s.size();
        int i = 0;
        while (i < m - 1 && s[i] <= s[i + 1]) {
            i++;
        }
        if (i == m - 1) {
            return n;
        }
        while (i > 0 && s[i] == s[i - 1]) {
            i--;
        }
        s[i] = s[i] - 1;
        i++;
        while (i < m) {
            s[i] = '9';
            i++;
        }
        return stoi(s);
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int n = 10;
    int ans = solution -> monotoneIncreasingDigits(n);
    cout << ans << "\n";
}
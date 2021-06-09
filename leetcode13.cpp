/*************************************************
Author: wenhaofang
Date: 2021-03-18
Description: leetcode13 - Roman to Integer
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
 * 思路一：找规律
 * 
 * 时间复杂度：O(1)
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 5.9 MB, less than 95.89% of C++ online submissions
 */
/**
 * 如果不存在 4、9、40、90、400、900 等特殊情况，
 * 直接顺序获取字符对应的数字，将它们相加即可得到答案，例如:
 *     LVIII -> 50 + 5 + 1 + 1 + 1 = 58
 * 
 * 而如果存在 4、9、40、90、400、900 等特殊情况，
 * 不难发现一个规律，即如果小值在大值左边，则小值变成负数相加即是期望值，例如
 *     IV -> (-1) + 5 = 4
 *     IX -> (-1) + 10 = 9
 *     XL -> (-10) + 50 = 40
 *     XC -> (-10) + 100 = 90
 *     CD -> (-100) + 500 = 400
 *     CM -> (-100) + 1000 = 900
 */
class Solution {
public:
    int romanToInt(string s) {
        int size = s.length();
        int ans = 0; // 符号
        int pos = 1; // 数字
        for (int i = 0; i < size; i++) {
            int curr = getValue(s[i]);
            int next = getValue(s[i + 1]);
            pos = curr >= next ? 1 : -1;
            ans = ans + pos * curr;
        }
        return ans;
    }

    /**
     * 获取符号对应的值
     */
    int getValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default : return 0;
        }
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string s = "III";
    int ans = solution->romanToInt(s);
    cout << ans << endl;
}
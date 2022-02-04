/*************************************************
Author: wenhaofang
Date: 2022-02-10
Description: leetcode67 - Add Binary
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
 * 方法一：暴力模拟
 * 
 * 理论时间复杂度：O(max(m, n))，其中 m、n 分别为两个字符串的长度
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.3 MB, less than 84.94% of C++ online submissions
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        string ans;
        int n = 0;
        int c = 0;
        // char - '0' -> int
        // int + '0' -> char
        while (i >= 0 && j >= 0) {
            n = (a[i] - '0') + (b[j] - '0') + c;
            ans.push_back((n % 2) + '0');
            c = n / 2;
            i--;
            j--;
        }
        while (i >= 0) {
            n = (a[i] - '0') + c;
            ans.push_back((n % 2) + '0');
            c = n / 2;
            i--;
        }
        while (j >= 0) {
            n = (b[j] - '0') + c;
            ans.push_back((n % 2) + '0');
            c = n / 2;
            j--;
        }
        if (c == 1) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string a = "11";
    string b = "1";
    string ans = solution -> addBinary(a, b);
    cout << ans << endl;
}
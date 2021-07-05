/*************************************************
Author: wenhaofang
Date: 2021-07-05
Description: leetcode38 - Count and Say
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
 * 方法一：迭代
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.2 MB, less than 99.66% of C++ online submissions
 */
class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        string next = "";
        while (--n) {
            int p1 = 0;
            int p2 = 0;
            while (p1 < prev.length()) {
                while (p2 < prev.length()) {
                    if (prev[p1] == prev[p2]) {
                        p2 += 1;
                    } else break;
                }
                next.push_back(p2 - p1 + 48);
                next.push_back(prev[p1]);
                p1 = p2;
            }
            prev = next;
            next = "";
        }
        return prev;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int n = 4;
    string ans = solution -> countAndSay(n);
    cout << ans << endl;
}
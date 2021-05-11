/*************************************************
Author: wenhaofang
Date: 2021-05-11
Description: leetcode29 - Divide Two Integers
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
 * 方法一：倍增
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 5.9 MB, less than 22.33% of C++ online submissions
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        // 特判
        if (dividend == 0) {
            return 0;
        } else if (divisor == 1) {
            return dividend;
        } else if (divisor == -1) {
            return dividend == INT_MIN ? INT_MAX : -dividend;
        } else if (dividend == 1 || dividend == -1) {
            return 0;
        }
        // 符号
        int sign = 1;
        if (dividend < 0) {
            sign = -sign;
        } else {
            dividend = -dividend;
        }
        if (divisor < 0) {
            sign = -sign;
        } else {
            divisor = -divisor;
        }
        // 数字
        int ans = div(dividend, divisor);
        // 返回
        return sign * ans;
    }

    // 计算两个负数间的除法（递归）
    int div(int dividend, int divisor) {
        if (dividend > divisor) {
            return 0;
        }
        int ans = 1;
        int cur = divisor;
        while (
            INT_MIN - cur <= cur &&
            cur + cur >= dividend
        ) {
            cur += cur;
            ans += ans;
        }
        return ans + div(dividend - cur, divisor);
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int dividend = 7;
    int divisor = -3;
    int ans = solution->divide(dividend, divisor);
    cout << ans << endl;
}
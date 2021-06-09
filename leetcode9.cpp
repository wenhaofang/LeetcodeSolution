/*************************************************
Author: wenhaofang
Date: 2021-03-12
Description: leetcode9 - Palindrome Number
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
 * 思路一：反转整个数字后比较
 * 
 * 时间复杂度：O(log(n))，其中 n 为数字大小
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 8 ms, faster than 79.15% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 5.9 MB, less than 82.80% of C++ online submissions
 */
// class Solution {
// public:
//     // 反转一个整数，参考 leetcode7
//     int reverse(int x) {
//         int ans = 0;
//         while (x != 0) {
//             if (x > 0 && ans > (INT_MAX - x % 10) / 10) return 0;
//             if (x < 0 && ans < (INT_MIN - x % 10) / 10) return 0;
//             ans = ans * 10 + x % 10;
//             x = x / 10;
//         }
//         return ans;
//     }

//     bool isPalindrome(int x) {
//         if (x < 0) return false;
//         if (x == 0) return true;
//         return x == reverse(x);
//     }
// };

/**
 * 思路二：反转一半数字后比较
 * 
 * 时间复杂度：O(log(n))，其中 n 为数字大小
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 4 ms, faster than 94.60% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 5.8 MB, less than 93.48% of C++ online submissions
 */
class Solution {
public:
    bool isPalindrome(int x) {
        // 前处理，特殊情况
        // 如果 x 小于 0，那么它必不可能是回文数
        // 如果 x 最后一位为 0 且其本身不是 0，那么它也不可能是回文数
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        // x 用于储存原数的前半部分数字，y 用于储存原数的后半部分数字
        // 每次去掉 x 的最后一位，并将该数字加入 y，直至 x <= y
        // 此时数字 x 的位数等于数字 y 的位数或等于数字 y 的位数加 1
        int y = 0;
        while (x > y) {
            y = y * 10 + x % 10;
            x = x / 10;
        }
        // 一个数字是回文数分为两种情况:
        // 1. 以一个字符为回文中心，例如原数 x = 121， 那么处理后的 x = 1,  y = 12，此时 x == y / 10
        // 2. 以两个字符为回文中心，例如原数 x = 1221，那么处理后的 x = 12, y = 12，此时 x == y
        return (x == y || x == y / 10);
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int x = 121;
    bool ans = solution->isPalindrome(x);
    cout << ans << endl;
}
/*************************************************
Author: wenhaofang
Date: 2021-03-10
Description: leetcode7 - Reverse Integer
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
 * 思路一：数字反序加入答案，要注意溢出的情况
 * 
 * 时间复杂度：O(log(n))，其中 n 为数字大小
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 4 ms, faster than 45.27% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 5.9 MB, less than 84.65% of C++ online submissions
 */
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            // 如果 x > 0 且 ans * 10 + x % 10 > INT_MAX
            // 即表明 ans * 10 + x % 10 上溢出，直接返回 0
            if (x > 0 && ans > (INT_MAX - x % 10) / 10) return 0;
            // 如果 x < 0 且 ans * 10 + x % 10 < INT_MIN
            // 即表明 ans * 10 + x % 10 下溢出，直接返回 0
            if (x < 0 && ans < (INT_MIN - x % 10) / 10) return 0;
            // 其他情况下，每次取 x 的最后一位加到 ans 中
            ans = ans * 10 + x % 10;
            x = x / 10;
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int x = 123;
    int ans = solution->reverse(x);
    cout << ans << endl;
}
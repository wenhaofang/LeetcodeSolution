/*************************************************
Author: wenhaofang
Date: 2022-02-12
Description: leetcode69 - Sqrt(x)
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
 * 方法一：顺序查找
 * 
 * 理论时间复杂度：O(x)
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 43 ms, faster than 5.13% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 5.8 MB, less than 74.30% of C++ online submissions
 */
// class Solution {
// public:
//     int mySqrt(int x) {
//         long long int ans = -1;
//         for (long long int i = 0, j = 0; i <= x; i = i + 1, j = i * i) {
//             if (j == x) {
//                 ans = i;
//                 break;
//             } else if (j > x) {
//                 ans = i - 1;
//                 break;
//             }
//         }
//         return ans;
//     }
// };

/**
 * 方法二：二分查找
 * 
 * 理论时间复杂度：O(logx)
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 5.8 MB, less than 95.59% of C++ online submissions
 */
class Solution {
public:
    int mySqrt(int x) {
        int p1 = 0;
        int p2 = x;
        int ans = -1;
        while (p1 <= p2) {
            long long int m = p1 + (p2 - p1) / 2;
            long long int n = m * m;
            if (n == x) {
                return m;
            } else if (n < x) {
                p1 = m + 1;
            } else if (n > x) {
                p2 = m - 1;
            }
        }
        return p1 - 1;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int x = 99;
    int ans = solution -> mySqrt(x);
    cout << ans << endl;
}
/*************************************************
Author: wenhaofang
Date: 2022-01-26
Description: leetcode50 - Pow(x, n)
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
 * 方法一：递归（快速幂）
 * 
 * 理论时间复杂度：O(logn)，其中 n 为幂次
 * 理论空间复杂度：O(logn)，其中 n 为幂次
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6 MB, less than 16.69% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 该问题存在子问题，具体如下：x^(n) = x^(n-1) * x
 */
// class Solution {
// public:
//     double myPowHelper(double x, long long int N) {
//         // 递归边界
//         if (N == 0) {
//             return 1.0;
//         }
//         // 递归过程
//         double y = myPowHelper(x, N / 2);
//         return N % 2 == 0 ? y * y : y * y * x;
//     }

//     double myPow(double x, int n) {
//         long long int N = n;
//         return N >= 0 ? myPowHelper(x, N) : 1.0 / myPowHelper(x, -N);
//     }
// };

/**
 * 方法二：迭代（快速幂）
 * 
 * 理论时间复杂度：O(logn)，其中 n 为幂次
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 5.9 MB, less than 41.79% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 实际上就是倍增法
 */
class Solution {
public:
    double myPowHelper(double x, long long int N) {
        double y = x;
        double ans = 1.0;
        while (N > 0) {
            if(N % 2 == 1) {
                ans *= y;
            }
            y *= y;
            N /= 2;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long int N = n;
        return N >= 0 ? myPowHelper(x, N) : 1.0 / myPowHelper(x, -N);
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    double x = 2.00000;
    int n = 10;
    double ans = solution -> myPow(x, n);
    cout << ans << endl;
}
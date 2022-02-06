/*************************************************
Author: wenhaofang
Date: 2022-02-13
Description: leetcode70 - Climbing Stairs
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
 * 方法一：动态规划
 * 
 * 理论时间复杂度：O(n)
 * 理论空间复杂度：O(n)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.2 MB, less than 28.45% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 设置一维 dp 数组，dp[i] 表示爬到第 i 个台阶有多少种方法
 * 
 * 状态转移方程为：dp[i] = dp[i - 1] + dp[i - 2]
 */
// class Solution {
// public:
//     int climbStairs(int n) {
//         // 特判
//         if (n == 1) {
//             return 1;
//         }
//         if (n == 2) {
//             return 2;
//         }
//         vector<int> dp(n, 0);
//         // 确定边界
//         dp[0] = 1;
//         dp[1] = 2;
//         // 逐步填表
//         for (int i = 2; i < n; i++) {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }
//         // 读取结果
//         return dp[n - 1];
//     }
// };

/**
 * 方法二：动态规划 + 滚动数组
 * 
 * 理论时间复杂度：O(n)
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6 MB, less than 53.93% of C++ online submissions
 */
// class Solution {
// public:
//     int climbStairs(int n) {
//         // 特判
//         if (n == 1) {
//             return 1;
//         }
//         if (n == 2) {
//             return 2;
//         }
//         // 确定边界
//         int p1 = 1;
//         int p2 = 2;
//         int tp;
//         // 逐步填表
//         for (int i = 2; i < n; i++) {
//             tp = p2;
//             p2 = p1 + p2;
//             p1 = tp;
//         }
//         // 读取结果
//         return p2;
//     }
// };

/**
 * 方法三：动态规划 + 矩阵快速幂
 * 
 * 理论时间复杂度：O(logn)
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.2 MB, less than 14.96% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 在上文我们发现递推公式为 f(n) = f(n - 1) + f(n - 2)
 * 
 * 我们可以构造等价递推关系 | 1 1 | * |  f(n)  | = | f(n) + f(n - 1) | = | f(n+1) |
 *                        | 1 0 |   | f(n-1) |   |       f(n)      |   |  f(n)  |
 * 
 * 上述递推关系也可以简化为 | f(n+1) | = | 1 1 |^n * | f(1) |
 *                        |  f(n)  |   | 1 0 |     | f(0) |
 * 
 * 令 M = | 1 1 |，这样就能利用矩阵快速幂算法求解 M 的 n 次方，以此提高效率
 *        | 1 0 |
 * 
 * 备注：如果一个递推式形如 f(n) = \sum_{i}^{m} a_i f(n - i)，即齐次线性递推式
 * 
 *       那么就可以把数列的递推关系转化为矩阵的递推关系，该常数矩阵一般为 | a_1 a_2 a_3 ... a_m |
 *                                                                  |  1   0   0  ...  0  |
 *                                                                  |  0   1   0  ...  0  |
 *                                                                  |  0   0   1  ...  0  |
 *                                                                  | ... ... ... ... ... |
 *                                                                  |  0   0   0  ...  1  |
 */
class Solution {
public:
    // 矩阵乘法
    vector<vector<long long int>> matrixMul(
        vector<vector<long long int>>& a,
        vector<vector<long long int>>& b
    ) {
        vector<vector<long long int>> c(2, vector<long long int>(2));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }

    // 快速幂：参考 leetcode50
    vector<vector<long long int>> matrixPow(
        vector<vector<long long int>> a,
        int n
    ) {
        vector<vector<long long int>> ret = { // 答案矩阵，初始化为单位矩阵
            {1, 0},
            {0, 1}
        };
        while  (n > 0) {
            if (n % 2 == 1) {
                ret = matrixMul(ret, a);
            }
            n = n / 2;
            a = matrixMul(a, a);
        }
        return ret;
    }

    int climbStairs(int n) {
        vector<vector<long long int>> ret = {
            {1, 1},
            {1, 0}
        };
        vector<vector<long long int>> res = matrixPow(ret, n);
        return res[0][0];
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int n = 45;
    int ans = solution -> climbStairs(n);
    cout << ans << endl;
}
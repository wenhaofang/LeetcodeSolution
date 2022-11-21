/*************************************************
Author: wenhaofang
Date: 2022-11-18
Description: leetcode887 - Super Egg Drop
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
 * 方法一：动态规划 (自下而上)
 * 
 * 理论时间复杂度：O(k * n * n)，其中 k 为鸡蛋数，n 为楼层数
 * 理论空间复杂度：O(k * n    )，其中 k 为鸡蛋数，n 为楼层数
 * 
 * Time Limit Exceeded
 */

// class Solution {
// public:
//     int superEggDrop(int k, int n) {
//         // 特判
//         if (
//             k <= 1 ||
//             n <= 1
//         ) {
//             return n;
//         }
//         // 定义数组，dp[i][j] 表示当鸡蛋数为 i 且楼层数为 j 时子问题的结果，即确定在最坏情况下鸡蛋掉落不会碎的最高楼层的操作次数
//         int dp[k + 1][n + 1];
//         // 填充数组
//         // 边界情况，dp[i][0] 表示当鸡蛋数为 i 且楼层数为 0 时子问题的结果，只需随便返回 0，因为此情况不合法
//         //          dp[0][j] 表示当鸡蛋数为 0 且楼层数为 j 时子问题的结果，只需随便返回 0，因为此情况不合法
//         //          dp[i][1] 表示当鸡蛋数为 i 且楼层数为 1 时子问题的结果，因为楼层数为 1，所以只需在第一层楼层尝试即可，因此最小操作次数为 1
//         //          dp[1][j] 表示当鸡蛋数为 1 且楼层数为 j 时子问题的结果，因为鸡蛋数为 1，所以只能从低到高楼层逐层尝试，因此最小操作次数为 j
//         for (int i = 0; i <= k; i++) {
//             dp[i][0] = 0;
//             dp[i][1] = 1;
//         }
//         for (int j = 0; j <= n; j++) {
//             dp[0][j] = 0;
//             dp[1][j] = j;
//         }
//         // 填充数组
//         // 其余情况
//         for (int i = 2; i<= k; i++) {
//             for (int j = 2; j <= n; j++) {
//                 // 当鸡蛋数为 i 且楼层数为 j 时，因为不知道在哪一层扔鸡蛋符合条件，所以需要逐一尝试在每一层扔鸡蛋的情况
//                 int result = INT_MAX;
//                 for (int k = 1; k <= j; k++) {
//                     // 如果鸡蛋碎了，说明在 k 层及以上的楼层扔鸡蛋也会碎
//                     // 此时鸡蛋数量减一，之后继续检查 k 层以下的楼层即可，即状态转移为：dp[i - 1][k - 1]
//                     int case1 = dp[i - 1][k - 1] + 1;
//                     // 如果鸡蛋没碎，说明在 k 层及以下的楼层扔鸡蛋也不碎
//                     // 此时鸡蛋数量不变，之后继续检查 k 层以上的楼层即可，即状态转移为：dp[i][j - k]
//                     int case2 = dp[i][j - k] + 1;
//                     // max 对应最坏情况
//                     // min 对应最少次数
//                     result = min(result, max(case1, case2));
//                 }
//                 dp[i][j] = result;
//             }
//         }
//         // 返回结果
//         return dp[k][n];
//     }
// };

/**
 * 方法二：动态规划 (自下而上) + 二分搜索
 * 
 * 理论时间复杂度：O(k * n * logn)，其中 k 为鸡蛋数，n 为楼层数
 * 理论空间复杂度：O(k * n       )，其中 k 为鸡蛋数，n 为楼层数
 * 
 * 实际时间复杂度：Runtime: 317 ms, faster than 17.90% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 9.6 MB, less than 85.10% of C++ online submissions
 */

// class Solution {
// public:
//     int superEggDrop(int k, int n) {
//         // 特判
//         if (
//             k <= 1 ||
//             n <= 1
//         ) {
//             return n;
//         }
//         // 定义数组，dp[i][j] 表示当鸡蛋数为 i 且楼层数为 j 时子问题的结果，即确定在最坏情况下鸡蛋掉落不会碎的最高楼层的操作次数
//         int dp[k + 1][n + 1];
//         // 填充数组
//         // 边界情况，dp[i][0] 表示当鸡蛋数为 i 且楼层数为 0 时子问题的结果，只需随便返回 0，因为此情况不合法
//         //          dp[0][j] 表示当鸡蛋数为 0 且楼层数为 j 时子问题的结果，只需随便返回 0，因为此情况不合法
//         //          dp[i][1] 表示当鸡蛋数为 i 且楼层数为 1 时子问题的结果，因为楼层数为 1，所以只需在第一层楼层尝试即可，因此最小操作次数为 1
//         //          dp[1][j] 表示当鸡蛋数为 1 且楼层数为 j 时子问题的结果，因为鸡蛋数为 1，所以只能从低到高楼层逐层尝试，因此最小操作次数为 j
//         for (int i = 0; i <= k; i++) {
//             dp[i][0] = 0;
//             dp[i][1] = 1;
//         }
//         for (int j = 0; j <= n; j++) {
//             dp[0][j] = 0;
//             dp[1][j] = j;
//         }
//         // 填充数组
//         // 其余情况
//         for (int i = 2; i<= k; i++) {
//             for (int j = 2; j <= n; j++) {
//                 // 修改之处
//                 // 当鸡蛋数为 i 且楼层数为 j 时，可以用二分搜索来查找楼层，代替线性搜索
//                 int result = INT_MAX;
//                 int lp = 1;
//                 int rp = j;
//                 while (lp <= rp) {
//                     // 找出中间楼层 m
//                     int m = lp + (rp - lp) / 2;
//                     // 如果鸡蛋碎了，说明在 m 层及以上的楼层扔鸡蛋也会碎
//                     // 此时鸡蛋数量减一，之后继续检查 m 层以下的楼层即可
//                     int case1 = dp[i - 1][m - 1] + 1;
//                     // 如果鸡蛋没碎，说明在 m 层及以下的楼层扔鸡蛋也不碎
//                     // 此时鸡蛋数量不变，之后继续检查 m 层以上的楼层即可
//                     int case2 = dp[i][j - m] + 1;
//                     // 缩小搜索区间
//                     if (case1 > case2) {
//                         rp = m - 1;
//                     } else {
//                         lp = m + 1;
//                     }
//                     // max 对应最坏情况
//                     // min 对应最少次数
//                     result = min(result, max(case1, case2));
//                 }
//                 dp[i][j] = result;
//             }
//         }
//         // 返回结果
//         return dp[k][n];
//     }
// };

/**
 * 方法三：动态规划 (自上而下) + 二分搜索
 * 
 * 理论时间复杂度：O(k * n * logn)，其中 k 为鸡蛋数，n 为楼层数
 * 理论空间复杂度：O(k * n       )，其中 k 为鸡蛋数，n 为楼层数
 * 
 * 实际时间复杂度：Runtime: 8 ms, faster than 86.14% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.3 MB, less than 86.95% of C++ online submissions
 */

int dp[105][10005] = {0};

class Solution {
public:
    int superEggDrop(int k, int n) {
        if (
            k == 1 ||
            n <= 1
        ) {
            return n;
        }
        if (dp[k][n] == 0) {
            int result = INT_MAX;
            int lp = 1;
            int rp = n;
            while (lp <= rp) {
                int m = lp + (rp - lp) / 2;
                int case1 = superEggDrop(k - 1, m - 1) + 1;
                int case2 = superEggDrop(k, n - m) + 1;
                if (case1 > case2) {
                    rp = m - 1;
                } else {
                    lp = m + 1;
                }
                result = min(result, max(case1, case2));
            }
            dp[k][n] = result;
        }
        return dp[k][n];
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int k = 1;
    int n = 2;
    int ans = solution -> superEggDrop(k, n);
    cout << ans << endl;
}
/*************************************************
Author: wenhaofang
Date: 2023-03-12
Description: leetcode121 - Best Time to Buy and Sell Stock
*************************************************/

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>

using std::list;
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
using std::atoi;
using std::stoi;
using std::to_string;
using std::cin;
using std::cout;
using std::endl;

/**
 * 方法一：暴力搜索
 * 
 * 理论时间复杂度：O(n^2)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 */
/**
 * 思路
 * 
 * 遍历数组作为买入时间点，从买入时间点后遍历数组，找最大值作为卖出时间点
 */

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         // 特判
//         int n = prices.size();
//         if (n == 0) {
//             return 0;
//         }
//         // 开始暴力搜索
//         int cur = 0;
//         int ans = 0;
//         // 遍历买入时间
//         for (int i = 0; i < n; i++) {
//             // 遍历卖出时间
//             for (int j = i + 1; j < n; j++) {
//                 // 计算最大收益
//                 cur = prices[j] - prices[i];
//                 ans = max(ans, cur);
//             }
//         }
//         // 返回结果
//         return ans;
//     }
// };

/**
 * 方法二：预处理
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 */
/**
 * 思路
 * 
 * 上述内层循环存在重复运算，想办法消解掉这些重复运算
 * 
 * 可以预先从后往前遍历数组，记录当前位置之后的最大值，以后就能通过 O(1) 时间复杂度找到最大值
 */

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         // 特判
//         int n = prices.size();
//         if (n == 0) {
//             return 0;
//         }
//         // 预处理
//         vector<int> highest(n, -1);
//         highest[n - 1] = prices[n - 1];
//         for (int i = n - 2; i >= 0; i--) {
//             highest[i] = max(prices[i], highest[i + 1]);
//         }
//         // 正处理
//         int cur = 0;
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             cur = highest[i] - prices[i];
//             ans = max(ans, cur);
//         }
//         // 返回结果
//         return ans;
//     }
// };

/**
 * 方法三：逆过程
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 */
/**
 * 思路
 * 
 * 之前的方法是遍历数组作为买入时间点，然后就是从后往前预处理，记录下对应的最佳卖出时间点（当前元素后的最大值）
 * 
 * 如果现在我们遍历数组作为卖出时间点，那么变成从前往后预处理，记录下对应的最佳买入时间点（当前元素前的最小值）
 * 
 * 这样就可以将预处理和遍历数组同时做
 * 
 * 另外在空间上也可以做优化，不再需要用数组存储所有最小值，只是需要用变量存储历史最小值即可
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 特判
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        // 预处理 + 正处理
        int lowest = prices[0];
        int cur = 0;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            lowest = min(prices[i], lowest);
            cur = prices[i] - lowest;
            ans = max(ans, cur);
        }
        // 返回结果
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int ans = solution -> maxProfit(prices);
    cout << ans << endl;
}
/*************************************************
Author: wenhaofang
Date: 2022-01-27
Description: leetcode53 - Maximum Subarray
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
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 * 
 * 实际时间复杂度：Runtime: 104 ms, faster than 77.31% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 67.7 MB, less than 53.79% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 设置一维 dp 数组，dp[i] 表示以第 i 个数结尾的连续子数组的最大和
 * 
 * 状态转移方程为：dp[i] = max(dp[i - 1] + nums[i], nums[i])
 * 
 * 备注：不能使用双指针加贪心算法，因为局部最优无法保证全局最优
 */
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,0);
//         // 确定边界
//         dp[0] = nums[0];
//         // 逐步填表
//         for (int i = 1; i < n; i++) {
//             dp[i] = max(dp[i - 1] + nums[i], nums[i]);
//         }
//         // 读取结果
//         int ans = INT_MIN;
//         for (int i = 0; i < n; i++) {
//             if (dp[i] > ans) {
//                 ans = dp[i];
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 因为在填充 dp 数组时，只需要前一个位置的值
        // 所以只维护 dp 数组的最后一个位置，以便节约空间
        // 同时在一次遍历中计算答案，以便节约时间
        int dp0 = 0;
        int ans = nums[0];
        for (const auto &x: nums) {
            dp0 = max(dp0 + x, x);
            ans = max(dp0, ans);
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = solution -> maxSubArray(nums);
    cout << ans << endl;
}
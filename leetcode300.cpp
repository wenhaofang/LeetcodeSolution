/*************************************************
Author: wenhaofang
Date: 2022-11-17
Description: leetcode300 - Longest Increasing Subsequence
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
 * 理论时间复杂度：O(n^2)，其中 n 为数组大小
 * 理论空间复杂度：O(n)  ，其中 n 为数组大小
 * 
 * 实际时间复杂度：Runtime: 512 ms, faster than 50.44% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 10.2 MB, less than 99.92% of C++ online submissions
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 特判
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        // 定义数组，dp[i] 表示以 nums[i] 结尾的子问题的结果，即最长严格递增子序列的长度，注意，子序列是不要求连续的
        int dp[n];
        // 填充数组
        // 边界情况，dp[0] 表示以 nums[0] 结尾的子问题的结果，为一，因为有且只有一个元素
        dp[0] = 1;
        // 填充数组
        // 其余情况，dp[i] = max(dp[j] + 1), 0 <= j < i && nums[j] > nums[i]
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] ) {
                    dp[i] = max(dp[i] , dp[j] + 1);
                }
            }
        }
        // 返回结果
        return *std::max_element(dp, dp + n);
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int ans = solution -> lengthOfLIS(nums);
    cout << ans << endl;
}
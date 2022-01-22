/*************************************************
Author: wenhaofang
Date: 2022-01-23
Description: leetcode45 - Jump Game II
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
 * 实际时间复杂度：Runtime: 782 ms, faster than 10.28% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 17.2 MB, less than 13.53% of C++ online submissions
 */
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, INT_MAX);
//         dp[0] = 0;
//         for (int i = 0; i <= n - 2; i++) {
//             for (int j = 0; j <= nums[i]; j++) {
//                 if (i + j < n) {
//                     dp[i + j] = min(dp[i + j], dp[i] + 1);
//                 }
//             }
//         }
//         return dp[n - 1];
//     }
// };

/**
 * 方法二：贪心算法
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 12 ms, faster than 91.20% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 16.7 MB, less than 38.89% of C++ online submissions
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() - 1;
        int ans = 0;
        int idx = 0;
        while (idx < n) {
            int max_idx = 0;
            int max_num = 0;
            for (int i = 0; i <= nums[idx]; i++) {
                if (idx + i >= n) {
                    max_idx = idx + i;
                    break;
                }
                if (idx + i + nums[idx + i] > max_num) {
                    max_idx = idx + i;
                    max_num = idx + i + nums[idx + i];
                }
            }
            ans = ans + 1;
            idx = max_idx;
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {2,1};
    int ans = solution -> jump(nums);
    cout << ans << endl;
}
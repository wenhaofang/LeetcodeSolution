/*************************************************
Author: wenhaofang
Date: 2022-12-03
Description: leetcode376 - Wiggle Subsequence
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
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7.4 MB, less than 19.18% of C++ online submissions
 */

// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         // 特判
//         int n = nums.size();
//         if (n < 2) {
//             return n;
//         }
//         // 定义数组，up[i] 表示在 nums[0...i] 中最长上升摆动子序列长度，上升摆动子序列是指最后一个元素呈上升趋势
//         //          dn[i] 表示在 nums[0...i] 中最长下降摆动子序列长度，下降摆动子序列是指最后一个元素呈下降趋势
//         vector<int> up(n);
//         vector<int> dn(n);
//         // 填充数组
//         // 边界情况，up[0] 表示在 nums[0...0] 中最长上升摆动子序列长度，为一，因为有且仅有一个元素
//         //          dn[0] 表示在 nums[0...0] 中最长下降摆动子序列长度，为一，因为有且仅有一个元素
//         up[0] = 1;
//         dn[0] = 1;
//         // 填充数组
//         // 其余情况
//         for (int i = 1; i < n; i++) {
//             if (nums[i - 1] == nums[i]) {
//                 up[i] = up[i - 1];
//                 dn[i] = dn[i - 1];
//             } else if (nums[i - 1] < nums[i]) {
//                 up[i] = max(up[i - 1], dn[i - 1] + 1);
//                 dn[i] = dn[i - 1];
//             } else if (nums[i - 1] > nums[i]) {
//                 up[i] = up[i - 1];
//                 dn[i] = max(dn[i - 1], up[i - 1] + 1);
//             }
//         }
//         // 返回结果
//         return max(up[n - 1], dn[n - 1]);
//     }
// };

/**
 * 方法二：贪心算法
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7.1 MB, less than 74.03% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 从折线图的角度来看，只要从起点开始，交替找谷顶谷低，直至到终点结束，最终的点数即为所求
 */

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // 特判
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        // 贪心算法
        int prev_diff = nums[1] - nums[0];
        int ans = prev_diff != 0 ? 2 : 1;
        for (int i = 2; i < n; i++) {
            int curr_diff = nums[i] - nums[i - 1];
            if (
                (curr_diff > 0 && prev_diff <= 0) ||
                (curr_diff < 0 && prev_diff >= 0)
            ) {
                ans += 1;
                prev_diff = curr_diff;
            }
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
    vector<int> nums {1, 7, 4, 9, 2, 5};
    int ans = solution -> wiggleMaxLength(nums);
    cout << ans << "\n";
}
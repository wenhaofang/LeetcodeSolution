/*************************************************
Author: wenhaofang
Date: 2023-03-12
Description: leetcode128 - Longest Consecutive Sequence
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
 * 理论时间复杂度：O(n^3)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 */
/**
 * 思路
 * 
 * 遍历数组作为连续序列的起始元素 x，遍历数组找 x + 1、x + 2、...，直至没找到时即为一组连续序列
 */

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         // 特判
//         int n = nums.size();
//         if (n == 0) {
//             return 0;
//         }
//         // 暴力搜索
//         int ans = 0;
//         for (int i = 0; i < n; i++) { // 第 1 层循环
//             int sos = nums[i];
//             int eos = nums[i];
//             while (1) { // 第 2 层循环
//                 bool find = false;
//                 for (int j = 0; j < n; j++) { // 第 3 层循环
//                     if (nums[j] == eos + 1) {
//                         find = true;
//                         eos += 1;
//                         break;
//                     }
//                 }
//                 if (!find) {
//                     break;
//                 }
//             }
//             ans = max(ans, eos - sos + 1);
//         }
//         // 返回答案
//         return ans;
//     }
// };

/**
 * 方法二：哈希
 * 
 * 理论时间复杂度：O(n^2)，其中 n 为数组大小
 * 理论空间复杂度：O(n)  ，其中 n 为数组大小
 */
/**
 * 思路：消解第 3 层循环
 * 
 * 上述第 3 层循环的作用是找数组中是否存在某个数，为此，我们可以预先将数组存入哈希集合，这样时间复杂度可以降为 O(1)
 */

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         // 特判
//         int n = nums.size();
//         if (n == 0) {
//             return 0;
//         }
//         // 数组存入哈希集合
//         unordered_set<int> set;
//         for (int num:nums) {
//             set.insert(num);
//         }
//         // 优化搜索
//         int ans = 0;
//         for (int i = 0; i < n; i++) { // 第 1 层循环
//             int sos = nums[i];
//             int eos = nums[i];
//             // while (1) {
//             //     if (set.find(eos + 1) != set.end()) {
//             //         eos += 1;
//             //     } else {
//             //         break;
//             //     }
//             // }
//             while (set.find(eos + 1) != set.end()) { // 第 2 层循环
//                 eos += 1;
//             }
//             ans = max(ans, eos - sos + 1);
//         }
//         // 返回答案
//         return ans;
//     }
// };

/**
 * 方法三：哈希
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 */
/**
 * 思路：优化第 2 层循环
 * 
 * 上述第 2 层循环有很多重复计算
 * 
 * 例如之前一步是找以 x 为起点的连续序列，此时要检查 x + 1, x + 2, ... 是否在数组
 * 
 * 如果之后一步要找以 x - 1 为起点的连续序列，又重复检查 x, x + 1, x + 2, ... 是否在数组
 * 
 * 所以说，如果要找以 x 为起点的连续序列，可以先检查 x - 1 是否在数组
 * 
 * 如果在，就不用处理 ，对应的检查可以留给遍历到 x - 1 时执行，如果不在，才要去检查
 * 
 * 实际上这样只会遍历一次数组，所以时间复杂度是 O(n)
 */

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         // 特判
//         int n = nums.size();
//         if (n == 0) {
//             return 0;
//         }
//         // 数组存入哈希集合
//         unordered_set<int> set;
//         for (int num: nums) {
//             set.insert(num);
//         }
//         // 优化搜索
//         int ans = 0;
//         for (int i = 0; i < n; i++) { // 第 1 层循环
//             int sos = nums[i];
//             int eos = nums[i];
//             if (set.find(sos - 1) != set.end()) { // 优化
//                 continue;
//             }
//             while (set.find(eos + 1) != set.end()) { // 第 2 层循环
//                 eos += 1;
//             }
//             ans = max(ans, eos - sos + 1);
//         }
//         // 返回答案
//         return ans;
//     }
// };

/**
 * 方法四：
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 */
/**
 * 思路：优化第 1 层循环
 * 
 * 上述第 1 层循环遍历的是数组，实际上遍历哈希集合就行，因为数组中的重复元素处理是一样的
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 特判
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        // 数组存入哈希集合
        unordered_set<int> set;
        for (int num: nums) {
            set.insert(num);
        }
        // 优化搜索
        int ans = 0;
        for (int num: set) { // 第 1 层循环
            int sos = num;
            int eos = num;
            if (set.find(sos - 1) != set.end()) { // 优化
                continue;
            }
            while (set.find(eos + 1) != set.end()) { // 第 2 层循环
                eos += 1;
            }
            ans = max(ans, eos - sos + 1);
        }
        // 返回答案
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int ans = solution -> longestConsecutive(nums);
    cout << ans << endl;
}
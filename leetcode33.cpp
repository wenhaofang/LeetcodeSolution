/*************************************************
Author: wenhaofang
Date: 2021-06-15
Description: leetcode33 - Search in Rotated Sorted Array
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
using std::pair;
using std::cin;
using std::cout;
using std::endl;


/**
 * 方法一：二分查找
 * 
 * 理论时间复杂度：O(logn)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 11.1 MB, less than 74.41% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 此题初看可以用二分查找来解决，但又与常规的二分查找有所不同
 * 
 * 我们可以用二分查找的思路尝试分析，当使用中值分割数组时，会出现以下的情况【分类讨论】：
 * 
 * 1、中值恰好等于目标值，此时直接得到结果！
 * 
 * 2、左半数组有序 且 (左边数组最小值 <= 目标值 且 目标值 <= 左边数组最大值)，此时可以把查找范围进一步约束为左半数组
 * 
 * 3、左半数组有序 且 (目标值 <  左边数组最小值 或 左边数组最大值 <  目标值)，此时可以把查找范围进一步约束为右半数组
 * 
 * 4、右半数组有序 且 (右边数组最小值 <= 目标值 且 目标值 <= 右边数组最大值)，此时可以把查找范围进一步约束为右半数组
 * 
 * 5、右半数组有序 且 (目标值 <  右边数组最小值 或 右边数组最大值 <  目标值)，此时可以把查找范围进一步约束为左半数组
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int p1 = 0;
        int p2 = n - 1;
        while (p1 <= p2) {
            int mid = (p1 + p2) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[p1] <= nums[mid] && (nums[p1] <= target && target <= nums[mid])) {
                p2 = mid - 1;
            } else if (nums[p1] <= nums[mid] && (target <= nums[p1] || nums[mid] <= target)) {
                p1 = mid + 1;
            } else if (nums[mid] <= nums[p2] && (nums[mid] <= target && target <= nums[p2])) {
                p1 = mid + 1;
            } else if (nums[mid] <= nums[p2] && (target <= nums[mid] || nums[p2] <= target)) {
                p2 = mid - 1;
            }
        }
        return -1;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int ans = solution -> search(nums, target);
    cout << ans << endl;
}
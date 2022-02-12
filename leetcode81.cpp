/*************************************************
Author: wenhaofang
Date: 2022-02-22
Description: leetcode81 - Search in Rotated Sorted Array II
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
 * 方法一：二分查找
 * 
 * 理论时间复杂度：O(logn)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 14.1 MB, less than 30.32% of C++ online submissions
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // 特判
        int n = nums.size();
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return nums[0] == target;
        }
        // 二分查找
        int p1 = 0;
        int p2 = n - 1;
        // while (p1 <= p2) {
        //     int mid = (p1 + p2) / 2;
        //     if (nums[mid] == target) {
        //         return true;
        //     } else if (nums[p1] == nums[mid] && nums[mid] == nums[p2]) { // 与 leetcode33 的不同之处
        //         p1++;
        //         p2--;
        //     } else if (nums[p1] <= nums[mid] && (nums[p1] <= target && target <= nums[mid])) {
        //         p2 = mid - 1;
        //     } else if (nums[p1] <= nums[mid] && (target <= nums[p1] || nums[mid] <= target)) {
        //         p1 = mid + 1;
        //     } else if (nums[mid] <= nums[p2] && (nums[mid] <= target && target <= nums[p2])) {
        //         p1 = mid + 1;
        //     } else if (nums[mid] <= nums[p2] && (target <= nums[mid] || nums[p2] <= target)) {
        //         p2 = mid - 1;
        //     }
        // }
        // return false;
        while (p1 <= p2) {
            int mid = (p1 + p2) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (
                nums[p1] == nums[mid] &&
                nums[mid] == nums[p2]
            ) {
                p1++;
                p2--;
            } else if (nums[p1] <= nums[mid]) {
                if (nums[p1] <= target && target <= nums[mid]) {
                    p2 = mid - 1;
                } else {
                    p1 = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[p2]) {
                    p1 = mid + 1;
                } else {
                    p2 = mid - 1;
                }
            }
        }
        return false;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    bool ans = solution -> search(nums, target);
    cout << ans << endl;
}
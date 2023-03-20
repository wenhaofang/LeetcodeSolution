/*************************************************
Author: wenhaofang
Date: 2023-03-20
Description: leetcode581 - Shortest Unsorted Continuous Subarray
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：排序
 * 
 * 理论时间复杂度：O(nlogn)，其中 n 为数组大小
 * 理论空间复杂度：O(n)    ，其中 n 为数组大小
 */
/**
 * 思路
 * 
 * 另外拷贝一份数组并对其排序
 * 
 * 从左往右找原数组与排序数组第一个不相等的位置，即为需要排序的左边界
 * 
 * 从右往左找原数组与排序数组第一个不相等的位置，即为需要排序的右边界
*/

// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> temp(nums);
//         sort(nums.begin(), nums.end());
//         int l = -1;
//         for (int i = 0; i < n; i++) {
//             if (nums[i] != temp[i]) {
//                 l = i;
//                 break;
//             }
//         }
//         if (l == -1) {
//             return 0;
//         }
//         int r = -1;
//         for (int i = n - 1; i >= 0; i--) {
//             if (nums[i] != temp[i]) {
//                 r = i;
//                 break;
//             }
//         }
//         if (r == -1) {
//             return 0;
//         }
//         return r - l + 1;
//     }
// };

/**
 * 方法二：模拟
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 */
/**
 * 思路
 * 
 * 可将数组看作由三部分组成：numsA (有序) + numsB (无序) + numsC (有序)
 * 
 * 从 numsB 中找最小值 minB 和最大值 maxB
 * 
 * 从 numsA 中找最小值 minB 插入位置，即为需要排序的左边界
 * 
 * 从 numsC 中找最大值 maxB 插入位置，即为需要排序的右边界
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) {
            return 0;
        }
        int a = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] <= nums[i + 1]) {
                a = i + 1;
            } else break;
        }
        if (a == n - 1) {
            return 0;
        }
        int b = n - 1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] <= nums[i]) {
                b = i - 1;
            } else break;
        }
        if (b == 0) {
            return 0;
        }
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        for (int i = a; i <= b; i++) {
            minVal = min(minVal, nums[i]);
            maxVal = max(maxVal, nums[i]);
        }
        int l;
        for (int i = 0; i <= a; i++) {
            if (nums[i] > minVal) {
                l = i;
                break;
            }
        }
        int r;
        for (int i = n - 1; i >= b; i--) {
            if (nums[i] < maxVal) {
                r = i;
                break;
            }
        }
        return r - l + 1;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {2, 1};
    int ans = solution -> findUnsortedSubarray(nums);
    cout << ans << endl;
}
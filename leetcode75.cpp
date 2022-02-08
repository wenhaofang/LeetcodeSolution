/*************************************************
Author: wenhaofang
Date: 2022-02-18
Description: leetcode75 - Sort Colors
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
 * 方法一：暴力模拟（两趟扫描，基于计数）
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 8.3 MB, less than 69.65% of C++ online submissions
 */
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> mapping(3); // 计数，表示值 0、1、2 各有多少个
//         // 1. 设置标志
//         for (int i = 0; i < n; i++) {
//             mapping[nums[i]] += 1;
//         }
//         // 2. 修改数组
//         for (int i = 0; i < n; i++) {
//             int v0 = mapping[0];
//             int v1 = mapping[0] + mapping[1];
//             int v2 = mapping[0] + mapping[1] + mapping[2];
//             if (i < v0) {
//                 nums[i] = 0;
//             }
//             else if (i < v1) {
//                 nums[i] = 1;
//             }
//             else if (i < v2) {
//                 nums[i] = 2;
//             }
//         }
//     }
// };

/**
 * 方法二：暴力模拟（两趟扫描，基于指针交换）
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 8.1 MB, less than 99.65% of C++ online submissions
 */
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         int p = 0;
//         // 交换 0 到前面
//         for (int i = 0; i < n; i++) {
//             if (nums[i] == 0) {
//                 swap(nums[i], nums[p]);
//                 p++;
//             }
//         }
//         // 交换 1 到前面
//         for (int i = p; i < n; i++) {
//             if (nums[i] == 1) {
//                 swap(nums[i], nums[p]);
//                 p++;
//             }
//         }
//     }
// };

/**
 * 方法三：暴力模拟（一趟扫描，基于指针交换）
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 8.3 MB, less than 69.65% of C++ online submissions
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0; // 用于交换 0
        int p1 = 0; // 用于交换 1
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                p1++;
            }
            else if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                p0++;
                p1++;
            }
        }
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    solution -> sortColors(nums);
    for (auto item: nums) {
        cout << item << "\n";
    }
}
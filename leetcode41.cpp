/*************************************************
Author: wenhaofang
Date: 2022-01-19
Description: leetcode41 - First Missing Positive
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
 * 方法一：原地哈希（标记）
 * 
 * 理论时间复杂度：O(N)，其中 N 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 152 ms, faster than 73.12% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 83 MB, less than 78.06% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 对于这类查找元素的题目，可以考虑用哈希算法（先处理存入哈希表，再从哈希表中查找）
 * 
 * 但是由于题目有时空限制，所以只能用原地哈希，具体来说这里使用标记法
 */
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int n = nums.size();
//         // 将数组中小于等于 0 的元素，修改成 n + 1
//         for (int i = 0; i < n; i++) {
//             if (nums[i] <= 0) {
//                 nums[i] = n + 1;
//             }
//         }
//         // 将数组中小于等于 n 的元素，作为索引找到对应的元素修改成 负数
//         for (int i = 0; i < n; i++) {
//             int num = abs(nums[i]);
//             if (num <= n) {
//                 nums[num - 1] = -abs(nums[num - 1]);
//             }
//         }
//         // 从左往后遍历数组，第一个大于 0 的元素对应的索引就是答案
//         for (int i = 0; i < n; i++) {
//             if (nums[i] > 0) {
//                 return i + 1;
//             }
//         }
//         // 兜底，若数组中 n 个元素都符合条件，则第一个不符合条件的数是 n + 1
//         return n + 1;
//     }
// };

/**
 * 方法二：原地哈希（置换）
 * 
 * 理论时间复杂度：O(N)
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 181 ms, faster than 53.63% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 83 MB, less than 78.06% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 对于这类查找元素的题目，可以考虑用哈希算法（先处理存入哈希表，再从哈希表中查找）
 * 
 * 但是由于题目有时空限制，所以只能用原地哈希，具体来说这里使用置换法
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 交换
        for (int i = 0; i < n; i++) {
            while (
                nums[i] >  0 &&
                nums[i] <= n &&
                nums[i] != nums[nums[i] - 1]
            ) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // 查找
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        // 兜底，若数组中 n 个元素都符合条件，则第一个不符合条件的数是 n + 1
        return n + 1;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = { 3, 4, -1, 1 };
    int ans = solution -> firstMissingPositive(nums);
    cout << ans << endl;
}
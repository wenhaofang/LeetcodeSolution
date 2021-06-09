/*************************************************
Author: wenhaofang
Date: 2021-03-04
Description: leetcode1 - Two Sum
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
 * 思路一：暴力搜索
 * 
 * 时间复杂度：O(n^2)，其中 n 为数组大小
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 4 ms, faster than 97.18% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 8.9 MB, less than 71.94% of C++ online submissions
 */
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         // 遍历数组元素
//         for (int i = 0; i < n; i++) {
//             // 对每个元素在数组中找与之相加等于 `target` 的值
//             for (int j = i + 1; j < n; j++) {
//                 if (nums[i] + nums[j] == target) {
//                     return {i, j};
//                 }
//             }
//         }
//         return {};
//     }
// };

/**
 * 思路二：先构建哈希，再逐一搜索
 * 
 * 时间复杂度：O(n)，其中 n 为数组大小
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 8 ms, faster than 74.84% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 9.9 MB, less than 15.08% of C++ online submissions
 */
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         unordered_map<int, int> hashTable;
//         // 先遍历一次数组，构建哈希表，哈希表中的键为元素，值为元素对应的索引
//         for (int i = 0; i < n; i++) {
//             hashTable.insert(pair<int, int>(nums[i], i));
//         }
//         // 再遍历一次数组，对每个元素在哈希表找与之相加等于 `target` 的值
//         for (int i = 0; i < n; i++) {
//             auto j = hashTable.find(target - nums[i]);
//             if (j != hashTable.end() && j->second != i) {
//                 return {i, j->second};
//             }
//         }
//         return {};
//     }
// };

/**
 * 思路三：构建哈希的同时逐一搜索
 * 
 * 时间复杂度：O(n)，其中 n 为数组大小
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 9 MB, less than 55.03% of C++ online submissions
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hashTable;
        // 遍历一次数组
        for (int i = 0; i < n; i++) {
            // 对每个元素在哈希表找与之相加等于 `target` 的值
            auto j = hashTable.find(target - nums[i]);
            // 如果可以找到，立即返回结果
            if (j != hashTable.end()) {
                return {j->second, i};
            }
            // 如果没有找到，把该元素的值及其索引添加到哈希表
            hashTable.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = solution->twoSum(nums, target);
    for(auto item: ans) {
        cout << item << " ";
    }
}
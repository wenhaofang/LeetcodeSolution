/*************************************************
Author: wenhaofang
Date: 2021-03-21
Description: leetcode16 - 3Sum Closest
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
 * 思路一：双指针
 * 
 * 时间复杂度：O(n^2)，其中 n 为数组大小
 * 空间复杂度：O(logn)，其中 n 为数组大小
 * 
 * 实际时间复杂度：Runtime: 4 ms, faster than 99.10% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 9.8 MB, less than 94.01% of C++ online submissions
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        // minGap: 表示三数之和与 target 之间的最小差距
        // answer: 表示经计算得到 minGap 对应的三数之和
        int minGap = INT_MAX;
        int answer;
        // 数组排序
        sort(nums.begin(), nums.end());
        // 遍历数组，把指针 i 对应的值固定作为一数，双指针扫描找剩余两数
        for (int i = 0; i < n; i++) {
            // 指针 j 初始化在数组始端，指针 k 初始化在数组末端
            int j = i + 1;
            int k = n - 1;
            // 双指针向数组中间移动，直至相遇
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    // 如果三数之和等于 target，那么直接返回答案
                    return target;
                } else if (sum < target) {
                    // 如果三数之和小于 target，那么计算三数之和与 target 之间的差距
                    int curGap = target - sum;
                    // 若它们的差距小于之前的最小差距，则更新最小差距和答案
                    if (curGap < minGap) {
                        minGap = curGap;
                        answer = sum;
                    }
                    // 同时将指针 j 向右移动，直至遇到第一个不相同的数或到达 n
                    while (++j < n && nums[j] == nums[j - 1]);
                } else if (sum > target) {
                    // 如果三数之和大于 target，那么计算三数之和与 target 之间的差距
                    int curGap = sum - target;
                    // 若它们的差距小于之前的最小差距，则更新最小差距和答案
                    if (curGap < minGap) {
                        minGap = curGap;
                        answer = sum;
                    }
                    // 同时将指针 k 向左移动，直至遇到第一个不相同的数或到达 i
                    while (--k > i && nums[k] == nums[k + 1]);
                }
            }
        }
        return answer;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int ans = solution->threeSumClosest(nums, target);
    cout << ans << endl;
}
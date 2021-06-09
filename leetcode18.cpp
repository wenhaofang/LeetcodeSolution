/*************************************************
Author: wenhaofang
Date: 2021-03-23
Description: leetcode18 - 4Sum
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
 * 时间复杂度：O(n^3)，其中 n 为数组大小
 * 空间复杂度：O(logn)，其中 n 为数组大小
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 13 MB, less than 85.41% of C++ online submissions
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 4) {
            return ans;
        }
        // 排序
        sort(nums.begin(), nums.end());
        // 遍历 + 双指针
        for (int i = 0; i < n - 3; i++) {
            // 剪枝，由于题目要求四元组不能重复
            // 所以指针 i 直接移动到下一个不相同的数
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 剪枝，此时固定 nums[i] 为四数最小值
            // 如果 nums[i] + 能取的最小值依然大于 target，那么退出循环
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            // 剪枝，此时固定 nums[i] 为四数最小值
            // 如果 nums[i] + 能取的最大值依然小于 target，那么跳过循环
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                // 剪枝，由于题目要求四元组不能重复
                // 所以指针 j 直接移动到下一个不相同的数
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                // 剪枝，此时固定 nums[i], nums[j] 为四数第一第二小
                // 如果 nums[i] + nums[j] + 能取的最小值依然大于 target，那么退出循环
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                // 剪枝，此时固定 nums[i], nums[j] 为四数第一第二小
                // 如果 nums[i] + nums[j] + 能取的最大值依然小于 target，那么跳过循环
                if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) {
                    continue;
                }
                // 将中间值保存下来，避免多次取值
                int numI = nums[i];
                int numJ = nums[j];
                // 指针 p 初始化在数组始端，指针 q 初始化在数组末端
                int p = j + 1;
                int q = n - 1;
                // 双指针向数组中间移动，直至相遇
                while (p < q) {
                    // 将中间值保存下来，避免多次取值
                    int numP = nums[p];
                    int numQ = nums[q];
                    // 计算四数之和
                    int sum = numI + numJ + numP + numQ;
                    if (sum == target) {
                        // 如果四数之和等于零
                        // 那么表示找到一组解，将其加入 ans
                        ans.push_back({numI, numJ, numP, numQ});
                        // 并且指针 p 向右移动，直至遇到第一个不相同的数或到达 n
                        // 同时指针 q 向左移动，直至遇到第一个不相同的数或到达 j
                        while (++p < n && nums[p] == numP);
                        while (--q > j && nums[q] == numQ);
                    } else if (sum < target) {
                        // 如果四数之和小于零
                        // 那么指针 p 向右移动，直至遇到第一个不相同的数或到达 n
                        while (++p < n && nums[p] == numP);
                    } else if (sum > target) {
                        // 如果四数之和大于零
                        // 那么指针 q 向左移动，直至遇到第一个不相同的数或到达 j
                        while (--q > j && nums[q] == numQ);
                    }
                }
            }
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> ans = solution->fourSum(nums, target);
    for (vector<vector<int>>::iterator iter_outer = ans.begin(); iter_outer != ans.end(); iter_outer++) {
        for (vector<int>::iterator iter_inner = (*iter_outer).begin(); iter_inner != (*iter_outer).end(); iter_inner++) {
            cout << (*iter_inner) << " ";
        }
        cout << endl;
    }
}
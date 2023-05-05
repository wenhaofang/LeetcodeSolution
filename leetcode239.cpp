/*************************************************
Author: wenhaofang
Date: 2023-05-05
Description: leetcode239 - Sliding Window Maximum
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：单调队列
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(k)
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        vector<int> r;
        deque <int> q;
        // 初始阶段
        for (int i = 0; i < k; i++) {
            // 新窗口右端元素进队
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        r.push_back(nums[q.front()]); // 保存结果
        // 更新阶段
        for (int i = k; i < n; i++) {
            // 旧窗口左端元素出队
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }
            // 新窗口右端元素进队
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            r.push_back(nums[q.front()]); // 保存结果
        }
        // 返回结果
        return r;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = solution -> maxSlidingWindow(nums, k);
    for (auto item: ans) {
        cout << item << " ";
    }
}
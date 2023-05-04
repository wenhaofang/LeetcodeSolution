/*************************************************
Author: wenhaofang
Date: 2023-05-04
Description: leetcode496 - Next Greater Element II
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：单调栈 + 循环数组
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack <int> s;
        // 遍历范围从 [n - 1, 0] 变成 [n * 2 - 1, 0]
        for (int i = n * 2 - 1; i >= 0; i--) {
            // 取值从 i 变成 i % n
            while (!s.empty() && s.top() <= nums[i % n]) s.pop();
            ans[i % n] = !s.empty() ? s.top() : -1;
            s.push(nums[i % n]);
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {1, 2, 1};
    vector<int> ans = solution -> nextGreaterElements(nums);
    for (auto item: ans) {
        cout << item << " ";
    }
}
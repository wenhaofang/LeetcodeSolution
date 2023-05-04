/*************************************************
Author: wenhaofang
Date: 2023-05-04
Description: leetcode496 - Next Greater Element I
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：单调栈 + 哈希映射
 * 
 * 理论时间复杂度：O(m + n), 其中 m、n 分别为数组 nums1 和 nums2 的大小
 * 理论空间复杂度：O(n)
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // 
        vector<int> nextG = myNextGreaterElement(nums2);
        // 
        unordered_map<int, int> map;
        for (int i = 0; i < nums2.size(); i++) {
            map[nums2[i]] = nextG[i];
        }
        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            ans[i] = map[nums1[i]];
        }
        return ans;
    }

    // 下一个更大元素
    vector<int> myNextGreaterElement(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack <int> s;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i]) s.pop();
            ans[i] = !s.empty() ? s.top() : -1;
            s.push(nums[i]);
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = solution -> nextGreaterElement(nums1, nums2);
    for (auto item: ans) {
        cout << item << " ";
    }
}
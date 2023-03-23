/*************************************************
Author: wenhaofang
Date: 2023-03-23
Description: leetcode238 - Product of Array Except Self
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：前缀和
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 */
/**
 * 思路
 * 
 * 先从暴力做法入手
 * 
 * 例如 1 2 3 4 5
 * 求1:   - - - -
 * 求2: -   - - -
 * 求3: - -   - -
 * 求4: - - -   -
 * 求5: - - - -
 * 
 * 发现有很多计算都是重复的，有点像前缀和，所以
 * 
 *                 1   2   3   4    5
 * 预先计算好 l2r:      2   6  24  120
 * 同时计算好 r2l: 24  24  12   4
 * 
 * 那么要计算 ans: ans[i] = l2r[i - 1] * r2l[i + 1]
 * 
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> l2r(n, 1);
        l2r[0] = nums[0];
        for (int i = 1; i <= n - 2; i++) {
            l2r[i] = nums[i] * l2r[i - 1];
        }
        vector<int> r2l(n, 1);
        r2l[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            r2l[i] = nums[i] * r2l[i + 1];
        }
        vector<int> ans(n);
        ans[0] = r2l[1];
        ans[n - 1] = l2r[n - 2];
        for (int i = 1; i <= n - 2; i++) {
            ans[i] = l2r[i - 1] * r2l[i + 1];
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = solution -> productExceptSelf(nums);
    for (auto item: ans) {
        cout << item << " ";
    }
}
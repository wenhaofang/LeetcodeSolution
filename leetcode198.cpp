/*************************************************
Author: wenhaofang
Date: 2023-03-23
Description: leetcode198 - House Robber
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：动态规划
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 */

class Solution {
public:
    unordered_map<int, int> true_map;
    unordered_map<int, int> false_map;

    int rob(vector<int>& nums) {
        return dfs(nums, nums.size() - 1, true);
    }

    int dfs(vector<int>& nums, int i, bool canSteal) {
        if (i < 0) {
            return 0;
        }
        if (canSteal) {
            if (true_map.find(i) == true_map.end()) {
                true_map[i] = dfs(nums, i - 1, false) + nums[i];
            }
            if (false_map.find(i) == false_map.end()) {
                false_map[i] = dfs(nums, i - 1, true);
            }
            return max(true_map[i], false_map[i]);
        }
        else {
            if (false_map.find(i) == false_map.end()) {
                false_map[i] = dfs(nums, i - 1, true);
            }
            return false_map[i];
        }
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {1, 2, 3, 1};
    int ans = solution -> rob(nums);
    cout << ans << endl;
}
/*************************************************
Author: wenhaofang
Date: 2023-03-12
Description: leetcode169 - Majority Element
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        int m = n / 2;
        for (int num: nums) {
            map[num]++;
            if (map[num] > m) {
                return num;
            }
        }
        return -1;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {3, 2, 3};
    int ans = solution -> majorityElement(nums);
    cout << ans << endl;
}
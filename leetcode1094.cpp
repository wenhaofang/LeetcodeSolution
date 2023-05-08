/*************************************************
Author: wenhaofang
Date: 2023-05-08
Description: leetcode1094 - Car Pooling
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：差分数组
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 */

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> nums(1005);
        vector<int> diff(1005);
        for (vector<int> trip: trips) {
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }
        nums[0] = diff[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i - 1] + diff[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > capacity) {
                return false;
            }
        }
        return true;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<vector<int>> trips = {
        {2, 1, 5},
        {3, 3, 7}
    };
    int capacity = 3;
    bool ans = solution -> carPooling(trips, capacity);
    cout << ans << endl;
}
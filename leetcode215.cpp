/*************************************************
Author: wenhaofang
Date: 2023-03-23
Description: leetcode215 - Kth Largest Element in an Array
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：堆 (最小堆)
 * 
 * 理论时间复杂度：O(nlogn)，其中 n 为数组大小
 * 理论空间复杂度：O(nlogn)，其中 n 为数组大小
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < nums.size(); i++) {
            if (q.size() < k) {
                q.push(nums[i]);
            } else {
                if (q.top() < nums[i]) {
                    q.pop();
                    q.push(nums[i]);
                }
            }
        }
        return q.top();
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int ans = solution -> findKthLargest(nums, k);
    cout << ans << endl;
}
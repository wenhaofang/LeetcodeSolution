/*************************************************
Author: wenhaofang
Date: 2023-05-08
Description: leetcode1109 - Corporate Flight Bookings
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
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums(n);
        vector<int> diff(n);
        for (vector<int> booking: bookings) {
            diff[booking[0] - 1] += booking[2];
            if  (booking[1] < n) {
                diff[booking[1]] -= booking[2];
            }
        }
        nums[0] = diff[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i - 1] + diff[i];
        }
        return nums;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<vector<int>> bookings = {
        {1, 2, 10},
        {2, 3, 20},
        {2, 5, 25}
    };
    int n = 5;
    vector<int> ans = solution -> corpFlightBookings(bookings, n);
    for (auto item: ans) {
        cout << item << " ";
    }
}
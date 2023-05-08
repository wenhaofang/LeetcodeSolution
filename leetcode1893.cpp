/*************************************************
Author: wenhaofang
Date: 2023-05-08
Description: leetcode1893 - Check if All the Integers in a Range Are Covered
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
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> nums(55);
        vector<int> diff(55);
        for (vector<int> range: ranges) {
            diff[range[0]] += 1;
            diff[range[1] + 1] -= 1;
        }
        nums[0] = diff[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i - 1] + diff[i];
        }
        for (int i = left; i <= right; i++) {
            if (nums[i] == 0) {
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
    vector<vector<int>> ranges = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    int left = 2;
    int right = 5;
    bool ans = solution -> isCovered(ranges, left, right);
    cout << ans << endl;
}
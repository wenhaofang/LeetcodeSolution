/*************************************************
Author: wenhaofang
Date: 2023-03-21
Description: leetcode283 - Move Zeroes
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：快慢指针
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return;
        }
        int slow = -1;
        int fast = -1;
        while (true) {
            slow++;
            while (++fast < n && nums[fast] == 0);
            if (fast < n) {
                nums[slow] = nums[fast];
            } else {
                for (int i = slow; i < n; i++) {
                    nums[i] = 0;
                }
                break;
            }
        }
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {0, 1, 0, 3, 12};
    solution -> moveZeroes(nums);
    for(auto item: nums) {
        cout << item << endl;
    }
}
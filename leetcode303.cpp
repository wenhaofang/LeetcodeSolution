/*************************************************
Author: wenhaofang
Date: 2023-05-07
Description: leetcode303 - Range Sum Query - Immutable
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：前缀和
 * 
 * 理论时间复杂度：
 * 理论空间复杂度：
 */

class NumArray {
public:
    vector<int> sums; // 前缀和

    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int left , int right) {
        return sums[right + 1] - sums[left];
    }
};

/**
 * 测试
 */
int main() {

}
/*************************************************
Author: wenhaofang
Date: 2023-03-21
Description: leetcode560 - Subarray Sum Equals K
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：暴力
 * 
 * 理论时间复杂度：O(n^2)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 */

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         if (n == 0) {
//             return 0;
//         }
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             int sum = 0;
//             for (int j = i; j >= 0; j--) {
//                 sum += nums[j];
//                 if (sum == k) {
//                     ans ++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

/**
 * 方法二：前缀和
 * 
 * 理论时间复杂度：O(n^2)，其中 n 为数组大小
 * 理论空间复杂度：O(n)  ，其中 n 为数组大小
 */

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         if (n == 0) {
//             return 0;
//         }
//         vector<int> prefix(n + 1, 0);
//         int sum = 0;
//         for (int i = 0; i < n; i++) {
//             sum += nums[i];
//             prefix[i + 1] = sum;
//         }
//         int ans = 0;
//         for (int i = 1; i <= n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (prefix[i] - prefix[j] == k) {
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

/**
 * 方法三：前缀和 + 哈希
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        unordered_map<int, int> map;
        map[0]++; // 前缀和
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (map.find(sum - k) != map.end()) {
                ans += map[sum - k];
            }
            map[sum]++;
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int ans = solution -> subarraySum(nums, k);
    cout << ans << endl;
}
/*************************************************
Author: wenhaofang
Date: 2023-03-21
Description: leetcode448 - Find All Numbers Disappeared in an Array
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：哈希
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 */

// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         unordered_set<int> set;
//         for (int num: nums) {
//             set.insert(num);
//         }
//         vector<int> ans;
//         for (int i = 1; i <= nums.size(); i++) {
//             if (set.find(i) == set.end()) {
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };

/**
 * 方法二：原地哈希
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 */
/**
 * 思路
 * 
 * 就用当前数组做哈希表，构建哈希表时给元素赋一个不可取的值，之后再还原
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[(nums[i] - 1) % n] += n;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] > n) {
                nums[i] %= n;
            } else {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = solution -> findDisappearedNumbers(nums);
    for(auto item: ans) {
        cout << item << " ";
    }
}
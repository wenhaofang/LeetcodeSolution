/*************************************************
Author: wenhaofang
Date: 2021-06-26
Description: leetcode47 - Permutations II
*************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>

using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::stack;
using std::queue;
using std::priority_queue;
using std::max;
using std::min;
using std::pair;
using std::cin;
using std::cout;
using std::endl;

/**
 * 方法一：回溯 + 哈希
 * 
 * 理论时间复杂度：O(n × n!)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 8.4 MB, less than 88.97% of C++ online submissions
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        vector<bool> map(n, false);
        backtrack(ans, cur, nums, n, map);
        return ans;
    }

    void backtrack(
        vector<vector<int>>& ans,
        vector<int>& cur,
        vector<int>& nums,
        int n,
        vector<bool>& map
    ) {
        int m = cur.size();
        if (m == n) {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (
                map[i] == true ||
                (i > 0 && nums[i] == nums[i - 1] && map[i - 1] == false)
            ) {
                continue;
            }
            cur.push_back(nums[i]);
            map[i] = true;
            backtrack(ans, cur, nums, n, map);
            cur.pop_back();
            map[i] = false;
        }
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> ans = solution -> permuteUnique(nums);
    for (vector<vector<int>>::iterator outer_iter = ans.begin(); outer_iter != ans.end(); outer_iter++) {
        for (vector<int>::iterator inner_iter = (*outer_iter).begin(); inner_iter != (*outer_iter).end(); inner_iter++) {
            cout << (*inner_iter) << " ";
        }
        cout << endl;
    }
}
/*************************************************
Author: wenhaofang
Date: 2021-07-04
Description: leetcode78 - Subsets
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
 * 方法一：回溯
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7 MB, less than 82.81% of C++ online submissions
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        int begin = 0;
        backtrack(ans, cur, nums, begin);
        return ans;
    }

    void backtrack(
        vector<vector<int>>& ans,
        vector<int>& cur,
        vector<int>& nums,
        int begin
    ) {
        ans.push_back(cur);
        int n = nums.size();
        for (int i = begin; i < n; i++) {
            cur.push_back(nums[i]);
            backtrack(ans, cur, nums, i + 1);
            cur.pop_back();
        }
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = solution -> subsets(nums);
    for (vector<vector<int>>::iterator outer_iter = ans.begin(); outer_iter != ans.end(); outer_iter++) {
        for (vector<int>::iterator inner_iter = (*outer_iter).begin(); inner_iter != (*outer_iter).end(); inner_iter++) {
            cout << (*inner_iter) << " ";
        }
        cout << endl;
    }
}
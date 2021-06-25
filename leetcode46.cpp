/*************************************************
Author: wenhaofang
Date: 2021-06-25
Description: leetcode46 - Permutations
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
 * 实际空间复杂度：Memory Usage: 8 MB, less than 30.17% of C++ online submissions
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> cur;
        unordered_set<int> set;
        backtrack(ans, cur, nums, n, set);
        return ans;
    }

    void backtrack(
        vector<vector<int>>& ans,
        vector<int>& cur,
        vector<int>& nums,
        int n,
        unordered_set<int>& set
    ) {
        int m = cur.size();
        if (m == n) {
            ans.push_back(cur);
            return;
        }

        for (int num: nums) {
            if (set.find(num) != set.end()) {
                continue;
            }
            cur.push_back(num);
            set.insert(num);
            backtrack(ans, cur, nums, n, set);
            cur.pop_back();
            set.erase(num);
        }
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = solution -> permute(nums);
    for (vector<vector<int>>::iterator outer_iter = ans.begin(); outer_iter != ans.end(); outer_iter++) {
        for (vector<int>::iterator inner_iter = (*outer_iter).begin(); inner_iter != (*outer_iter).end(); inner_iter++) {
            cout << (*inner_iter) << " ";
        }
        cout << endl;
    }
}
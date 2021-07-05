/*************************************************
Author: wenhaofang
Date: 2021-07-07
Description: leetcode40 - Combination Sum II
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
 * 实际空间复杂度：Memory Usage: 10.4 MB, less than 94.21% of C++ online submissions
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtrack(ans, cur, candidates, 0, target);
        return ans;
    }

    void backtrack(
        vector<vector<int>>& ans,
        vector<int>& cur,
        vector<int>& candidates,
        int begin,
        int resNum
    ) {
        if (resNum == 0) {
            ans.push_back(cur);
            return;
        }
        int n = candidates.size();
        for (int i = begin; i < n; i++) {
            int num = candidates[i];
            if (i > begin && num == candidates[i - 1]) {
                continue;
            }
            if (num > resNum) {
                break;
            }
            cur.push_back(num);
            backtrack(ans, cur, candidates, i + 1, resNum - num);
            cur.pop_back();
        }
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = solution -> combinationSum2(candidates, target);
    for (vector<vector<int>>::iterator outer_iter = ans.begin(); outer_iter != ans.end(); outer_iter++) {
        for (vector<int>::iterator inner_iter = (*outer_iter).begin(); inner_iter != (*outer_iter).end(); inner_iter++) {
            cout << (*inner_iter) << " ";
        }
        cout << "\n";
    }
}
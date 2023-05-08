/*************************************************
Author: wenhaofang
Date: 2023-05-08
Description: leetcode2536 - Increment Submatrices by One
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：差分矩阵
 * 
 * 理论时间复杂度：O(n * n)
 * 理论空间复杂度：O(n * n)
 */

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> nums(n, vector<int>(n));
        vector<vector<int>> diff(n, vector<int>(n));
        for (vector<int> query: queries) {
            diff[query[0]][query[1]] += 1;
            if (query[3] + 1 < n) {
                diff[query[0]][query[3] + 1] -= 1;
            }
            if (query[2] + 1 < n) {
                diff[query[2] + 1][query[1]] -= 1;
            }
            if (
                query[2] + 1 < n &&
                query[3] + 1 < n
            ) {
                diff[query[2] + 1][query[3] + 1] += 1;
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    nums[i][j] = diff[i][j];
                } else {
                    nums[i][j] = nums[i - 1][j] + diff[i][j];
                }
            }
        }
        for (int i = 0; i < n; i++) { // 这里是 nums
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    nums[i][j] = nums[i][j];
                } else {
                    nums[i][j] = nums[i][j - 1] + nums[i][j];
                }
            }
        }
        return nums;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int n = 3;
    vector<vector<int>> queries = {
        {1, 1, 2, 2},
        {0, 0, 1, 1}
    };
    vector<vector<int>> ans = solution -> rangeAddQueries(n, queries);
    for (vector<vector<int>>::iterator outer_iter = ans.begin(); outer_iter != ans.end(); outer_iter++) {
        for (vector<int>::iterator inner_iter = (*outer_iter).begin(); inner_iter != (*outer_iter).end(); inner_iter++) {
            cout << (*inner_iter) << " ";
        }
        cout << "\n";
    }
}
/*************************************************
Author: wenhaofang
Date: 2023-05-08
Description: leetcode2406 - Divide Intervals Into Minimum Number of Groups
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
    int minGroups(vector<vector<int>>& intervals) {
        int N = INT_MIN;
        for (vector<int> interval: intervals) {
            N = max(N, interval[1]);
        }
        vector<int> diff(N + 1);
        for (vector<int> interval: intervals) {
            diff[interval[0]] += 1;
            if  (interval[1] + 1 <= N) {
                diff[interval[1] + 1] -= 1;
            }
        }
        int sum = 0;
        int ans = INT_MIN;
        for (int i = 1; i <= N; i++) {
            sum += diff[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<vector<int>> intervals = {
        {5, 10},
        {6,  8},
        {1,  5},
        {2,  3},
        {1, 10}
    };
    bool ans = solution -> minGroups(intervals);
    cout << ans << endl;
}
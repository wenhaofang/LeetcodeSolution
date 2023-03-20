/*************************************************
Author: wenhaofang
Date: 2023-03-20
Description: leetcode739 - Daily Temperatures
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：单调栈
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? 0 : (s.top() - i);
            s.push(i);
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = solution -> dailyTemperatures(temperatures);
    for(auto item: ans) {
        cout << item << " ";
    }
}
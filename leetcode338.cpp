/*************************************************
Author: wenhaofang
Date: 2023-03-21
Description: leetcode338 - Counting Bits
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：位运算
 */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            int a = i;
            int c = 0;
            while (a) {
                a &= a - 1;
                c++;
            }
            ans[i] = c;
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int n = 2;
    vector<int> ans = solution -> countBits(n);
    for(auto item: ans) {
        cout << item << endl;
    }
}
/*************************************************
Author: wenhaofang
Date: 2023-03-20
Description: leetcode647 - Palindromic Substrings
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：中心拓展
 * 
 * 理论时间复杂度：O(n^2)，其中 n 为字符串长度
 * 理论空间复杂度：O(1)
 */

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        // 奇数
        for (int i = 0; i < n; i++) {
            ans++;
            int j = i - 1;
            int k = i + 1;
            while (j >= 0 && k <= n - 1) {
                if (s[j] == s[k]) {
                    j--;
                    k++;
                    ans++;
                } else {
                    break;
                }
            }
        }
        // 偶数
        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            if (s[i] == s[j]) {
                ans++;
            } else {
                continue;
            }
            int k = i - 1;
            int l = j + 1;
            while (k >= 0 && l <= n - 1) {
                if (s[k] == s[l]) {
                    k--;
                    l++;
                    ans++;
                } else {
                    break;
                }
            }
        }
        // 返回
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string s = "abc";
    int ans = solution -> countSubstrings(s);
    cout << ans << endl;
}
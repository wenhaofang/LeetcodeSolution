/*************************************************
Author: wenhaofang
Date: 2023-03-21
Description: leetcode347 - Top K Frequent Elements
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：堆 (最小堆)
 * 
 * 理论时间复杂度：O(nlogk)，其中 n 为数组大小
 * 理论空间复杂度：O(n)    ，其中 n 为数组大小
 */

class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> elem2freq;
        for (int num: nums) {
            elem2freq[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(&cmp);
        for (unordered_map<int, int>::iterator it = elem2freq.begin(); it != elem2freq.end(); it++) {
            if (q.size() < k) {
                q.emplace(it -> first, it -> second);
            } else {
                pair<int, int> tmp = q.top();
                if (it -> second > tmp.second) {
                    q.pop();
                    q.emplace(it -> first, it -> second);
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            pair<int, int> tmp = q.top();
            ans.push_back(tmp.first);
            q.pop();
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> ans = solution -> topKFrequent(nums, k);
    for(auto item: ans) {
        cout << item << endl;
    }
}
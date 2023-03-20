/*************************************************
Author: wenhaofang
Date: 2023-03-20
Description: leetcode621 - Task Scheduler
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：数学
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 */
/**
 * 思路
 *           |      n + 1      |
 *           |-----|-----|-----|
 *          /|  A  |  B  | ... |
 * maxE - 1  |-----|-----|-----|
 *          \|  A  |  B  | ... |
 *           |-----|-----|-----|
 *           |  A  |  B  |     |
 *           |-----|-----|-----|
 *           |    maxC   |
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 统计最多执行多少次
        int maxE = -1;
        unordered_map<char, int> map;
        for (char c: tasks) {
            map[c]++;
            maxE = max(maxE, map[c]);
        }
        // 统计有多少个执行最多次
        int maxC = 0;
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it -> second == maxE) {
                maxC++;
            }
        }
        // 返回答案
        int temp1 = (maxE - 1) * (n + 1) + maxC;
        int temp2 = tasks.size();
        return max(temp1, temp2);
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    int ans = solution -> leastInterval(tasks, n);
    cout << ans << endl;
}
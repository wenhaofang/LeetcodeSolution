/*************************************************
Author: wenhaofang
Date: 2023-03-11
Description: leetcode96 - Unique Binary Search Trees
*************************************************/

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>

using std::list;
using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::stack;
using std::queue;
using std::priority_queue;
using std::max;
using std::min;
using std::swap;
using std::pair;
using std::atoi;
using std::stoi;
using std::to_string;
using std::cin;
using std::cout;
using std::endl;

/**
 * 方法一：递归
 * 
 * 理论时间复杂度：O(n^2)，其中 n 为节点数量
 * 理论空间复杂度：O(n)  ，其中 n 为节点数量
 */

class Solution {
public:
    unordered_map<int, int> mem;

    int numTrees(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 1;
        }
        if (mem.find(n) != mem.end()) {
            return mem[n];
        }
        int ans = 0;
        for (int i = 0; i <= n - 1; i++) {
            int l = i;
            int r = n - 1 - i;
            mem[l] = numTrees(l);
            mem[r] = numTrees(r);
            ans += mem[l] * mem[r];
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int n = 3;
    int ans = solution -> numTrees(n);
    cout << ans << endl; // ?
}
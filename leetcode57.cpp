/*************************************************
Author: wenhaofang
Date: 2022-01-31
Description: leetcode57 - Insert Interval
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
using std::swap;
using std::pair;
using std::cin;
using std::cout;
using std::endl;

/**
 * 方法一：暴力模拟
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 20 ms, faster than 57.54% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 17.1 MB, less than 76.00% of C++ online submissions
 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int minV = newInterval[0];
        int maxV = newInterval[1];
        bool placed = false; // 插入的区间是否已加入答案
        vector<vector<int>> ans;
        for (const vector<int> & interval: intervals) {
            if (interval[1] < minV) {
                // 当前遍历区间在插入区间的左侧且无交集
                ans.emplace_back(interval);
            } else if (interval[0] > maxV) {
                // 当前遍历区间在插入区间的右侧且无交集
                if (!placed) {
                    ans.emplace_back(vector<int>{minV, maxV});
                    placed = true;
                }
                ans.emplace_back(interval);
            } else {
                // 当前遍历区间与插入区间有交集
                minV = min(minV, interval[0]);
                maxV = max(maxV, interval[1]);
            }
        }
        // 包尾
        if (!placed) {
            ans.emplace_back(vector<int>{minV, maxV});
            placed = true;
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    vector<vector<int>> ans = solution -> insert(intervals, newInterval);
    for (vector<vector<int>>::iterator outer_iter = ans.begin(); outer_iter != ans.end(); outer_iter++) {
        for (vector<int>::iterator inner_iter = (*outer_iter).begin(); inner_iter != (*outer_iter).end(); inner_iter++) {
            cout << (*inner_iter) << " ";
        }
        cout << "\n";
    }
}
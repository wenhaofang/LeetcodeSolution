/*************************************************
Author: wenhaofang
Date: 2022-01-30
Description: leetcode56 - Merge Intervals
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
 * 方法一：双指针
 * 
 * 理论时间复杂度：O(nlogn)，其中 n 为数组大小
 * 理论空间复杂度：O(logn) ，其中 n 为数组大小
 * 
 * 实际时间复杂度：Runtime: 28 ms, faster than 54.31% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 18.8 MB, less than 48.03% of C++ online submissions
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 特判
        int n = intervals.size();
        if (n == 0) {
            return {};
        }
        // 处理
        sort(intervals.begin() , intervals.end()); // 先排序
        vector<vector<int>> ans;
        int lp = 0; // 左指针
        int rp = 0; // 右指针
        int minV, maxV; // 区间最小值，区间最大值
        int lVal, rVal; // 该区间左值，该区间右值
        while (true) {
            if (rp == lp) {
                // 初始情况：左指针等于右指针
                // 赋值区间最小值和区间最大值，之后右指针前移一步
                minV = intervals[rp][0];
                maxV = intervals[rp][1];
                rp = rp + 1;
            } else {
                // 其余情况：左指针小于右指针
                // 赋值该区间左值和该区间右值
                lVal = intervals[rp][0];
                rVal = intervals[rp][1];
                if (lVal > maxV) {
                    // 如果该区间左值大于区间最大值，说明不可与前面的区间合并
                    // 那么将前面的区间加入答案列表，之后左指针赋值为右指针，开始新一轮合并
                    ans.emplace_back(vector<int>{minV, maxV});
                    lp = rp;
                } else {
                    // 如果该区间左值小于等于区间最大值，可以与前面的区间合并
                    // 那么更新区间最大值，之后右指针前移一步，继续寻找下一个区间
                    maxV = max(maxV, rVal);
                    rp = rp + 1;
                }
            }
            // 包尾
            if (rp >= n) {
                ans.emplace_back(vector<int>{minV, maxV});
                break;
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
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = solution -> merge(intervals);
    for (vector<vector<int>>::iterator outer_iter = ans.begin(); outer_iter != ans.end(); outer_iter++) {
        for (vector<int>::iterator inner_iter = (*outer_iter).begin(); inner_iter != (*outer_iter).end(); inner_iter++) {
            cout << (*inner_iter) << " ";
        }
        cout << "\n";
    }
}
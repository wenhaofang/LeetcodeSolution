/*************************************************
Author: wenhaofang
Date: 2022-12-02
Description: leetcode435 - Non-overlapping Intervals
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
 * 方法一：贪心算法
 * 
 * 理论时间复杂度：O(nlogn)，其中 n 为区间数量
 * 理论空间复杂度：O( logn)，其中 n 为区间数量
 * 
 * 实际时间复杂度：Runtime: 449 ms, faster than 95.82% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 89.9 MB, less than 47.79% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 1.题目要求移除最少数量的区间使得剩余的区间互不重叠
 *   可转换为选择最多数量的区间使得选择的区间互不重叠
 * 
 * 2.根据贪心算法的思路，每次选择右端点最小且不与先前区间重叠的区间即可
 *   这是因为同样是增加一个区间，如果选择右端点较小的区间，那么以后选择的可能性更多
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 特判
        int n = intervals.size();
        if (n <= 0) {
            return 0;
        }
        // 预处理，为了提高效率
        // 按右端点从小到大排序
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
            return u[1] < v[1];
        });
        // 每次选择右端点最小且不与先前区间重叠的区间
        int ans = 1;
        int end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            // 因为数组已提前排序，所以按顺序遍历就能选择右端点最小的区间
            // 然后只需保证当前区间与先前区间无重叠，也即当前区间的左端点大于等于先前区间的右端点
            if (intervals[i][0] >= end) {
                ans = ans + 1;
                end = intervals[i][1];
            }
        }
        // 返回结果
        return n - ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<vector<int>> intervals {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3}
    };
    int ans = solution -> eraseOverlapIntervals(intervals);
    cout << ans << endl;
}
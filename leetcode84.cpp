/*************************************************
Author: wenhaofang
Date: 2022-02-25
Description: leetcode84 - Largest Rectangle in Histogram
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
 * 理论时间复杂度：O(n^2)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Time Limit Exceeded
 * 实际空间复杂度：Time Limit Exceeded
 */
/**
 * 基本思路
 * 
 * 双重循环遍历矩形的宽，外循环确定左边界，内循环确定有边界
 */
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int ans = 0;
//         int tmp = 0;
//         for (int i = 0; i < n; i++) { // 遍历左边界
//             tmp = INT_MAX;
//             for (int j = i; j < n; j++) { // 遍历右边界
//                 tmp = min(tmp, heights[j]);
//                 ans = max(ans, (j - i + 1) * tmp);
//             }
//         }
//         return ans;
//     }
// };

/**
 * 方法二：暴力模拟
 * 
 * 理论时间复杂度：O(n^2)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Time Limit Exceeded
 * 实际空间复杂度：Time Limit Exceeded
 */
/**
 * 基本思路
 * 
 * 单层循环遍历矩形的高，将该高度作为最小高度，再左右两边分别找左右边界
 */
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int ans = 0;
//         int tmp = 0;
//         for (int i = 0; i < n; i++) {
//             tmp = heights[i];
//             // 确定左边界：左边第一个比最小高度小的值
//             int j = i;
//             while (j - 1 >= 0 && heights[j - 1] >= tmp) {
//                 j -= 1;
//             }
//             // 找出右边界：右边第一个比最小高度小的值
//             int k = i;
//             while (k + 1 <  n && heights[k + 1] >= tmp) {
//                 k += 1;
//             }
//             // 计算面积
//             ans = max(ans, (k - j + 1) * tmp);
//         }
//         return ans;
//     }
// };

/**
 * 方法三：单调栈
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 * 
 * 实际时间复杂度：Runtime: 164 ms, faster than 64.48% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 81.6 MB, less than 5.53% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 对思路二进行优化
 * 
 * 预先计算每个位置左右边界，实际上就是找每个位置左边右边第一个比当前元素小的元素
 * 
 * 这种情况可以用单调递减栈辅助计算
 */
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         // 计算每个高度的左边界
//         vector<int> l_vec(n); // 储存左边界的数组
//         stack <int> l_stk;    // 单调栈
//         for (int i = 0; i < n; i++) {
//             // 从左往后遍历
//             while (
//                 !l_stk.empty() &&
//                 heights[l_stk.top()] >= heights[i]
//             ) {
//                 l_stk.pop();
//             }
//             l_vec[i] = l_stk.empty() ? -1 : l_stk.top(); // -1 为哨兵
//             l_stk.push(i);
//         }
//         // 计算每个高度的右边界
//         vector<int> r_vec(n); // 储存右边界的数组
//         stack <int> r_stk;    // 单调栈
//         for (int i = n - 1; i >= 0; i--) {
//             // 从右往左遍历
//             while (
//                !r_stk.empty() &&
//                heights[r_stk.top()] >= heights[i] 
//             ) {
//                 r_stk.pop();
//             }
//             r_vec[i] = r_stk.empty() ? n : r_stk.top(); // n 为哨兵
//             r_stk.push(i);
//         }
//         // 答案
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             ans = max(ans, (r_vec[i] - l_vec[i] - 1) * heights[i]);
//         }
//         return ans;
//     }
// };

/**
 * 方法四：单调栈
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 * 
 * 实际时间复杂度：Runtime: 144 ms, faster than 74.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 81.5 MB, less than 6.03% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 对思路三进行优化
 * 
 * 遍历一次同时计算左右边界，不用遍历两次分别计算左右边界
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // 同时计算每个高度左右边界
        vector<int> l_vec(n, 0); // 储存左边界的数组
        vector<int> r_vec(n, n); // 储存右边界的数组
        stack <int> stk;         // 单调栈
        for (int i = 0; i < n; i++) {
            while (
                !stk.empty() &&
                heights[stk.top()] >= heights[i]
            ) {
                // 在出栈时确定右边界
                r_vec[stk.top()] = i;
                stk.pop();
            }
            l_vec[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        // 答案
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, (r_vec[i] - l_vec[i] - 1) * heights[i]);
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int ans = solution -> largestRectangleArea(heights);
    cout << ans << endl;
}
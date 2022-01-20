/*************************************************
Author: wenhaofang
Date: 2022-01-20
Description: leetcode42 - Trapping Rain Water
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
 * 方法一：暴力
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
 * 从常规的思路出发，计算每一个数组位置能储存多少雨水
 * 
 * 一个数组位置能储存雨水量等于左边最大高度和右边最大高度的最小值减当前高度
 */
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int ans = 0;
//         int m = 0;
//         int n = height.size() - 1;
//         // 对于每个数组位置
//         for (int i = m + 1; i <= n - 1; i++) {
//             int l_height = 0;
//             int r_height = 0;
//             // 左边最大高度
//             for (int j = i; j >= m; j--) {
//                 l_height = max(l_height, height[j]);
//             }
//             // 右边最大高度
//             for (int j = i; j <= n; j++) {
//                 r_height = max(r_height, height[j]);
//             }
//             // 一个数组位置能储存雨水量等于左边最大高度和右边最大高度的最小值减当前高度
//             ans += min(l_height, r_height) - height[i];
//         }
//         // 返回结果
//         return ans;
//     }
// };

/**
 * 方法二：动态规划
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 * 
 * 实际时间复杂度：Runtime: 10 ms, faster than 57.80% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 16 MB, less than 42.27% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 对上述的思路进行优化，在上述思路中，找出一个位置左边和右边的最大高度需要遍历一遍数组
 * 
 * 这时我们可以提前遍历一遍数组，将最大高度储存下来，则总共只需遍历一遍数组即可
 */
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int m = 0;
//         int n = height.size() - 1;
//         // 构造左边最大高度数组
//         vector<int> l_height(n + 1);
//         l_height[m] = height[m];
//         for (int i = m + 1; i <= n; i++) {
//             l_height[i] = max(height[i], l_height[i - 1]);
//         }
//         // 构造右边最大高度数组
//         vector<int> r_height(n + 1);
//         r_height[n] = height[n];
//         for (int i = n - 1; i >= m; i--) {
//             r_height[i] = max(height[i], r_height[i + 1]);
//         }
//         // 计算答案
//         int ans = 0;
//         for (int i = m; i <= n; i += 1) {
//             ans += min(l_height[i], r_height[i]) - height[i];
//         }
//         return ans;
//     }
// };

/**
 * 方法三：栈
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 * 
 * 实际时间复杂度：Runtime: 8 ms, faster than 83.25% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 16 MB, less than 42.27% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 对上述的思路进行优化，在上述思路中，需要预先遍历一遍数组构造高度数组
 * 
 * 观察到在计算的时候可以只利用左边的信息逐步计算，我们可以使用栈来维护，则能做到边遍历边计算
 */
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int curr = 0;
//         int size = height.size();
//         int ans = 0;
//         stack<int> stk;
//         // 当前的遍历元素：右边界、最高候选
//         // 栈顶第一个元素：左边界、最低
//         // 栈顶第二个元素：无左右、最高候选
//         while (curr < size) {
//             while ( 
//                 !stk.empty() &&
//                 height[curr] > height[stk.top()]
//             ) {
//                 int top = stk.top();
//                 stk.pop();
//                 if (stk.empty()) {
//                     break;
//                 }
//                 // 计算宽、长、面积
//                 int w = curr - stk.top() - 1;
//                 int h = min(height[curr], height[stk.top()]) - height[top];
//                 ans += w * h;
//             }
//             stk.push(curr++);
//         }
//         return ans;
//     }
// };

/**
 * 方法四：双指针
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 8 ms, faster than 83.25% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 15.6 MB, less than 97.26% of C++ online submissions
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int lp = 0;
        int rp = height.size() - 1;
        int l_max = 0;
        int r_max = 0;
        // 到左右指针相遇时停止
        while (lp < rp) {
            if (height[lp] < height[rp]) {
                // 如果左指针较小
                if (height[lp] >= l_max) {
                    // 如果左指针的值大于等于左边最大值
                    // 那么将左边最大值赋值为左指针的值
                    l_max = height[lp];
                } else {
                    // 如果左指针的值小于左边最大值
                    // 那么计算高度
                    ans += l_max - height[lp];
                }
                // 左指针右移一步
                ++lp;
            } else {
                // 如果右指针较小
                if (height[rp] >= r_max) {
                    // 如果右指针的值大于等于右边最大值
                    // 那么将右边最大值赋值为右指针的值
                    r_max = height[rp];
                } else {
                    // 如果右指针的值小于右边最大值
                    // 那么计算高度
                    ans += r_max - height[rp];
                }
                // 右指针左移一步
                --rp;
            }
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ans = solution -> trap(nums);
    cout << ans << endl;
}
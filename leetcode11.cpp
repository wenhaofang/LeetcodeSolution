/*************************************************
Author: wenhaofang
Date: 2021-03-16
Description: leetcode11 - Container With Most Water
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
using std::pair;
using std::cin;
using std::cout;
using std::endl;

/**
 * 思路一：双指针
 * 
 * 时间复杂度：O(n)，其中 n 为数组大小
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 80 ms, faster than 5.51% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 59.1 MB, less than 25.51% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 左右指针初始化分别指向数组头部和尾部
 * 每次将指向数字较小的指针往中间移动，直至两个指针相遇
 * 并且在每次移动时计算矩形面积，其中最大的面积即为答案
 */
/**
 * 思路解析
 * 
 * 为什么上面的思路是可行的呢？首先我们要清楚，移动指针的过程其实就是剪枝的过程
 * 也就是说，我们需要保证每次排除的情况都不可能是最优解，下面来证明这件事情：
 * 
 * 不失一般性，假设 0 <= i < j <= n - 1, H[i] <= H[j] (H[i] > H[j]同理可证)
 * 此时算法会将指针 i 向右移动一位，这意味着以 i 为左指针、j' 为右指针的情况都被排除
 * 其中 j' = i + 1, i + 2, ..., j - 2, j - 1, 这里有两种情况：
 * 1) 若 H[i] <= H[j'], 则 原面积 = H[i] * (j - i) > H[i]  * (j' - i) = 更新后的面积
 * 2) 若 H[i] >  H[j'], 则 原面积 = H[i] * (j - i) > H[j'] * (j' - i) = 更新后的面积
 * 在以上两种情况下，都有原面积 > 更新后的面积，所以排除的情况必定不是最优解
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int curArea = 0, maxArea = 0;
        // 每次往中间移动指针，直至两者相遇
        while (i < j) {
            // 计算面积
            curArea = min(height[i], height[j]) * (j - i);
            maxArea = max(curArea, maxArea);
            // 移动指针
            if (height[i] == height[j]) {
                i++;
                j--;
            } else if (height[i] < height[j]) {
                i++;
            } else if (height[i] > height[j]) {
                j--;
            }
        }
        return maxArea;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int ans = solution->maxArea(height);
    cout << ans << endl;
}
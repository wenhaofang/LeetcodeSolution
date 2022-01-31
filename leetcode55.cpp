/*************************************************
Author: wenhaofang
Date: 2022-01-29
Description: leetcode55 - Jump Game
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
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 56 ms, faster than 87.66% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 48.4 MB, less than 51.75% of C++ online submissions
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxValue = 0; // 维护最远距离
        for (int i = 0; i < n; i++) {
            if (i <= maxValue) {
                maxValue = max(maxValue, i + nums[i]);
                if (maxValue >= n - 1) {
                    return true;
                }
            } else break;
        }
        return false;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {2, 3, 1, 1, 4};
    bool ans = solution -> canJump(nums);
    cout << ans << endl;
}
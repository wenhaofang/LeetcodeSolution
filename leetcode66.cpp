/*************************************************
Author: wenhaofang
Date: 2022-02-09
Description: leetcode66 - Plus One
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
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 8.6 MB, less than 98.48% of C++ online submissions
 */
// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         int n = digits.size();
//         vector<int> ans; // 其实可以设置为固定的长度 n + 1，后面用下标来填充数组
//         int carry = 1;
//         int num, a, b;
//         for (int i = n - 1; i >= 0; i--) {
//             num = digits[i] + carry;
//             ans.emplace_back(num % 10);
//             carry = num / 10;
//         }
//         if (carry > 0) {
//             ans.emplace_back(carry);
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

/**
 * 方法二：数学方法
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 8.8 MB, less than 12.29% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 数字加一的核心特征只在于影响最后的一串九
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                count += 1;
            } else break;
        }
        if (count == 0) {
            vector<int> ans(n, 0);
            for (int i = 0; i < n; i++) {
                ans[i] = digits[i];
            }
            ans[n - 1] += 1;
            return ans;
        }
        if (count == n) {
            vector<int> ans(n + 1, 0);
            ans[0] = 1;
            return ans;
        }
        vector<int> ans(n, 0);
        int split = n - count;
        for (int i = 0; i < split; i++) {
            ans[i] = digits[i];
        }
        ans[split - 1] += 1;
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> digits = {9};
    vector<int> ans = solution -> plusOne(digits);
    for (auto item: ans) {
        cout << item << " ";
    }
}
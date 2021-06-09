/*************************************************
Author: wenhaofang
Date: 2021-03-27
Description: leetcode22 - Generate Parentheses
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
 * 思路一：回溯
 * 
 * 时间复杂度：O(4^n / √n)，其中 n 为括号对数
 * 空间复杂度：O(n)，其中 n 为括号对数
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 11.3 MB, less than 83.80% of C++ online submissions
 */
/**
 * 思路
 * 
 * 回溯算法，遍历剪枝
 * 
 * 在这道题目中，我们要维护一个字符串，表示当前排列
 * 该字符串初始化为空，然后每次取一个（符合条件的）括号加入到该字符串
 * 直至所有括号被用完，至此我们能得到一个可能的排列，将其加入答案数组
 * 之后进行回退操作，遍历其余可能排列
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string combination;
        backtrace(ans, combination, n, n, n * 2);
        return ans;
    }

    void backtrace(
        vector<string>& ans, // 答案数组
        string& combination, // 当前排列
        int lNum, // 左括号剩余个数
        int rNum, // 右括号剩余个数
        int num // 总括号数
    ) {
        if (combination.size() == num) {
            // 当前排列已经用完所有括号
            // 意味着已经得到一个可行解，将其加入答案列表
            ans.push_back(combination);
        } else {
            // 在其余情况下，放入一个括号
            // 剪枝：只有剩余左括号数大于零，才能继续放左括号
            if (lNum > 0) {
                // 深入
                combination.push_back('(');
                // 递归
                backtrace(ans, combination, lNum - 1, rNum, num);
                // 回退
                combination.pop_back();
            }
            // 剪枝：只有剩余左括号数小于剩余右括号数，才能继续放右括号
            if (lNum < rNum) {
                // 深入
                combination.push_back(')');
                // 递归
                backtrace(ans, combination, lNum, rNum - 1, num);
                // 回退
                combination.pop_back();
            }
        }
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int n = 3;
    vector<string> ans = solution->generateParenthesis(n);
    for(auto item: ans) {
        cout << item << " ";
    }
}
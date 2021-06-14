/*************************************************
Author: wenhaofang
Date: 2021-06-13
Description: leetcode32 - Longest Valid Parentheses
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
 * 方法一：栈
 * 
 * 理论时间复杂度：O(n)，其中 n 为字符串长度
 * 理论空间复杂度：O(n)，其中 n 为字符串长度
 * 
 * 实际时间复杂度：Runtime: 4 ms, faster than 81.69% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7.3 MB, less than 28.51% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 通过栈实现在遍历的同时判断子串是否符合要求
 * 栈底元素始终为最后一个没有被匹配的右括号的下标（避免对边界做特殊判断）
 * 栈中其余元素为所有没有被匹配的左括号的下标（核心数据，按顺序维护下一个可以被匹配的括号）
 * 
 * 具体过程描述为从左往右遍历字符串：
 * 1、如果遇到左括号，则将其对应的下标入栈
 * 2、如果遇到右括号，则首先将栈顶下标出栈
 *   1）如果此时栈为空，则该右括号下标入栈
 *   2）如果此时栈不空，则该右括号下标减去栈顶下标就等于 以该右括号为结尾的最长有效括号的长度
 */
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int n = s.length();
//         int ans = 0;
//         stack<int> stk;
//         stk.push(-1);
//         for (int i = 0; i < n; i++) {
//             char c = s[i];
//             if (c == '(') {
//                 stk.push(i);
//             } else {
//                 stk.pop();
//                 if (stk.empty()) {
//                     stk.push(i);
//                 } else {
//                     ans = max(ans, i - stk.top());
//                 }
//             }
//         }
//         return ans;
//     }
// };

/**
 * 方法二：双向遍历
 * 
 * 理论时间复杂度：O(n)，其中 n 为字符串长度
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.7 MB, less than 92.56% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 首先从左往右遍历字符串，并定义两个变量分别记录左、右括号出现的数量
 * 每遍历一个字符时，进行以下两组判断：
 *   1. 如果遇到左括号，则左括号数量加一
 *      如果遇到右括号，则右括号数量加一
 *   2. 如果左括号数量等于右括号数量，则这就是一个符合要求的子串，记录下子串长度
 *      如果左括号数量小于右括号数量，则这是一个不符合要求的子串，将计数变量清零
 * 
 * 然后从右往左遍历字符串，并定义两个变量分别记录左、右括号出现的数量
 * 每遍历一个字符时，进行以下两组判断：
 *   1. 如果遇到左括号，则左括号数量加一
 *      如果遇到右括号，则右括号数量加一
 *   2. 如果左括号数量等于右括号数量，则这就是一个符合要求的子串，记录下子串长度
 *      如果左括号数量大于右括号数量，则这是一个不符合要求的子串，将计数变量清零
 */
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int n = s.length();
//         int ans = 0;
//         // 从左往右遍历
//         int p1 = 0, p2 = 0;
//         for (int i = 0; i < n; i++) {
//             char c = s[i];
//             if (c == '(') {
//                 p1++;
//             } else {
//                 p2++;
//             }
//             if (p1 == p2) {
//                 ans = max(ans, 2 * p2);
//             } else if (p2 > p1) {
//                 p1 = p2 = 0;
//             }
//         }
//         // 从右往左遍历
//         int p3 = 0, p4 = 0;
//         for (int i = n - 1; i >= 0; i--) {
//             char c = s[i];
//             if (c == '(') {
//                 p3++;
//             } else {
//                 p4++;
//             }
//             if (p3 == p4) {
//                 ans = max(ans, 2 * p3);
//             } else if (p3 > p4) {
//                 p3 = p4 = 0;
//             }
//         }
//         // 返回结果
//         return ans;
//     }
// };

/**
 * 方法三：动态规划
 * 
 * 理论时间复杂度：O(n)，其中 n 为字符串长度
 * 理论空间复杂度：O(n)，其中 n 为字符串长度
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7.3 MB, less than 28.51% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 假设 dp[i] 表示以 s[i] 为结尾的合法字符串长度
 * 
 * 如果 s[i] 为左括号，则以该括号为结尾的字符串不可能合法，也即 dp[i] 必定等于 0
 * 
 * 如果 s[i] 为右括号，则有两种情况能得到合法的字符串
 * 
 *   如果 s[i - 1] 为左括号，那么该左括号能与当前的右括号匹配，故有 dp[i] = dp[i - 2] + 2
 * 
 *   如果 s[i - 1] 为右括号且 dp[i - dp[i - 1] - 1] 为左括号，那么该左括号能与当前的右括号匹配，故有 dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2]
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            char c = s[i];
            if (c == '(') {
                dp[i] = 0;
            } else { // c == ')'
                if (s[i - 1] == '(') {
                    dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
                }
                ans = max(ans, dp[i]);
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
    string s = "(()";
    int ans = solution -> longestValidParentheses(s);
    cout << ans << endl;
}
/*************************************************
Author: wenhaofang
Date: 2021-03-25
Description: leetcode20 - Valid Parentheses
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
 * 思路一：栈
 * 
 * 时间复杂度：O(n)，其中 n 为字符串长度
 * 空间复杂度：O(n)，其中 n 为字符串长度
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.4 MB, less than 6.23% of C++ online submissions
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> map = {
            {')', '('}, {']', '['}, {'}', '{'}
        };
        // 遍历字符串
        for (char c: s) {
            // 如果当前字符是左括号
            if (c == '(' || c == '[' || c == '{') {
                // 那么将其加入栈中
                stk.push(c);
            }
            // 如果当前字符是右括号
            if (c == ')' || c == ']' || c == '}') {
                if (!stk.empty() && stk.top() == map[c]) {
                    // 如果栈不为空，并且栈顶字符与当前字符能匹配，那么将其消去
                    stk.pop();
                } else {
                    // 其余情况下，均不能匹配，直接返回 false
                    return false;
                }
            }
        }
        // 最后，如果栈为空，表示可以全部匹配，返回 true
        // 反之，若栈不为空，表示不能全部匹配，返回 false
        return stk.empty();
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string s = "()";
    bool ans = solution->isValid(s);
    cout << ans << endl;
}
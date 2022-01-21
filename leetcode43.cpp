/*************************************************
Author: wenhaofang
Date: 2022-01-21
Description: leetcode43 - Multiply Strings
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
 * 方法一：模拟
 * 
 * 理论时间复杂度：O(m * n)，其中 m、n 分别为两个数组的大小
 * 理论空间复杂度：O(m + n)，其中 m、n 分别为两个数组的大小
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6.8 MB, less than 45.94% of C++ online submissions
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length();
        int n = num2.length();
        // 特判
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        // 按位相乘然后累加
        vector<int> vec(m + n, 0);
        for (int i = m - 1; i >= 0; i--) {
            int xi = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--) {
                int yj = num2.at(j) - '0';
                vec[i + j + 1] += xi * yj;
            }
        }
        for (int k = m + n - 1; k > 0; k--) {
            vec[k - 1] = vec[k - 1] + vec[k] / 10;
            vec[k] = vec[k] % 10;
        }
        // 整型数组转字符串
        string ans;
        if (vec[0] != 0) {
            ans.push_back(vec[0] + '0');
        }
        for (int k = 1; k < m + n; k++) {
            ans.push_back(vec[k] + '0');
        }
        // 返回结果
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string num1 = "123";
    string num2 = "456";
    string ans = solution -> multiply(num1, num2);
    cout << ans << endl;
}
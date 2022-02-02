/*************************************************
Author: wenhaofang
Date: 2022-02-03
Description: leetcode60 - Permutation Sequence
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
 * 方法一：数学方法（康托展开与逆康托展开）
 * 
 * 理论时间复杂度：O(n^2)
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6 MB, less than 48.26% of C++ online submissions
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        // 先计算阶乘，也可以写成固定值加快速度
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        // 逆康托展开：已知某个排列在全排列中的排位，求该排列
        k = k - 1; // 康托展开值，等于排位减一
        vector<int> valid(n + 1, 1); // 表示排列中的每个数是否已被使用
        string ans;
        for (int i = 1; i <= n; i++) {
            int p = k / factorial[n - i] + 1;
            int q = k % factorial[n - i];
            for (int j = 1; j <= n; j++) {
                p -= valid[j];
                if (p == 0) {
                    ans += j + '0';
                    valid[j] = 0;
                    break;
                }
            }
            k = q;
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    int n = 3;
    int k = 3;
    string ans = solution -> getPermutation(n, k);
    cout << ans << endl;
}
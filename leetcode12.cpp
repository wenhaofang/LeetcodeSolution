/*************************************************
Author: wenhaofang
Date: 2021-03-17
Description: leetcode12 - Integer to Roman
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
 * 思路一：硬编码
 * 
 * 时间复杂度：O(1)
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 8 ms, faster than 65.67% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 5.8 MB, less than 97.91% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 将个、十、百、千位所有符号罗列出来
 * 然后将数字拆成个、十、百、千位分别对应上述符号
 */
// class Solution {
// public:
//     string intToRoman(int num) {
//         string ones[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
//         string tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
//         string hundreds[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
//         string thousands[4] = {"", "M", "MM", "MMM"};
//         return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
//     }
// };

/**
 * 思路二：贪心算法
 * 
 * 时间复杂度：O(1)
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 6 MB, less than 79.99% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 将所有的特殊符号罗列出来
 * 每次取最大的符号，然后用数字减去符号对应的值，得到的余数重复上述步骤
 */
class Solution {
public:
    string intToRoman(int num) {
        int digits[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbol[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int cur = 0;
        string ans;
        while (num != 0) {
            if (num >= digits[cur]) {
                num -= digits[cur];
                ans += symbol[cur];
            } else {
                cur += 1;
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
    int num = 3;
    string ans = solution->intToRoman(num);
    cout << ans << endl;
}
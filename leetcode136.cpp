/*************************************************
Author: wenhaofang
Date: 2023-03-12
Description: leetcode136 - Single Number
*************************************************/

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>

using std::list;
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
using std::atoi;
using std::stoi;
using std::to_string;
using std::cin;
using std::cout;
using std::endl;

/**
 * 方法一：哈希
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 */

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int, int> map;
//         for (int num: nums) {
//             map[num] += 1;
//         }
//         for (auto it = map.begin(); it != map.end(); it++) {
//             if (it -> second == 1) {
//                 return it -> first;
//             }
//         }
//         return -1;
//     }
// };

/**
 * 方法二：位运算
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 */
/**
 * 思路
 * 
 * 数组所有元素做异或运算
 * 
 * 异或运算满足以下的性质：
 * 
 * 1、a ⊕ 0 = a
 * 2、a ⊕ a = 0
 * 3、交换律 和 结合律：a ⊕ b = b ⊕ a 和 (a ⊕ b) ⊕ c = a ⊕ (b ⊕ c)
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int num: nums) {
            ans ^= num;
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {2, 2, 1};
    int ans = solution -> singleNumber(nums);
    cout << ans << endl;
}
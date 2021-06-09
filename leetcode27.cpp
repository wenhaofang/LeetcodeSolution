/*************************************************
Author: wenhaofang
Date: 2021-04-01
Description: leetcode27 - Remove Element
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
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 8.8 MB, less than 16.40% of C++ online submissions
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 特判
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        // lPtr: 左指针，从左往右寻找等于 val 的元素
        // rPtr: 右指针，从右往左寻找不等于 val 的元素
        int lPtr = 0;
        int rPtr = size - 1;
        // 循环，直至两指针相遇
        while (lPtr <= rPtr) {
            // 左指针寻找下一个等于 val 的元素
            while (lPtr < size && nums[lPtr] != val) {
                ++lPtr;
            }
            // 右指针寻找下一个不等于 val 的元素
            while (rPtr > -1 && nums[rPtr] == val) {
                --rPtr;
            }
            // 如果左指针在右指针的左边
            if (lPtr < rPtr) {
                // 将右指针指向元素赋值给左指针指向元素
                // 并将左指针右移一位，将右指针左移一位
                nums[lPtr++] = nums[rPtr--];
            }
        }
        // 返回数组大小
        return rPtr + 1;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int ans = solution->removeElement(nums, val);
    cout << ans << endl;
}
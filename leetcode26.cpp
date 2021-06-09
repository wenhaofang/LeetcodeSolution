/*************************************************
Author: wenhaofang
Date: 2021-03-31
Description: leetcode26 - Remove Duplicates from Sorted Array
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
 * 思路一：快慢指针
 * 
 * 时间复杂度：O(n)，其中 n 为数组大小
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 13.7 MB, less than 59.96% of C++ online submissions
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 特判
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        // slow: 慢指针，初始化指向第一个元素
        // fast: 快指针，初始化指向第二个元素
        int slow = 0;
        int fast = 1;
        // 循环，直至快指针到达数组末尾
        while (fast < size) {
            if (nums[slow] == nums[fast]) {
                // 如果快指针指向元素等于慢指针指向元素
                // 那么快指针前移一位
                fast++;
            } else {
                // 如果快指针指向元素不等于慢指针指向元素
                // 那么慢指针前移一位
                // 然后将快指针指向元素赋值给慢指针指向元素
                // 最后快指针前移一位
                slow++;
                nums[slow] = nums[fast];
                fast++;
            }
        }
        // 慢指针指向的是数组最后一位元素
        // 由于题目要求返回数组大小，所以需要加一
        return ++slow;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {1, 1, 2};
    int ans = solution->removeDuplicates(nums);
    cout << ans << endl;
}
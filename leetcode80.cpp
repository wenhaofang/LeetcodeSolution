/*************************************************
Author: wenhaofang
Date: 2022-02-21
Description: leetcode80 - Remove Duplicates from Sorted Array II
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
 * 方法一：快慢指针
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 9 ms, faster than 42.28% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 10.8 MB, less than 75.18% of C++ online submissions
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 特判
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        // slow: 慢指针，初始化指向第三个元素，表示下一个填入的位置
        // fast: 快指针，初始化指向第三个元素，表示下一个填入的元素
        int slow = 2;
        int fast = 2;
        // 循环，直至快指针到达数组末尾
        while  (fast < n) {
            // 如果下一个填入的元素合法
            // 将其填入下一个填入的位置，并且慢指针前移一步
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                slow++;
            }
            // 无论下一个填入的元素是否合法，快指针前移一步
            // 若合法，则已经正确填入；否则，也要继续寻找下一个
            fast++;
        }
        // 慢指针所指位置之前的所有元素都是合法的
        // 因此慢指针位置也代表合法数组长度
        return slow;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int ans = solution -> removeDuplicates(nums);
    cout << ans << endl;
}
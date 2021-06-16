/*************************************************
Author: wenhaofang
Date: 2021-06-17
Description: leetcode35 - Search Insert Position
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
 * 方法一：二分查找
 * 
 * 理论时间复杂度：O(logn)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 4 ms, faster than 83.01% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 9.5 MB, less than 90.70% of C++ online submissions
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int p1 = 0;
        int p2 = n - 1;
        int ans = n;
        while (p1 <= p2) {
            int mid = p1 + (p2 - p1) / 2;
            if (nums[mid] == target) {
                ans = mid;
                p2 = mid - 1;
            } else if (nums[mid] < target) {
                p1 = mid + 1;
            } else if (nums[mid] > target) {
                ans = mid;
                p2 = mid - 1;
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
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;
    int ans = solution -> searchInsert(nums, target);
    cout << ans << endl;
}
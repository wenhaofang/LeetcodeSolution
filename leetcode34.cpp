/*************************************************
Author: wenhaofang
Date: 2021-06-16
Description: leetcode34 - Find First and Last Position of Element in Sorted Array
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
 * 实际时间复杂度：Runtime: 4 ms, faster than 96.21% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 13.7 MB, less than 61.12% of C++ online submissions
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int p1 = lower_bound(nums, target);
        int p2 = upper_bound(nums, target);
        return (p1 == -1 || p2 == -1) ? vector<int>{-1, -1} : vector<int>{p1, p2};
    }

    /**
     * 在升序数组中查找给定值第一个出现的位置
     * 如果能够找到，则返回对应下标；如果没有找到，则返回 -1；
     */
    int lower_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int p1 = 0;
        int p2 = n - 1;
        while (p1 <= p2) {
            int mid = p1 + (p2 - p1) / 2;
            if (nums[mid] == target) {
                p2 = mid - 1;
            } else if (nums[mid] < target) {
                p1 = mid + 1;
            } else if (nums[mid] > target) {
                p2 = mid - 1;
            }
        }
        if (p1 > n - 1 || nums[p1] != target) {
            return -1;
        }
        return p1;
    }

    /**
     * 在升序数组中查找给定值最后一个出现的位置
     * 如果能够找到，则返回对应下标；如果没有找到，则返回 -1；
     */
    int upper_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int p1 = 0;
        int p2 = n - 1;
        while (p1 <= p2) {
            int mid = p1 + (p2 - p1) / 2;
            if (nums[mid] == target) {
                p1 = mid + 1;
            } else if (nums[mid] < target) {
                p1 = mid + 1;
            } else if (nums[mid] > target) {
                p2 = mid - 1;
            }
        }
        if (p2 < 0 || nums[p2] != target) {
            return -1;
        }
        return p2;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 7;
    vector<int> ans = solution -> searchRange(nums, target);
    for (auto item: ans) {
        cout << item << " ";
    }
}
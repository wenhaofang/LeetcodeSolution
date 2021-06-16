/*************************************************
Author: wenhaofang
Date: 2021-06-16
Description: Binary Search
*************************************************/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/**
 * 二分搜索概述
 * 
 * 使用场景：在有序数组中查找给定值的所在位置
 * 
 * 核心思想：通过比较中间值与给定值，每次缩小一半的搜索范围
 */

/**
 * 模板 1：在升序数组中查找给定值
 * 
 * 如果能够找到，则返回对应下标；如果没有找到，则返回 -1；
 */
int binary_search(vector<int>& nums, int target) {
    int n = nums.size();
    int p1 = 0;
    int p2 = n - 1;
    // 搜索范围规定为闭区间 [p1, p2]，当 p1 > p2 时搜索停止
    while (p1 <= p2) {
        int mid = p1 + (p2 - p1) / 2;
        // 分类讨论
        if (nums[mid] == target) {
            // 当中间值等于给定值，能够找到，返回结果
            return mid;
        } else if (nums[mid] < target) {
            // 当中间值小于给定值，将搜索范围约束在右半部分
            p1 = mid + 1;
        } else if (nums[mid] > target) {
            // 当中间值大于给定值，将搜索范围约束在左半部分
            p2 = mid - 1;
        }
    }
    // 没有找到，返回结果
    return -1;
}

/**
 * 模板 2：在升序数组中查找给定值第一个出现的位置
 * 
 * 如果能够找到，则返回对应下标；如果没有找到，则返回 -1；
 */
int lower_bound(vector<int>& nums, int target) {
    int n = nums.size();
    int p1 = 0;
    int p2 = n - 1;
    // 搜索范围规定为闭区间 [p1, p2]，当 p1 > p2 时搜索停止
    while (p1 <= p2) {
        int mid = p1 + (p2 - p1) / 2;
        // 分类讨论
        if (nums[mid] == target) {
            // 不同之处
            // 当中间值等于给定值，将搜索范围约束在左半部分继续搜索
            p2 = mid - 1;
        } else if (nums[mid] < target) {
            // 当中间值小于给定值，将搜索范围约束在右半部分
            p1 = mid + 1;
        } else if (nums[mid] > target) {
            // 当中间值大于给定值，将搜索范围约束在左半部分
            p2 = mid - 1;
        }
    }
    // 不同之处
    // 最后检查 p1 是否符合条件
    if (p1 > n - 1 || nums[p1] != target) {
        return -1;
    }
    return p1;
}

/**
 * 模板 3：在升序数组中查找给定值最后一个出现的位置
 * 
 * 如果能够找到，则返回对应下标；如果没有找到，则返回 -1；
 */
int upper_bound(vector<int>& nums, int target) {
    int n = nums.size();
    int p1 = 0;
    int p2 = n - 1;
    // 搜索范围规定为闭区间 [p1, p2]，当 p1 > p2 时搜索停止
    while (p1 <= p2) {
        int mid = p1 + (p2 - p1) / 2;
        if (nums[mid] == target) {
            // 不同之处
            // 当中间值等于给定值，将搜索范围约束在右半部分继续搜索
            p1 = mid + 1;
        } else if (nums[mid] < target) {
            // 当中间值小于给定值，将搜索范围约束在右半部分
            p1 = mid + 1;
        } else if (nums[mid] > target) {
            // 当中间值大于给定值，将搜索范围约束在左半部分
            p2 = mid - 1;
        }
    }
    // 不同之处
    // 最后检查 p2 是否符合条件
    if (p2 < 0 || nums[p2] != target) {
        return -1;
    }
    return p2;
}

/**
 * 测试
 */
int main() {
    vector<int> nums = {1, 2, 3, 3, 3, 4, 5};
    int target = 3;
    int ans1 = binary_search(nums, target);
    int ans2 = lower_bound(nums, target);
    int ans3 = upper_bound(nums, target);
    cout << "binary_search: " << ans1 << endl;
    cout << "lower_bound  : " << ans2 << endl;
    cout << "upper_bound  : " << ans3 << endl;
}
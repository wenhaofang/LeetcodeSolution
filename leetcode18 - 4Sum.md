---
title: leetcode18 - 4Sum
date: 2021-03-23 09:00:00
categories: leetcode
tags: [leetcode, 数组, 双指针]
---

> leetcode 18
>
> 原题链接[英]：[4Sum](https://leetcode.com/problems/4sum/)
>
> 原题链接[中]：[四数之和](https://leetcode-cn.com/problems/4sum/)

<!--more-->

------

### 题目描述

Given an array `nums` of *n* integers and an integer `target`, are there elements *a*, *b*, *c*, and *d* in `nums` such that *a* + *b* + *c* + *d* = `target`? Find all unique quadruplets in the array which gives the sum of `target`.

**Notice** that the solution set must not contain duplicate quadruplets.

<br/>

**Example 1:**

```
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

**Example 2:**

```
Input: nums = [], target = 0
Output: []
```

<br/>

**Constraints:**

- `0 <= nums.length <= 200`
- `-109 <= nums[i] <= 109`
- `-109 <= target <= 109`

------

### 解决方案

**思路一：双指针**

> 时间复杂度为 O(n^3)，空间复杂度为 O(logn)，其中 n 是数组大小
>

> Runtime: **0 ms**, faster than **100.00%** of C++ online submissions
>
> Memory Usage: **13 MB**, less than **85.41%** of C++ online submissions

```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 4) {
            return ans;
        }
        // 排序
        sort(nums.begin(), nums.end());
        // 遍历 + 双指针
        for (int i = 0; i < n - 3; i++) {
            // 剪枝，由于题目要求四元组不能重复
            // 所以指针 i 直接移动到下一个不相同的数
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 剪枝，此时固定 nums[i] 为四数最小值
            // 如果 nums[i] + 能取的最小值依然大于 target，那么退出循环
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            // 剪枝，此时固定 nums[i] 为四数最小值
            // 如果 nums[i] + 能取的最大值依然小于 target，那么跳过循环
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                // 剪枝，由于题目要求四元组不能重复
                // 所以指针 j 直接移动到下一个不相同的数
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                // 剪枝，此时固定 nums[i], nums[j] 为四数第一第二小
                // 如果 nums[i] + nums[j] + 能取的最小值依然大于 target，那么退出循环
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                // 剪枝，此时固定 nums[i], nums[j] 为四数第一第二小
                // 如果 nums[i] + nums[j] + 能取的最大值依然小于 target，那么跳过循环
                if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) {
                    continue;
                }
                // 将中间值保存下来，避免多次取值
                int numI = nums[i];
                int numJ = nums[j];
                // 指针 p 初始化在数组始端，指针 q 初始化在数组末端
                int p = j + 1;
                int q = n - 1;
                // 双指针向数组中间移动，直至相遇
                while (p < q) {
                    // 将中间值保存下来，避免多次取值
                    int numP = nums[p];
                    int numQ = nums[q];
                    // 计算四数之和
                    int sum = numI + numJ + numP + numQ;
                    if (sum == target) {
                        // 如果四数之和等于零
                        // 那么表示找到一组解，将其加入 ans
                        ans.push_back({numI, numJ, numP, numQ});
                        // 并且指针 p 向右移动，直至遇到第一个不相同的数或到达 n
                        // 同时指针 q 向左移动，直至遇到第一个不相同的数或到达 j
                        while (++p < n && nums[p] == numP);
                        while (--q > j && nums[q] == numQ);
                    } else if (sum < target) {
                        // 如果四数之和小于零
                        // 那么指针 p 向右移动，直至遇到第一个不相同的数或到达 n
                        while (++p < n && nums[p] == numP);
                    } else if (sum > target) {
                        // 如果四数之和大于零
                        // 那么指针 q 向左移动，直至遇到第一个不相同的数或到达 j
                        while (--q > j && nums[q] == numQ);
                    }
                }
            }
        }
        return ans;
    }
};
```


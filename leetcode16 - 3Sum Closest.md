---
title: leetcode16 - 3Sum Closest
date: 2021-03-21 09:00:00
categories: leetcode
tags: [leetcode, 数组, 双指针]
---

> leetcode 16
>
> 原题链接[英]：[3Sum Closest](https://leetcode.com/problems/3sum-closest/)
>
> 原题链接[中]：[最接近的三数之和](https://leetcode-cn.com/problems/3sum-closest/)

<!--more-->

------

### 题目描述

Given an array `nums` of *n* integers and an integer `target`, find three integers in `nums` such that the sum is closest to `target`. Return the sum of the three integers. You may assume that each input would have exactly one solution.

<br/>

**Example 1:**

```
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

<br/>

**Constraints:**

- `3 <= nums.length <= 10^3`
- `-10^3 <= nums[i] <= 10^3`
- `-10^4 <= target <= 10^4`

------

### 解决方案

**思路一：双指针**

> 时间复杂度为 O(n^2)，空间复杂度为 O(logn)，其中 n 是数组大小

> Runtime: **4 ms**, faster than **99.10%** of C++ online submissions
>
> Memory Usage: **9.8 MB**, less than **94.01%** of C++ online submissions

```c++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        // minGap: 表示三数之和与 target 之间的最小差距
        // answer: 表示经计算得到 minGap 对应的三数之和
        int minGap = INT_MAX;
        int answer;
        // 数组排序
        sort(nums.begin(), nums.end());
        // 遍历数组，把指针 i 对应的值固定作为一数，双指针扫描找剩余两数
        for (int i = 0; i < n; i++) {
            // 指针 j 初始化在数组始端，指针 k 初始化在数组末端
            int j = i + 1;
            int k = n - 1;
            // 双指针向数组中间移动，直至相遇
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    // 如果三数之和等于 target，那么直接返回答案
                    return target;
                } else if (sum < target) {
                    // 如果三数之和小于 target，那么计算三数之和与 target 之间的差距
                    int curGap = target - sum;
                    // 若它们的差距小于之前的最小差距，则更新最小差距和答案
                    if (curGap < minGap) {
                        minGap = curGap;
                        answer = sum;
                    }
                    // 同时将指针 j 向右移动，直至遇到第一个不相同的数或到达 n
                    while (++j < n && nums[j] == nums[j - 1]);
                } else if (sum > target) {
                    // 如果三数之和大于 target，那么计算三数之和与 target 之间的差距
                    int curGap = sum - target;
                    // 若它们的差距小于之前的最小差距，则更新最小差距和答案
                    if (curGap < minGap) {
                        minGap = curGap;
                        answer = sum;
                    }
                    // 同时将指针 k 向左移动，直至遇到第一个不相同的数或到达 i
                    while (--k > i && nums[k] == nums[k + 1]);
                }
            }
        }
        return answer;
    }
};
```


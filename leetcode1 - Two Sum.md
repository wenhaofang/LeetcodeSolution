---
title: leetcode1 - Two Sum
date: 2021-03-04 09:00:00
categories: leetcode
tags: [leetcode, 数组, 哈希映射]
---

> leetcode 1
>
> 原题链接[英]：[Two Sum](https://leetcode.com/problems/two-sum/)
>
> 原题链接[中]：[两数之和](https://leetcode-cn.com/problems/two-sum/)

<!--more-->

---

### 题目描述

Given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have **exactly one solution**, and you may not use the *same* element twice.

You can return the answer in any order.

<br/>

**Example 1:**

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
```

**Example 2:**

```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

**Example 3:**

```
Input: nums = [3,3], target = 6
Output: [0,1]
```

<br/>

**Constraints:**

- `2 <= nums.length <= 103`
- `-109 <= nums[i] <= 109`
- `-109 <= target <= 109`
- **Only one valid answer exists.**

---

### 解决方案

**思路一：暴力搜索**

> 时间复杂度为 O(n^2)，空间复杂度为 O(1)，其中 n 为数组大小

> Runtime: **4 ms**, faster than **97.18%** of C++ online submissions
>
> Memory Usage: **8.9 MB**, less than **71.94%** of C++ online submissions

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // 遍历数组元素
        for (int i = 0; i < n; i++) {
            // 对每个元素在数组中找与之相加等于 `target` 的值
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
```

**思路二：先构建哈希，再逐一搜索**

> 时间复杂度为 O(n)，空间复杂度为 O(1)，其中 n 为数组大小

> Runtime: **8 ms**, faster than **74.84%** of C++ online submissions
>
> Memory Usage: **9.9 MB**, less than **15.08%** of C++ online submissions

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hashTable;
        // 先遍历一次数组，构建哈希表，哈希表中的键为元素，值为元素对应的索引
        for (int i = 0; i < n; i++) {
            hashTable.insert(pair<int, int>(nums[i], i));
        }
        // 再遍历一次数组，对每个元素在哈希表找与之相加等于 `target` 的值
        for (int i = 0; i < n; i++) {
            auto j = hashTable.find(target - nums[i]);
            if (j != hashTable.end() && j->second != i) {
                return {i, j->second};
            }
        }
        return {};
    }
};
```

**思路三：构建哈希的同时逐一搜索**

> 时间复杂度为 O(n)，空间复杂度为 O(1)，其中 n 为数组大小

> Runtime: **0 ms**, faster than **100.00%** of C++ online submissions
>
> Memory Usage: **9 MB**, less than **55.03%** of C++ online submissions

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hashTable;
        // 遍历一次数组
        for (int i = 0; i < n; i++) {
            // 对每个元素在哈希表找与之相加等于 `target` 的值
            auto j = hashTable.find(target - nums[i]);
            // 如果可以找到，立即返回结果
            if (j != hashTable.end()) {
                return {j->second, i};
            }
            // 如果没有找到，把该元素的值及其索引添加到哈希表
            hashTable.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};
```


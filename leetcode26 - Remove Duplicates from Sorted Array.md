---
title: leetcode26 - Remove Duplicates from Sorted Array
date: 2021-03-31 09:00:00
categories: leetcode
tags: [leetcode, 数组, 快慢指针]
---

> leetcode 26
>
> 原题链接[英]：[Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
>
> 原题链接[中]：[删除有序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)

<!--more-->

------

### 题目描述

Given a sorted array *nums*, remove the duplicates [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm) such that each element appears only *once* and returns the new length.

Do not allocate extra space for another array, you must do this by **modifying the input array in-place** with O(1) extra memory.

**Clarification:**

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by **reference**, which means a modification to the input array will be known to the caller as well.

Internally you can think of this:

```
// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```

<br/>

**Example 1:**

```
Input: nums = [1,1,2]
Output: 2, nums = [1,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the returned length.
```

**Example 2:**

```
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4]
Explanation: Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively. It doesn't matter what values are set beyond the returned length.
```

<br/>

**Constraints:**

- `0 <= nums.length <= 3 * 104`
- `-104 <= nums[i] <= 104`
- `nums` is sorted in ascending order.

------

### 解决方案

**思路一：快慢指针**

> 时间复杂度为 *O*(n)，空间复杂度为 O(1)，其中 n 为数组大小

> Runtime: **0 ms**, faster than **100.00%** of C++ online submissions
>
> Memory Usage: **13.7 MB**, less than **59.96%** of C++ online submissions

```c++
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
```


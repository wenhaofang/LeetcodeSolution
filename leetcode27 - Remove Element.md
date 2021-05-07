---
title: leetcode27 - Remove Element
date: 2021-04-01 09:00:00
categories: leetcode
tags: [leetcode, 数组, 双指针]
---

> leetcode 27
>
> 原题链接[英]：[Remove Element](https://leetcode.com/problems/remove-element/)
>
> 原题链接[中]：[移除元素](https://leetcode-cn.com/problems/remove-element/)

<!--more-->

------

### 题目描述

Given an array *nums* and a value `val`, remove all instances of that value [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm) and return the new length.

Do not allocate extra space for another array, you must do this by **modifying the input array in-place** with `O(1)` extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

**Clarification:**

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by **reference**, which means a modification to the input array will be known to the caller as well.

Internally you can think of this:

```
// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```

<br/>

**Example 1:**

```
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length. For example if you return 2 with nums = [2,2,3,3] or nums = [2,2,0,0], your answer will be accepted.
```

**Example 2:**

```
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3]
Explanation: Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4. Note that the order of those five elements can be arbitrary. It doesn't matter what values are set beyond the returned length.
```

<br/>

**Constraints:**

- `0 <= nums.length <= 100`
- `0 <= nums[i] <= 50`
- `0 <= val <= 100`

------

### 解决方案

**思路一：双指针**

> 时间复杂度为 *O*(n)，空间复杂度为 O(1)，其中 n 为数组大小

> Runtime: **0 ms**, faster than **100.00%** of C++ online submissions
>
> Memory Usage: **8.8 MB**, less than **16.40%** of C++ online submissions

```c++
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
```


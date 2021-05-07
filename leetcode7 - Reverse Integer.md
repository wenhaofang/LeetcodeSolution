---
title: leetcode7 - Reverse Integer
date: 2021-03-10 09:00:00
categories: leetcode
tags: [leetcode, 数字, 暴力模拟]
---

> leetcode 7
>
> 原题链接[英]：[Reverse Integer](https://leetcode.com/problems/reverse-integer/)
>
> 原题链接[中]：[整数反转](https://leetcode-cn.com/problems/reverse-integer/)

<!--more-->

------

### 题目描述

Given a signed 32-bit integer `x`, return `x` *with its digits reversed*. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2^31, 2^31 - 1]`, then return `0`.

**Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

<br/>

**Example 1:**

```
Input: x = 123
Output: 321
```

**Example 2:**

```
Input: x = -123
Output: -321
```

**Example 3:**

```
Input: x = 120
Output: 21
```

**Example 4:**

```
Input: x = 0
Output: 0
```

<br/>

**Constraints:**

- `-2^31 <= x <= 2^31 - 1`

------

### 解决方案

**思路一：数字反序加入答案，要注意溢出的情况**

> 时间复杂度为 O(log(n))，空间复杂度为 O(1)

> Runtime: **4 ms**, faster than **45.27%** of C++ online submissions
>
> Memory Usage: **5.9 MB**, less than **84.65%** of C++ online submissions

```c++
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            // 如果 x > 0 且 ans * 10 + x % 10 > INT_MAX
            // 即表明 ans * 10 + x % 10 上溢出，直接返回 0
            if (x > 0 && ans > (INT_MAX - x % 10) / 10) return 0;
            // 如果 x < 0 且 ans * 10 + x % 10 < INT_MIN
            // 即表明 ans * 10 + x % 10 下溢出，直接返回 0
            if (x < 0 && ans < (INT_MIN - x % 10) / 10) return 0;
            // 其他情况下，每次取 x 的最后一位加到 ans 中
            ans = ans * 10 + x % 10;
            x = x / 10;
        }
        return ans;
    }
};
```


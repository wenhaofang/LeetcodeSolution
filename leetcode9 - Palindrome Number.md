---
title: leetcode9 - Palindrome Number
date: 2021-03-12 09:00:00
categories: leetcode
tags: [leetcode, 数字, 暴力模拟]
---

> leetcode 9
>
> 原题链接[英]：[Palindrome Number](https://leetcode.com/problems/palindrome-number/)
>
> 原题链接[中]：[回文数](https://leetcode-cn.com/problems/palindrome-number/)

<!--more-->

------

### 题目描述

Given an integer `x`, return `true` if `x` is palindrome integer.

An integer is a **palindrome** when it reads the same backward as forward. For example, `121` is palindrome while `123` is not.

<br/>

**Example 1:**

```
Input: x = 121
Output: true
```

**Example 2:**

```
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

**Example 3:**

```
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

**Example 4:**

```
Input: x = -101
Output: false
```

<br/>

**Constraints:**

- `-2^31 <= x <= 2^31 - 1`

------

### 解决方案

**思路一：反转整个数字后比较**

> 时间复杂度为 O(log(n))，空间复杂度为 O(1)

> Runtime: **8 ms**, faster than **79.15%** of C++ online submissions
>
> Memory Usage: **5.9 MB**, less than **82.80%** of C++ online submissions

```c++
class Solution {
public:
    // 反转一个整数，参考 leetcode7
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            if (x > 0 && ans > (INT_MAX - x % 10) / 10) return 0;
            if (x < 0 && ans < (INT_MIN - x % 10) / 10) return 0;
            ans = ans * 10 + x % 10;
            x = x / 10;
        }
        return ans;
    }

    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        return x == reverse(x);
    }
};
```

**思路二：反转一半数字后比较**

> 时间复杂度为 O(log(n))，空间复杂度为 O(1)

> Runtime: **4 ms**, faster than **94.60%** of C++ online submissions
>
> Memory Usage: **5.8 MB**, less than **93.48%** of C++ online submissions

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        // 前处理，特殊情况
        // 如果 x 小于 0，那么它必不可能是回文数
        // 如果 x 最后一位为 0 且其本身不是 0，那么它也不可能是回文数
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        // x 用于储存原数的前半部分数字，y 用于储存原数的后半部分数字
        // 每次去掉 x 的最后一位，并将该数字加入 y，直至 x <= y
        // 此时数字 x 的位数等于数字 y 的位数或等于数字 y 的位数加 1
        int y = 0;
        while (x > y) {
            y = y * 10 + x % 10;
            x = x / 10;
        }
        // 一个数字是回文数分为两种情况:
        // 1. 以一个字符为回文中心，例如原数 x = 121， 那么处理后的 x = 1,  y = 12，此时 x == y / 10
        // 2. 以两个字符为回文中心，例如原数 x = 1221，那么处理后的 x = 12, y = 12，此时 x == y
        return (x == y || x == y / 10);
    }
};
```


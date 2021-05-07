---
title: leetcode13 - Roman to Integer
date: 2021-03-18 09:00:00
categories: leetcode
tags: [leetcode, 字符串, 找规律]
---

> leetcode 13
>
> 原题链接[英]：[Roman to Integer](https://leetcode.com/problems/roman-to-integer/)
>
> 原题链接[中]：[罗马数字转整数](https://leetcode-cn.com/problems/roman-to-integer/)

<!--more-->

------

### 题目描述

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, `2` is written as `II` in Roman numeral, just two one's added together. `12` is written as `XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

- `I` can be placed before `V` (5) and `X` (10) to make 4 and 9. 
- `X` can be placed before `L` (50) and `C` (100) to make 40 and 90. 
- `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

<br/>

**Example 1:**

```
Input: s = "III"
Output: 3
```

**Example 2:**

```
Input: s = "IV"
Output: 4
```

**Example 3:**

```
Input: s = "IX"
Output: 9
```

**Example 4:**

```
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
```

**Example 5:**

```
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

<br/>

**Constraints:**

- `1 <= s.length <= 15`
- `s` contains only the characters `('I', 'V', 'X', 'L', 'C', 'D', 'M')`.
- It is **guaranteed** that `s` is a valid roman numeral in the range `[1, 3999]`.

------

### 解决方案

**思路一：找规律**

> 时间复杂度为 O(1)，空间复杂度为 O(1)

> Runtime: **0 ms**, faster than **100.00%** of C++ online submissions
>
> Memory Usage: **5.9 MB**, less than **95.89%** of C++ online submissions

```c++
class Solution {
public:
    /**
     * 如果不存在 4、9、40、90、400、900 等特殊情况，
     * 直接顺序获取字符对应的数字，将它们相加即可得到答案，例如:
     *     LVIII -> 50 + 5 + 1 + 1 + 1 = 58
     * 
     * 而如果存在 4、9、40、90、400、900 等特殊情况，
     * 不难发现一个规律，即如果小值在大值左边，则小值变成负数相加即是期望值，例如
     *     IV -> (-1) + 5 = 4
     *     IX -> (-1) + 10 = 9
     *     XL -> (-10) + 50 = 40
     *     XC -> (-10) + 100 = 90
     *     CD -> (-100) + 500 = 400
     *     CM -> (-100) + 1000 = 900
     */
    int romanToInt(string s) {
        int size = s.length();
        int ans = 0; // 符号
        int pos = 1; // 数字
        for (int i = 0; i < size; i++) {
            int curr = getValue(s[i]);
            int next = getValue(s[i + 1]);
            pos = curr >= next ? 1 : -1;
            ans = ans + pos * curr;
        }
        return ans;
    }

    /**
     * 获取符号对应的值
     */
    int getValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default : return 0;
        }
    }
};
```


---
title: leetcode12 - Integer to Roman
date: 2021-03-17 09:00:00
categories: leetcode
tags: [leetcode, 数字, 硬编码, 贪心算法]
---

> leetcode 12
>
> 原题链接[英]：[Integer to Roman](https://leetcode.com/problems/integer-to-roman/)
>
> 原题链接[中]：[整数转罗马数字](https://leetcode-cn.com/problems/integer-to-roman/)

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

Given an integer, convert it to a roman numeral.

<br/>

**Example 1:**

```
Input: num = 3
Output: "III"
```

**Example 2:**

```
Input: num = 4
Output: "IV"
```

**Example 3:**

```
Input: num = 9
Output: "IX"
```

**Example 4:**

```
Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
```

**Example 5:**

```
Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

<br/>

**Constraints:**

- `1 <= num <= 3999`

------

### 解决方案

**思路一：硬编码**

> 时间复杂度为 O(1)，空间复杂度为 O(1)

> Runtime: **8 ms**, faster than **65.67%** of C++ online submissions
>
> Memory Usage: **5.8 MB**, less than **97.91%** of C++ online submissions

```c++
class Solution {
public:
    /**
     * 将个、十、百、千位所有符号罗列出来
     * 然后将数字拆成个、十、百、千位分别对应上述符号
     */
    string intToRoman(int num) {
        string ones[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hundreds[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thousands[4] = {"", "M", "MM", "MMM"};
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
    }
};
```

**思路二：贪心算法**

> 时间复杂度为 O(1)，空间复杂度为 O(1)

> Runtime: **0 ms**, faster than **100.00%** of C++ online submissions
>
> Memory Usage: **6 MB**, less than **79.99%** of C++ online submissions

```c++
class Solution {
public:
    /**
     * 将所有的特殊符号罗列出来
     * 每次取最大的符号，然后用数字减去符号对应的值，得到的余数重复上述步骤
     */
    string intToRoman(int num) {
        int digits[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbol[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int cur = 0;
        string ans;
        while (num != 0) {
            if (num >= digits[cur]) {
                num -= digits[cur];
                ans += symbol[cur];
            } else {
                cur += 1;
            }
        }
        return ans;
    }
};
```


---
title: leetcode17 - Letter Combinations of a Phone Number
date: 2021-03-22 09:00:00
categories: leetcode
tags: [leetcode, 字符串, 回溯]
---

> leetcode 17
>
> 原题链接[英]：[Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
>
> 原题链接[中]：[电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)

<!--more-->

------

### 题目描述

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

<img src="leetcode17 - Letter Combinations of a Phone Number/01.png" alt="图示">

<br/>

**Example 1:**

```
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**Example 2:**

```
Input: digits = ""
Output: []
```

**Example 3:**

```
Input: digits = "2"
Output: ["a","b","c"]
```

<br/>

**Constraints:**

- `0 <= digits.length <= 4`
- `digits[i]` is a digit in the range `['2', '9']`.

------

### 解决方案

**思路一：回溯**

> 时间复杂度为 O(3^m + 4^n)，空间复杂度为 O(m + n)
>
> 其中 m 为输入数字中对应 3 个字母的数字的个数，n 为输入数字中对应 4 个字母的数字的个数

> Runtime: **0 ms**, faster than **100.00%** of C++ online submissions
>
> Memory Usage: **6.7 MB**, less than **63.72%** of C++ online submissions

```c++
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) {
            return ans;
        }
        unordered_map<char, string> map {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string combination;
        backtrace(ans, map, digits, 0, combination);
        return ans;
    }

    /**
     * 回溯算法的核心是遍历剪枝，一般用于搜索所有的可行解
     * 在这道题目中，我们要维护一个字符串，表示已处理数字对应的字母排列
     * 该字符串初始化为空，然后每次取出一位数字，将该数字对应的一个字母加入字符串
     * 直至所有数字被取出，至此我们能得到一个可能的排列，将其记录下来加入答案列表
     * 之后进行回退操作，遍历其余的字符排列
     */
    /**
     * 以输入数字 "23" 为例，整个回溯的过程如下：
     * ""(初始) -> "a"(深入) -> "ad"(深入) -> "a"(回退) -> "ae"(深入) -> "a"(回退) -> "af"(深入) -> "a"(回退) ->
     * ""(回退) -> "b"(深入) -> "bd"(深入) -> "b"(回退) -> "be"(深入) -> "b"(回退) -> "bf"(深入) -> "b"(回退) ->
     * ""(回退) -> "c"(深入) -> "cd"(深入) -> "c"(回退) -> "ce"(深入) -> "c"(回退) -> "cf"(深入) -> "c"(回退) ->
     * ""(回退)
     */
    void backtrace(
        vector<string>& ans,  // 答案列表
        const unordered_map<char, string>& map,
        const string& digits, // 输入的数字
        int index,            // 当前处理的数字
        string& combination   // 可能的字母排列
    ) {
        if (index == digits.size()) {
            // 当前处理的数字已经是最后一位
            // 意味着已经得到一个可能的排列，将当前排列加入答案列表
            ans.push_back(combination);
        } else {
            // 在其余情况下
            // 每次取出一位数字，将该数字对应的一个字母加入字符串
            char digit = digits[index];
            string letters = map.at(digit);
            for (const char& letter: letters) {
                // 深入
                combination.push_back(letter);
                // 递归调用
                backtrace(ans, map, digits, index + 1, combination);
                // 回退
                combination.pop_back();
            }
        }
    }
};
```


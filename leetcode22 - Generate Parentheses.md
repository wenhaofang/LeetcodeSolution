---
title: leetcode22 - Generate Parentheses
date: 2021-03-27 09:00:00
categories: leetcode
tags: [leetcode, 字符串, 回溯]
---

> leetcode 22
>
> 原题链接[英]：[Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)
>
> 原题链接[中]：[括号生成](https://leetcode-cn.com/problems/generate-parentheses/)

<!--more-->

------

### 题目描述

ven `n` pairs of parentheses, write a function to *generate all combinations of well-formed parentheses*.

<br/>

**Example 1:**

```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```

**Example 2:**

```
Input: n = 1
Output: ["()"]
```

<br/>

**Constraints:**

- `1 <= n <= 8`

------

### 解决方案

**思路一：回溯**

> 时间复杂度为 O(4^n / √n)，空间复杂度为 O(n)，其中 n 为括号对数

> Runtime: **0 ms**, faster than **100.00%** of C++ online submissions
>
> Memory Usage: **11.3 MB**, less than **83.80%** of C++ online submissions

```c++
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string combination;
        backtrace(ans, combination, n, n, n * 2);
        return ans;
    }

    /**
     * 回溯算法，遍历剪枝
     * 在这道题目中，我们要维护一个字符串，表示当前排列
     * 该字符串初始化为空，然后每次取一个（符合条件的）括号加入到该字符串
     * 直至所有括号被用完，至此我们能得到一个可能的排列，将其加入答案数组
     * 之后进行回退操作，遍历其余可能排列
     */
    void backtrace(
        vector<string>& ans, // 答案数组
        string& combination, // 当前排列
        int lNum, // 左括号剩余个数
        int rNum, // 右括号剩余个数
        int num // 总括号数
    ) {
        if (combination.size() == num) {
            // 当前排列已经用完所有括号
            // 意味着已经得到一个可行解，将其加入答案列表
            ans.push_back(combination);
        } else {
            // 在其余情况下，放入一个括号
            // 剪枝：只有剩余左括号数大于零，才能继续放左括号
            if (lNum > 0) {
                // 深入
                combination.push_back('(');
                // 递归
                backtrace(ans, combination, lNum - 1, rNum, num);
                // 回退
                combination.pop_back();
            }
            // 剪枝：只有剩余左括号数小于剩余右括号数，才能继续放右括号
            if (lNum < rNum) {
                // 深入
                combination.push_back(')');
                // 递归
                backtrace(ans, combination, lNum, rNum - 1, num);
                // 回退
                combination.pop_back();
            }
        }
    }
};
```


---
title: leetcode20 - Valid Parentheses
date: 2021-03-25 09:00:00
categories: leetcode
tags: [leetcode, 字符串, 栈]
---

> leetcode 20
>
> 原题链接[英]：[Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)
>
> 原题链接[中]：[有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)

<!--more-->

------

### 题目描述

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

<br/>

**Example 1:**

```
Input: s = "()"
Output: true
```

**Example 2:**

```
Input: s = "()[]{}"
Output: true
```

**Example 3:**

```
Input: s = "(]"
Output: false
```

**Example 4:**

```
Input: s = "([)]"
Output: false
```

**Example 5:**

```
Input: s = "{[]}"
Output: true
```

<br/>

**Constraints:**

- `1 <= s.length <= 104`
- `s` consists of parentheses only `'()[]{}'`.

------

### 解决方案

**思路一：栈**

> 时间复杂度为 O(n)，空间复杂度为 O(n)，其中 n 为字符串长度

> Runtime: **0 ms**, faster than **100.00%** of C++ online submissions
>
> Memory Usage: **6.4 MB**, less than **6.23%** of C++ online submissions

```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> map = {
            {')', '('}, {']', '['}, {'}', '{'}
        };
        // 遍历字符串
        for (char c: s) {
            // 如果当前字符是左括号
            if (c == '(' || c == '[' || c == '{') {
                // 那么将其加入栈中
                stk.push(c);
            }
            // 如果当前字符是右括号
            if (c == ')' || c == ']' || c == '}') {
                if (!stk.empty() && stk.top() == map[c]) {
                    // 如果栈不为空，并且栈顶字符与当前字符能匹配，那么将其消去
                    stk.pop();
                } else {
                    // 其余情况下，均不能匹配，直接返回 false
                    return false;
                }
            }
        }
        // 最后，如果栈为空，表示可以全部匹配，返回 true
        // 反之，若栈不为空，表示不能全部匹配，返回 false
        return stk.empty();
    }
};
```


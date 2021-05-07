---
title: leetcode14 - Longest Common Prefix
date: 2021-03-19 09:00:00
categories: leetcode
tags: [leetcode, 字符串, 暴力模拟]
---

> leetcode 14
>
> 原题链接[英]：[Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)
>
> 原题链接[中]：[最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/)

<!--more-->

------

### 题目描述

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

<br/>

**Example 1:**

```
Input: strs = ["flower","flow","flight"]
Output: "fl"
```

**Example 2:**

```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```

<br/>

**Constraints:**

- `0 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- `strs[i]` consists of only lower-case English letters.

------

### 解决方案

**思路一：暴力模拟，纵向比较**

> 时间复杂度为 O(mn)，空间复杂度为 O(1)，其中 m 是字符串的数量，n 是字符串的平均长度

> Runtime: **0 ms**, faster than **100.00%** of C++ online submissions
>
> Memory Usage: **9 MB**, less than **92.57%** of C++ online submissions

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 前处理，特殊情况
        // 若字符串数组为空，那么没有最长公共前缀
        int strSize = strs.size();
        if (strSize == 0) {
            return "";
        }
        // 计算字符串数组中最长字符串的长度
        // 这也是最长公共前缀的最长长度
        int maxSize = 201;
        for (int j = 0; j < strSize; j++) {
            if (maxSize > strs[j].size()) {
                maxSize = strs[j].size();
            }
        }
        // 顺序比较字符串数组中同一索引的字符
        // 其中 i 表示字符索引，j 表示字符串索引
        string ans;
        for (int i = 0; i < maxSize; i++) {
            char c = strs[0][i];
            for (int j = 0; j < strSize; j++) {
                if (strs[j][i] != c) {
                    return ans;
                }
            }
            ans += c;
        }
        return ans;
    }
};
```


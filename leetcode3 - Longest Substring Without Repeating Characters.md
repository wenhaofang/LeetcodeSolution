---
title: leetcode3 - Longest Substring Without Repeating Characters
date: 2021-03-06 09:00:00
categories: leetcode
tags: [leetcode, 字符串, 滑动窗口, 哈希集合, 哈希映射]
---

> leetcode 3
>
> 原题链接[英]：[Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
>
> 原题链接[中]：[无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

<!--more-->

------

### 题目描述

Given a string `s`, find the length of the **longest substring** without repeating characters.

<br/>

**Example 1:**

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

**Example 2:**

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

**Example 3:**

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
```

**Example 4:**

```
Input: s = ""
Output: 0
```

<br/>

**Constraints:**

- `0 <= s.length <= 5 * 104`
- `s` consists of English letters, digits, symbols and spaces.

------

### 解决方案

**思路一：滑动窗口 + 哈希集合**

> 时间复杂度为 O(n)，空间复杂度为 O(min(m, n))，其中 n 是字符串长度，m 是词典大小

> Runtime: **12 ms**, faster than **77.31%** of C++ online submissions
>
> Memory Usage: **8.9 MB**, less than **38.40%** of C++ online submissions

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int num = s.size();
        // 字符集合，用于维护左右指针间的字符
        unordered_set<char> hashSet;
        // ans: 当前无重复字符的最长子串长度
        // lp : 滑动窗口的左指针
        // rp : 滑动窗口的右指针
        int ans = 0, lp = -1, rp = -1;
        // 右指针每次向右移动一个字符，直至到达字符串末尾
        while (++rp < num) {
            // 判断右指针指向的字符是否在集合中
            if (!hashSet.count(s[rp])) {
                // 若字符不在集合中，则把该字符加入集合
                hashSet.insert(s[rp]);
            } else {
                // 如果字符在集合中，左指针向右移动直至到达相同字符
                // 同时，把从左指针开始移动位置到左指针结束移动位置间的字符从集合中删除
                while (s[++lp] != s[rp]) {
                    hashSet.erase(s[lp]);
                }
            }
            // 计算当前无重复字符的最长子串长度
            ans = max(ans, int(hashSet.size()));
        }
        return ans;
    }
};
```

**思路二：滑动窗口 + 哈希映射**

> 时间复杂度为 O(n)，空间复杂度为 O(min(m, n))，其中 n 是字符串长度，m 是词典大小

> Runtime: **8 ms**, faster than **89.09%** of C++ online submissions
>
> Memory Usage: **8.3 MB**, less than **67.70%** of C++ online submissions

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int num = s.size();
        // 字符映射，用于维护右指针扫过的字符及其最后一次出现的位置
        unordered_map<char, int> hashMap;
        // ans: 当前无重复字符的最长子串长度
        // lp : 滑动窗口的左指针
        // rp : 滑动窗口的右指针
        int ans = 0, lp = 0, rp = -1;
        // 右指针每次向右移动一个字符，直至到达字符串末尾
        while (++rp < num) {
            // 判断右指针指向的字符是否在映射中
            auto res = hashMap.find(s[rp]);
            // 如果字符在映射中且其最后一次出现的位置不在左指针指向位置的左边
            // 那么直接将左指针移到该字符最后一次出现位置的右边一位
            if (res != hashMap.end() && res->second >= lp) {
                lp = res->second + 1;
            }
            // 更新字符映射
            hashMap[s[rp]] = rp;
            // 计算当前无重复字符的最长子串长度
            ans = max(ans, rp - lp + 1);
        }
        return ans;
    }
};
```


---
title: leetcode21 - Merge Two Sorted Lists
date: 2021-03-26 09:00:00
categories: leetcode
tags: [leetcode, 链表, 归并]
---

> leetcode 21
>
> 原题链接[英]：[Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
>
> 原题链接[中]：[合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

<!--more-->

------

### 题目描述

Merge two sorted linked lists and return it as a **sorted** list. The list should be made by splicing together the nodes of the first two lists.

<br/>

**Example 1:**

```
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
```

**Example 2:**

```
Input: l1 = [], l2 = []
Output: []
```

**Example 3:**

```
Input: l1 = [], l2 = [0]
Output: [0]
```

<br/>

**Constraints:**

- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `l1` and `l2` are sorted in **non-decreasing** order.

------

### 解决方案

**思路一：归并**

> 时间复杂度为 O(m + n)，空间复杂度为 O(m + n)，其中 m、n 分别为两个链表的长度

> Runtime: **0 ms**, faster than **100.00%** of C++ online submissions
>
> Memory Usage: **14.8 MB**, less than **28.00%** of C++ online submissions

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // head: 结果链表的头指针，用于返回答案
        ListNode* head = new ListNode(0);
        // curr: 结果链表当前指针，用于添加节点
        ListNode* curr = head;
        // 每次将值较小的节点添加到结果链表
        // 同时将该链表指针和结果链表指针各前移一位
        while (l1 != nullptr && l2 != nullptr) {
            if (l1 -> val < l2 -> val) {
                curr -> next = l1;
                l1 = l1 -> next;
                curr = curr -> next;
            } else {
                curr -> next = l2;
                l2 = l2 -> next;
                curr = curr -> next;
            }
        }
        // 此时，两链表指针必定有一个已到达链表末尾
        // 最后只需将另一链表余下节点添加至结果链表即可
        curr -> next = (l1 == nullptr) ? l2 : l1;
        // 返回答案
        return head -> next;
    }
};
```


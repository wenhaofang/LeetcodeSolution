---
title: leetcode2 - Add Two Numbers
date: 2021-03-05 09:00:00
categories: leetcode
tags: [leetcode, 链表, 双指针]
---

> leetcode 2
>
> 原题链接[英]：[Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)
>
> 原题链接[中]：[两数相加](https://leetcode-cn.com/problems/add-two-numbers/)

<!--more-->

------

### 题目描述

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

<br/>

**Example 1:**

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
```

**Example 2:**

```
Input: l1 = [0], l2 = [0]
Output: [0]
```

**Example 3:**

```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

 <br/>

**Constraints:**

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.

---

### 解决方案

**思路一：按照加法原理逐位对应相加**

> 时间复杂度为 O(max(m, n))，空间复杂度为 O(max(m, n))，其中 m、n 分别为两个链表的大小

> Runtime: **16 ms**, faster than **98.72%** of C++ online submissions
>
> Memory Usage: **71.1 MB**, less than **87.78%** of C++ online submissions

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // sum:   两数相加得到的结果
        // carry: 两数相加得到的进位
        int sum = 0;
        int carry = 0;
        // head: 结果链表头指针，指向结果链表的第一个元素，用于结果返回
        // tail: 结果链表尾指针，指向结果链表的最后一个元素，用于添加元素
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        // 如果原链表指针都未到达末端
        while (l1 || l2) {
            // 获取原链表指针指向的值，并计算两数相加得到的结果和进位
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            sum = x + y + carry;
            carry = sum / 10;
            // 将计算结果取模后添加到结果链表
            // 这里分为两种情况，第一次添加到链表以及其它
            if (!head) {
                head = new ListNode(sum % 10);
                tail = head;
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            // 如果原链表指针尚未到达末尾，则向右移动一格
            // 如果原链表指针已经到达末尾，则保持不动
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        // 后处理
        // 若最后一次相加也有进位，则把进位添加到结果链表
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
```


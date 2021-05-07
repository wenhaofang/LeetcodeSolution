---
title: leetcode25 - Reverse Nodes in k-Group
date: 2021-03-30 09:00:00
categories: leetcode
tags: [leetcode, 链表, 递归, 迭代]
---

> leetcode 25
>
> 原题链接[英]：[Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)
>
> 原题链接[中]：[K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)

<!--more-->

------

### 题目描述

Given a linked list, reverse the nodes of a linked list *k* at a time and return its modified list.

*k* is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of *k* then left-out nodes, in the end, should remain as it is.

**Follow up:**

- Could you solve the problem in `O(1)` extra memory space?
- You may not alter the values in the list's nodes, only nodes itself may be changed.

<br/>

**Example 1:**

```
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
```

**Example 2:**

```
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
```

**Example 3:**

```
Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
```

**Example 4:**

```
Input: head = [1], k = 1
Output: [1]
```

<br/>

**Constraints:**

- The number of nodes in the list is in the range `sz`.
- `1 <= sz <= 5000`
- `0 <= Node.val <= 1000`
- `1 <= k <= sz`

------

### 解决方案

**思路一：递归**

> 时间复杂度为 *O*(n)，空间复杂度为 O(1)，其中 n 为链表长度

> Runtime: **12 ms**, faster than **89.71%** of C++ online submissions
>
> Memory Usage: **11.5 MB,** less than **20.46%** of C++ online submissions

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
    /**
     * 该函数可以翻转一个具有 k 个（小于 k 个）节点的链表
     * 其接收翻转前的头指针和尾指针，返回翻转后的头指针和尾指针
     */
    pair<ListNode*, ListNode*> reverseNode(ListNode* head, ListNode* tail) {
        ListNode* prev = head;
        ListNode* curr = head -> next;
        while (prev != tail) {
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return { tail, head };
    }

    /**
     * 递归的核心在于将原问题规约成子问题
     * 在这个过程中有三个要点：传入的参数、处理的过程、返回的结果
     * 规约子问题：翻转一个具有 k 个（小于 k 个）节点的链表
     * 传入的参数：链表翻转前的头指针
     * 处理的过程：接收翻转前的头指针，翻转所有节点，返回翻转后的头指针
     * 返回的结果：链表翻转后的头指针
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 特判
        if (head == nullptr || k == 1) {
            return head;
        }
        // prev: 当前处理链表的头指针，初始化为 head
        // curr: 当前处理链表的尾指针，初始化为 head
        int n = 1;
        ListNode* prev = head;
        ListNode* curr = head;
        // 将当前处理链表的尾指针移动到 k 个节点后
        // 如果不足 k 个节点，则移动到链表末尾停止
        while (n < k && curr -> next) {
            n = n + 1;
            curr = curr -> next;
        }
        if (n < k) {
            // 如果尾指针移动到链表末尾（不足 k 个节点）
            // 此时不用翻转当前链表，直接返回 head 即可
            return head;
        } else {
            // 如果尾指针移动到 k 个元素后，那么翻转当前链表
            ListNode* next = curr -> next;
            pair<ListNode*, ListNode*> result = reverseNode(prev, curr);
            // 返回翻转后的头指针 newHead 和尾指针 newTail
            ListNode* newHead = result.first;
            ListNode* newTail = result.second;
            // 并将当前处理链表翻转后的尾指针指向下一个要处理链表翻转后的头指针
            newTail -> next = reverseKGroup(next, k);
            // 返回当前处理链表翻转后的头指针
            return newHead;
        }
    }
};
```

**思路二：迭代**

> 时间复杂度为 *O*(n)，空间复杂度为 O(1)，其中 n 为链表长度

> Runtime: **16 ms**, faster than **55.13%** of C++ online submissions
>
> Memory Usage: **11.6 MB**, less than **20.51%** of C++ online submissions

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
    /**
     * 该函数可以翻转一个具有 k 个（小于 k 个）节点的链表
     * 其接收翻转前的头指针和尾指针，返回翻转后的头指针和尾指针
     */
    pair<ListNode*, ListNode*> reverseNode(ListNode* head, ListNode* tail) {
        ListNode* prev = head;
        ListNode* curr = head -> next;
        while (prev != tail) {
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return { tail, head };
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // 添加哑节点
        ListNode* dummy = new ListNode(0, head);
        // curr: 上一处理链表的尾指针，初始化指向哑节点
        // tail: 当前处理链表的尾指针，初始化指向哑节点
        ListNode* curr = dummy;
        ListNode* tail = dummy;
        // 进入循环
        while (true) {
            // tail 移动到 k 个节点后
            // 如果不足 k 个节点，则移动到链表末尾停止
            int n = 0;
            while (n < k && tail -> next) {
                n = n + 1;
                tail = tail -> next;
            }
            if (n < k) {
                // 如果 tail 移动到链表末尾（不足 k 个节点）
                // 此时已经到达最后，直接退出循环
                break;
            } else {
                // 如果 tail 移动到 k 个节点后，那么翻转 curr 后的 k 个节点
                ListNode* next = tail -> next;
                pair<ListNode*, ListNode*> result = reverseNode(curr -> next, tail);
                // 返回翻转后的头指针 newHead 和尾指针 newTail
                ListNode* newHead = result.first;
                ListNode* newTail = result.second;
                // curr(上一处理链表的尾指针，已翻转) 指向 newHead(当前处理链表的头指针)
                // newTail(当前处理链表的尾指针) 指向 next(下一处理链表的头指针，未翻转)
                curr -> next = newHead;
                newTail -> next = next;
                // 令 curr 等于 newTail，令 tail 等于 newTail
                // 重复以上步骤，直至到达链表末尾
                curr = newTail;
                tail = newTail;
            }
        }
        // 返回答案
        return dummy -> next;
    }
};
```


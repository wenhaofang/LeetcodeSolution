---
title: leetcode19 - Remove Nth Node From End of List
date: 2021-03-24 09:00:00
categories: leetcode
tags: [leetcode, 链表, 栈, 快慢指针]
---

> leetcode 19
>
> 原题链接[英]：[Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
>
> 原题链接[中]：[删除链表的倒数第 N 个结点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

<!--more-->

------

### 题目描述

Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.

**Follow up:** Could you do this in one pass?

<br/>

**Example 1:**

```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

**Example 2:**

```
Input: head = [1], n = 1
Output: []
```

**Example 3:**

```
Input: head = [1,2], n = 1
Output: [1]
```

<br/>

**Constraints:**

- The number of nodes in the list is `sz`.
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`

------

### 解决方案

**思路一：栈**

> 时间复杂度为 O(n)，空间复杂度为 O(n)，其中 n 为链表长度

> Runtime: **4 ms**, faster than **80.13%** of C++ online submissions
>
> Memory Usage: **10.8 MB**, less than **13.04%** of C++ online submissions

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 定义节点栈
        stack<ListNode*> stk;
        // 增加哑节点，避免对头节点做特殊判断
        ListNode* dummy = new ListNode(0, head);
        // 所有节点入栈
        ListNode* curr = dummy;
        while (curr) {
            stk.push(curr);
            curr = curr -> next;
        }
        // 倒数 n 个节点出栈
        while (n--) {
            stk.pop();
        }
        // 当前栈顶节点即为待删除节点的前一个节点
        ListNode* prev = stk.top();
        prev -> next = prev -> next -> next;
        // 保存头节点作为结果返回，并删除哑节点
        ListNode* ans = dummy -> next;
        delete dummy;
        return ans;
    }
};
```

**思路二：快慢指针**

> 时间复杂度为 O(n)，空间复杂度为 O(1)，其中 n 为链表长度

> Runtime: **0 ms**, faster than **100.00%** of C++ online submissions
>
> Memory Usage: **10.8 MB**, less than **13.04%** of C++ online submissions

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 增加哑节点，避免对头节点做特殊判断
        ListNode* dummy = new ListNode(0, head);
        // 定义快、慢指针，同时初始化在哑节点
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        // 快指针首先移动 n 位
        for (int i = 0; i < n; i++) {
            fast = fast -> next;
        }
        // 快、慢指针同时移动，直至快指针到达链表末尾
        while (fast -> next) {
            fast = fast -> next;
            slow = slow -> next;
        }
        // 此时慢指针指向即为待删除节点的前一个节点
        slow -> next = slow -> next -> next;
        // 保存头节点作为结果返回，并删除哑节点
        ListNode* ans = dummy -> next;
        delete dummy;
        return ans;
    }
};
```


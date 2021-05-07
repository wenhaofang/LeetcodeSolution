---
title: leetcode23 - Merge k Sorted Lists
date: 2021-03-28 09:00:00
categories: leetcode
tags: [leetcode, 链表, 归并, 优先队列, 分治]
---

> leetcode 23
>
> 原题链接[英]：[Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)
>
> 原题链接[中]：[合并K个升序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)

<!--more-->

------

### 题目描述

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

*Merge all the linked-lists into one sorted linked-list and return it.*

<br/>

**Example 1:**

```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```

**Example 2:**

```
Input: lists = []
Output: []
```

**Example 3:**

```
Input: lists = [[]]
Output: []
```

<br/>

**Constraints:**

- `k == lists.length`
- `0 <= k <= 10^4`
- `0 <= lists[i].length <= 500`
- `-10^4 <= lists[i][j] <= 10^4`
- `lists[i]` is sorted in **ascending order**.
- The sum of `lists[i].length` won't exceed `10^4`.

------

### 解决方案

**思路一：多路归并 + 优先队列**

> 时间复杂度为 *O*(kn × logk)，空间复杂度为 O(k)，其中 k 为链表数量，n 为链表中元素的个数

> Runtime: **24 ms**, faster than **60.89%** of C++ online submissions
>
> Memory Usage: **13.5 MB**, less than **42.10%** of C++ online submissions

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
    // 优先队列默认实现为大顶堆
    // 自定义结构体重载比较函数，将其改为小顶堆
    struct Status {
        int val;
        ListNode* ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    /**
     * 初始化多个指针，每个指针分别指向各链表的第一个节点
     * 每次将值最小的节点加入结果链表（优先队列实现）
     * 然后当前链表的指针前移一位，直至所有指针都到达各个链表的结尾
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // head: 头部指针，用于返回结果
        // curr: 当前指针，用于添加节点
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        // 优先队列，小顶堆实现，队首元素是最小元素
        priority_queue<Status> q;
        // 将所有链表的第一个节点添加到优先队列
        for (auto first: lists) {
            if (first) {
                q.push({first -> val, first});
            }
        }
        // 每次从优先队列中取出最小节点，将其加入结果链表
        // 然后从最小节点所在链表取下一个节点加入优先队列
        // 直至优先队列为空
        while (!q.empty()) {
            auto top = q.top(); q.pop();
            curr -> next = top.ptr;
            curr = curr -> next;
            if (top.ptr -> next) {
                q.push({top.ptr -> next -> val, top.ptr -> next});
            }
        }
        // 返回结果
        return head -> next;
    }
};
```

**思路二：双路归并 + 分治**

> 时间复杂度为 *O*(kn × logk)，空间复杂度为 O(logk)，其中 k 为链表数量，n 为链表中元素的个数

> Runtime: **16 ms**, faster than **97.27%** of C++ online submissions
>
> Memory Usage: **22.7 MB**, less than **5.03%** of C++ online submissions

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
    // 合并两个有序数组，具体请参考 leetcode21
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
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
        curr -> next = (l1 == nullptr) ? l2 : l1;
        return head -> next;
    }

    // 分治
    ListNode* merge(vector<ListNode*> &lists, int l, int r) {
        // 终止条件
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        // 分而治之
        int mid = (l + r) / 2;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};
```


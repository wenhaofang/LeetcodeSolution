/*************************************************
Author: wenhaofang
Date: 2023-03-12
Description: leetcode148 - Sort List
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：归并排序
 * 
 * 理论时间复杂度：O(nlogn)，其中 n 为链表长度
 * 理论空间复杂度：O( logn)，其中 n 为链表长度
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        return merge(head);
    }

    ListNode* merge (ListNode* head) {
        // 边界情况
        if (head -> next == nullptr) {
            return head;
        }
        // 环的中点
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast -> next != nullptr && fast -> next -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* temp = slow -> next;
        slow -> next = nullptr;
        // 排序
        ListNode* sortedLi1 = merge(head);
        ListNode* sortedLi2 = merge(temp);
        // 归并
        ListNode* dummyHead = new ListNode(0);
        ListNode* dummyTail = dummyHead;
        while (sortedLi1 != nullptr && sortedLi2 != nullptr) {
            if (sortedLi1 -> val < sortedLi2 -> val) {
                dummyTail -> next = sortedLi1;
                dummyTail = dummyTail -> next;
                sortedLi1 = sortedLi1 -> next;
            } else {
                dummyTail -> next = sortedLi2;
                dummyTail = dummyTail -> next;
                sortedLi2 = sortedLi2 -> next;
            }
        }
        // while (sortedLi1 != nullptr) {
        //     dummyTail -> next = sortedLi1;
        //     dummyTail = dummyTail -> next;
        //     sortedLi1 = sortedLi1 -> next;
        // }
        // while (sortedLi2 != nullptr) {
        //     dummyTail -> next = sortedLi2;
        //     dummyTail = dummyTail -> next;
        //     sortedLi2 = sortedLi2 -> next;
        // }
        if (sortedLi1 != nullptr) {
            dummyTail -> next = sortedLi1;
        }
        if (sortedLi2 != nullptr) {
            dummyTail -> next = sortedLi2;
        }
        return dummyHead -> next;
    }
};

/**
 * 方法二：转成数组
 * 
 * 理论时间复杂度：O(nlogn)，其中 n 为链表长度
 * 理论空间复杂度：O( logn)，其中 n 为链表长度
 */
/**
 * 思路：
 * 
 * 先将链表转数组，调用库函数 sort 解决
 */

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    ListNode* n4 = new ListNode(3);
    ListNode* n3 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n1 = new ListNode(4);
    n4 -> next = nullptr;
    n3 -> next = n4;
    n2 -> next = n3;
    n1 -> next = n2;
    ListNode* ans = solution -> sortList(n1);
    while (ans != nullptr) {
        cout << ans -> val << endl;
        ans = ans -> next;
    }
}
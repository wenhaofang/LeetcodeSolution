/*************************************************
Author: wenhaofang
Date: 2023-03-23
Description: leetcode206 - Reverse Linked List
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：迭代 (画图)
 * 
 * 理论时间复杂度：O(n)，其中 n 为链表长度
 * 理论空间复杂度：O(n)，其中 n 为链表长度
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!(head)) {
            return nullptr;
        }
        if (!(head -> next)) {
            return head;
        }
        ListNode* n1 = head;
        ListNode* n2 = head -> next;
        ListNode* n3 = head -> next -> next;
        head -> next = nullptr;
        while (1) {
            n2 -> next = n1;
            n1 = n2;
            n2 = n3;
            if (n3 == nullptr) {
                break;
            }
            n3 = n3 -> next;
        }
        return n1;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    ListNode* n5 = new ListNode(5);
    ListNode* n4 = new ListNode(4);
    ListNode* n3 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n1 = new ListNode(1);
    n4 -> next = n5;
    n3 -> next = n4;
    n2 -> next = n3;
    n1 -> next = n2;
    ListNode* ans = solution -> reverseList(n1);
    ListNode* tmp = ans;
    while (tmp) {
        cout << tmp -> val << " ";
        tmp = tmp -> next;
    }
}
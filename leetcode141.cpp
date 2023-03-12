/*************************************************
Author: wenhaofang
Date: 2023-03-12
Description: leetcode141 - Linked List Cycle
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：快慢指针
 * 
 * 理论时间复杂度：O(n)，其中 n 为链表长度
 * 理论空间复杂度：O(1)
 */
/**
 * 思路
 * 
 * 慢指针每次走一步，快指针每次走两步
 * 
 * 若链表有环，则二者相遇在环上某一点，若链表无环，则快指针会到达链表末尾
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 特判
        if (!head) {
            return false;
        }
        // 快慢指针
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast -> next != nullptr && fast -> next -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    ListNode* n4 = new ListNode(4);
    ListNode* n3 = new ListNode(0);
    ListNode* n2 = new ListNode(2);
    ListNode* n1 = new ListNode(3);
    n4 -> next = n2;
    n3 -> next = n4;
    n2 -> next = n3;
    n1 -> next = n2;
    bool ans = solution -> hasCycle(n1);
    cout << ans << endl;
}
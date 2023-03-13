/*************************************************
Author: wenhaofang
Date: 2023-03-12
Description: leetcode160 - Intersection of Two Linked Lists
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：栈
 * 
 * 理论时间复杂度：O(m + n)，其中 m、n 为两个链表的长度
 * 理论空间复杂度：O(m + n)，其中 m、n 为两个链表的长度
 */
/**
 * 思路
 * 
 * 分别遍历两个链表，将其存入栈中，然后同时出栈，判断节点是否相同
 * 
 * 如果相同，则说明是相交部分，如果不同，则说明是分叉部分
*/

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if (headA == nullptr) {
//             return nullptr;
//         }
//         if (headB == nullptr) {
//             return nullptr;
//         }
//         stack<ListNode*> stackA;
//         stack<ListNode*> stackB;
//         while (headA != nullptr) {
//             stackA.push(headA);
//             headA = headA -> next;
//         }
//         while (headB != nullptr) {
//             stackB.push(headB);
//             headB = headB -> next;
//         }
//         ListNode* ans = nullptr;
//         while (!stackA.empty() && !stackB.empty()) {
//             ListNode* currA = stackA.top();
//             ListNode* currB = stackB.top();
//             if (currA == currB) {
//                 ans = currA;
//                 stackA.pop();
//                 stackB.pop();
//             } else break;
//         }
//         return ans;
//     }
// };

/**
 * 方法二：数学
 * 
 * 理论时间复杂度：O(m + n)，其中 m、n 为两个链表的长度
 * 理论空间复杂度：O(1)
 */
/**
 * 思路
 * 
 * 初始化指针在两个链表开头并同时向前走
 * 
 * 当 A 指针到达末尾时，将其指向 B 开头
 * 
 * 当 B 指针到达末尾时，将其指向 A 开头
 * 
 * 当二者相遇在某一节点时就是答案
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr) {
            return nullptr;
        }
        if (headB == nullptr) {
            return nullptr;
        }
        ListNode* currA = headA;
        ListNode* currB = headB;
        while (currA != currB) {
            currA = currA == nullptr ? headB : currA -> next;
            currB = currB == nullptr ? headA : currB -> next;
        }
        return currA;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    ListNode* c3 = new ListNode(5);
    ListNode* c2 = new ListNode(4);
    ListNode* c1 = new ListNode(8);
    ListNode* b3 = new ListNode(1);
    ListNode* b2 = new ListNode(6);
    ListNode* b1 = new ListNode(5);
    ListNode* a2 = new ListNode(1);
    ListNode* a1 = new ListNode(4);
    a1 -> next = a2;
    a2 -> next = c1;
    b1 -> next = b2;
    b2 -> next = b3;
    b3 -> next = c1;
    c1 -> next = c2;
    c2 -> next = c3;
    ListNode* ans = solution -> getIntersectionNode(a1, b1);
    cout << ans -> val << endl;
}
/*************************************************
Author: wenhaofang
Date: 2021-03-26
Description: leetcode21 - Merge Two Sorted Lists
*************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>

using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::stack;
using std::queue;
using std::priority_queue;
using std::max;
using std::min;
using std::pair;
using std::cin;
using std::cout;
using std::endl;

/**
 * 思路一：归并
 * 
 * 时间复杂度：O(m + n)，其中 m、n 分别为两个链表的长度
 * 空间复杂度：O(m + n)，其中 m、n 分别为两个链表的长度
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 14.8 MB, less than 28.00% of C++ online submissions
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

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    ListNode* l1_2 = new ListNode(4);
    ListNode* l1_1 = new ListNode(2, l1_2);
    ListNode* l1_0 = new ListNode(1, l1_1);
    ListNode* l2_2 = new ListNode(4);
    ListNode* l2_1 = new ListNode(3, l2_2);
    ListNode* l2_0 = new ListNode(1, l2_1);
    ListNode* ans = solution->mergeTwoLists(l1_0, l2_0);
    ListNode* tmp = ans;
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}
/*************************************************
Author: wenhaofang
Date: 2021-03-05
Description: leetcode2 - Add Two Numbers
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
 * 思路一：按照加法原理逐位对应相加
 * 
 * 时间复杂度：max(m, n)，其中 m、n 分别为两个链表的大小
 * 空间复杂度：max(m, n)，其中 m、n 分别为两个链表的大小
 * 
 * 实际时间复杂度：Runtime: 16 ms, faster than 98.72% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 71.1 MB, less than 87.78% of C++ online submissions
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

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    ListNode* l1_2 = new ListNode(3);
    ListNode* l1_1 = new ListNode(4, l1_2);
    ListNode* l1_0 = new ListNode(2, l1_1);
    ListNode* l2_2 = new ListNode(4);
    ListNode* l2_1 = new ListNode(6, l2_2);
    ListNode* l2_0 = new ListNode(5, l2_1);
    ListNode* ans = solution->addTwoNumbers(l1_0, l2_0);
    ListNode* tmp = ans;
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}
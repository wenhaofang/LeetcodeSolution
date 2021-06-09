/*************************************************
Author: wenhaofang
Date: 2021-03-30
Description: leetcode25 - Reverse Nodes in k-Group
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
 * 思路一：递归
 * 
 * 时间复杂度：O(n)，其中 n 为链表长度
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 12 ms, faster than 89.71% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 11.5 MB, less than 20.46% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 递归的核心在于将原问题规约成子问题
 * 
 * 在这个过程中有三个要点：传入的参数、处理的过程、返回的结果
 * 规约子问题：翻转一个具有 k 个（小于 k 个）节点的链表
 * 传入的参数：链表翻转前的头指针
 * 处理的过程：接收翻转前的头指针，翻转所有节点，返回翻转后的头指针
 * 返回的结果：链表翻转后的头指针
 */

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// class Solution {
// public:
//     /**
//      * 该函数可以翻转一个具有 k 个（小于 k 个）节点的链表
//      * 其接收翻转前的头指针和尾指针，返回翻转后的头指针和尾指针
//      */
//     pair<ListNode*, ListNode*> reverseNode(ListNode* head, ListNode* tail) {
//         ListNode* prev = head;
//         ListNode* curr = head -> next;
//         while (prev != tail) {
//             ListNode* next = curr -> next;
//             curr -> next = prev;
//             prev = curr;
//             curr = next;
//         }
//         return { tail, head };
//     }

//     ListNode* reverseKGroup(ListNode* head, int k) {
//         // 特判
//         if (head == nullptr || k == 1) {
//             return head;
//         }
//         // prev: 当前处理链表的头指针，初始化为 head
//         // curr: 当前处理链表的尾指针，初始化为 head
//         int n = 1;
//         ListNode* prev = head;
//         ListNode* curr = head;
//         // 将当前处理链表的尾指针移动到 k 个节点后
//         // 如果不足 k 个节点，则移动到链表末尾停止
//         while (n < k && curr -> next) {
//             n = n + 1;
//             curr = curr -> next;
//         }
//         if (n < k) {
//             // 如果尾指针移动到链表末尾（不足 k 个节点）
//             // 此时不用翻转当前链表，直接返回 head 即可
//             return head;
//         } else {
//             // 如果尾指针移动到 k 个元素后，那么翻转当前链表
//             ListNode* next = curr -> next;
//             pair<ListNode*, ListNode*> result = reverseNode(prev, curr);
//             // 返回翻转后的头指针 newHead 和尾指针 newTail
//             ListNode* newHead = result.first;
//             ListNode* newTail = result.second;
//             // 并将当前处理链表翻转后的尾指针指向下一个要处理链表翻转后的头指针
//             newTail -> next = reverseKGroup(next, k);
//             // 返回当前处理链表翻转后的头指针
//             return newHead;
//         }
//     }
// };

/**
 * 思路二：迭代
 * 
 * 时间复杂度：O(n)，其中 n 为数组大小
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 16 ms, faster than 55.13% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 11.6 MB, less than 20.51% of C++ online submissions
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

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    ListNode* l1_4 = new ListNode(5);
    ListNode* l1_3 = new ListNode(4, l1_4);
    ListNode* l1_2 = new ListNode(3, l1_3);
    ListNode* l1_1 = new ListNode(2, l1_2);
    ListNode* l1_0 = new ListNode(1, l1_1);
    int k = 2;
    ListNode* ans = solution->reverseKGroup(l1_0, k);
    ListNode* tmp = ans;
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}
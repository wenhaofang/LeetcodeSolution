/*************************************************
Author: wenhaofang
Date: 2021-03-29
Description: leetcode24 - Swap Nodes in Pairs
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
 * 空间复杂度：O(n)，其中 n 为链表长度
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7.6 MB, less than 45.26% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 递归的核心在于将原问题规约成子问题
 * 
 * 在这个过程中有三个要点：传入的参数、处理的过程、返回的结果
 * 规约子问题：链表只有两个节点，交换两个节点的位置
 * 传入的参数：两节点交换前的头指针
 * 处理的过程：接收交换前的头指针，交换两节点位置，返回交换后的头指针
 * 返回的结果：两节点交换后的头指针
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
//     ListNode* swapPairs(ListNode* head) {
//         // prev: 指向第一个节点的指针
//         // 如果第一个节点为空，则直接返回该节点
//         ListNode* prev = head;
//         if (prev == nullptr) {
//             return prev;
//         }
//         // next: 指向第二个节点的指针
//         // 如果第二个节点为空，则返回第一个节点
//         ListNode* next = head -> next;
//         if (next == nullptr) {
//             return prev;
//         }
//         // 正常情况下递归调用该函数处理下一组节点
//         // 然后将第一个节点指向下一组的头节点
//         // 同时将第二个节点指向第一个节点
//         prev -> next = swapPairs(next -> next);
//         next -> next = prev;
//         // 返回交换后的头指针
//         return next;
//     }
// };

/**
 * 思路二：迭代
 * 
 * 时间复杂度：O(n)，其中 n 为链表长度
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7.6 MB, less than 45.26% of C++ online submissions
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
    ListNode* swapPairs(ListNode* head) {
        // 添加哑节点，并使 cur 初始化指向哑节点
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        // 进入循环
        while (
            cur -> next != nullptr &&
            cur -> next -> next != nullptr
        ) {
            // 令 one 指向 cur 后一个节点，令 two 指向 cur 后两个节点
            // 此时有 cur -> one -> two
            ListNode* one = cur -> next;
            ListNode* two = cur -> next -> next;
            // 交换 cur 后的两个节点 one & two
            // 此时有 cur -> two -> one
            cur -> next = two;
            one -> next = two -> next;
            two -> next = one;
            // 令 cur 等于 one
            // 重复以上步骤，直至到达链表末尾
            cur = one;
        }
        // 返回结果
        return dummy -> next;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    ListNode* l1_3 = new ListNode(4);
    ListNode* l1_2 = new ListNode(3, l1_3);
    ListNode* l1_1 = new ListNode(2, l1_2);
    ListNode* l1_0 = new ListNode(1, l1_1);
    ListNode* ans = solution->swapPairs(l1_0);
    ListNode* tmp = ans;
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}
/*************************************************
Author: wenhaofang
Date: 2022-02-27
Description: leetcode86 - Partition List
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
using std::swap;
using std::pair;
using std::cin;
using std::cout;
using std::endl;

/**
 * 方法一：暴力模拟
 * 
 * 理论时间复杂度：O(n)，其中 n 为链表长度
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 4 ms, faster than 88.70% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 10.4 MB, less than 31.00% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 遇到题目首先考虑最原始的解法
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
    ListNode* partition(ListNode* head, int x) {
        // 初始化两个链表
        // 一个用于存小值，另外一个用于存大值
        // 同时增加哑节点，便于处理特殊的情况
        ListNode* smallDummy = new ListNode(0);
        ListNode* largeDummy = new ListNode(0);
        ListNode* smallHead = smallDummy;
        ListNode* largeHead = largeDummy;
        // 遍历原链表
        while  (head) {
            if (head -> val < x) {
                // 小于特定值的接入存小值的链表
                smallHead -> next = head;
                smallHead = smallHead -> next;
            } else {
                // 大于等于特定值的接入存大值的链表
                largeHead -> next = head;
                largeHead = largeHead -> next;
            }
            head = head -> next;
        }
        // 将存小值的链表末尾接上存大值的链表
        // 将存大值的链表末尾接上空指针
        // 返回拼接的链表
        smallHead -> next = largeDummy -> next;
        largeHead -> next = nullptr;
        return smallDummy -> next;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    ListNode* val6 = new ListNode(2);
    ListNode* val5 = new ListNode(5, val6);
    ListNode* val4 = new ListNode(2, val5);
    ListNode* val3 = new ListNode(3, val4);
    ListNode* val2 = new ListNode(4, val3);
    ListNode* val1 = new ListNode(1, val2);
    int x = 3;
    ListNode* ans = solution -> partition(val1, x);
    ListNode* tmp = ans;
    while (tmp) {
        cout << tmp -> val << " ";
        tmp = tmp -> next;
    }
    cout << "\n";
}
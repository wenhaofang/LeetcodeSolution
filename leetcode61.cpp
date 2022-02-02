/*************************************************
Author: wenhaofang
Date: 2022-02-04
Description: leetcode61 - Rotate List
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
 * 实际时间复杂度：Runtime: 4 ms, faster than 94.61% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 11.7 MB, less than 54.91% of C++ online submissions
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
    ListNode* rotateRight(ListNode* head, int k) {
        // 特判
        if (
            head == nullptr ||
            head -> next == nullptr
        ) {
            return head;
        }
        if (k == 0) {
            return head;
        }
        // 处理
        // 1. 形成闭环
        int m = 1;
        ListNode* tail = head;
        while (tail -> next != nullptr) {
            tail = tail -> next;
            m += 1;
        }
        tail -> next = head;
        // 2. 找出断点
        int n = 0;
        ListNode* temp = head;
        while (n < m - (k % m) - 1) { // 最后减一是因为走到目标前一个元素即可
            temp = temp -> next;
            n += 1;
        }
        // 3. 返回结果
        ListNode* ans = temp -> next;
        temp -> next = nullptr;
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    ListNode* val5 = new ListNode(5);
    ListNode* val4 = new ListNode(4, val5);
    ListNode* val3 = new ListNode(3, val4);
    ListNode* val2 = new ListNode(2, val3);
    ListNode* val1 = new ListNode(1, val2);
    int k = 2;
    ListNode* ans = solution -> rotateRight(val1, k);
    ListNode* tmp = ans;
    while (tmp) {
        cout << tmp -> val << " ";
        tmp = tmp -> next;
    }
}
/*************************************************
Author: wenhaofang
Date: 2022-02-23
Description: leetcode82 - Remove Duplicates from Sorted List II
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
 * 方法一：快慢指针
 * 
 * 理论时间复杂度：O(n)，其中 n 为链表长度
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 11.2 MB, less than 59.35% of C++ online submissions
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
    ListNode* deleteDuplicates(ListNode* head) {
        // 特判
        if (
            head == nullptr ||
            head -> next == nullptr
        ) {
            return head;
        }
        // 技巧
        // 增加哑节点，避免对头节点做特殊判断
        ListNode* dummy = new ListNode(0, head);
        // 初始指针
        ListNode* slow = dummy;
        ListNode* fast = head;
        // 移动指针
        while (fast) { // 停止条件
            while (
                fast -> next &&
                fast -> val == fast -> next -> val
            ) {
                fast = fast -> next;
            }
            if (slow -> next != fast) {
                slow -> next = fast -> next;
            } else {
                slow = slow -> next;
            }
            fast = fast -> next;
        }
        // 返回结果
        // 记得删除哑节点，避免内存泄漏
        ListNode* ans = dummy -> next;
        delete dummy;
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    ListNode* val7 = new ListNode(5);
    ListNode* val6 = new ListNode(4, val7);
    ListNode* val5 = new ListNode(4, val6);
    ListNode* val4 = new ListNode(3, val5);
    ListNode* val3 = new ListNode(3, val4);
    ListNode* val2 = new ListNode(2, val3);
    ListNode* val1 = new ListNode(1, val2);
    ListNode* ans = solution -> deleteDuplicates(val1);
    ListNode* tmp = ans;
    while (tmp) {
        cout << tmp -> val << " ";
        tmp = tmp -> next;
    }
    cout << "\n";
}
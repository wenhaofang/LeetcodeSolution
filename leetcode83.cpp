/*************************************************
Author: wenhaofang
Date: 2022-02-24
Description: leetcode83 - Remove Duplicates from Sorted List
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
 * 实际时间复杂度：Runtime: 4 ms, faster than 99.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 11.7 MB, less than 36.35% of C++ online submissions
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
        // 初始指针
        ListNode* slow = head;
        ListNode* fast = head;
        // 移动指针
        while (fast) {
            while (
                fast -> next &&
                fast -> val == fast -> next -> val
            ) {
                fast = fast -> next;
            }
            if (slow != fast) {
                slow -> next = fast -> next;
            }
            slow = slow -> next;
            fast = fast -> next;
        }
        // 返回结果
        return head;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    ListNode* val5 = new ListNode(3);
    ListNode* val4 = new ListNode(3, val5);
    ListNode* val3 = new ListNode(2, val4);
    ListNode* val2 = new ListNode(1, val3);
    ListNode* val1 = new ListNode(1, val2);
    ListNode* ans = solution -> deleteDuplicates(val1);
    ListNode* tmp = ans;
    while (tmp) {
        cout << tmp -> val << " ";
        tmp = tmp -> next;
    }
    cout << "\n";
}
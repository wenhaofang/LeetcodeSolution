/*************************************************
Author: wenhaofang
Date: 2021-03-24
Description: leetcode19 - Remove Nth Node From End of List
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
 * 思路一：栈
 * 
 * 时间复杂度：O(n)，其中 n 为链表长度
 * 空间复杂度：O(n)，其中 n 为链表长度
 * 
 * 实际时间复杂度：Runtime: 4 ms, faster than 80.13% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 10.8 MB, less than 13.04% of C++ online submissions
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
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         // 定义节点栈
//         stack<ListNode*> stk;
//         // 增加哑节点，避免对头节点做特殊判断
//         ListNode* dummy = new ListNode(0, head);
//         // 所有节点入栈
//         ListNode* curr = dummy;
//         while (curr) {
//             stk.push(curr);
//             curr = curr -> next;
//         }
//         // 倒数 n 个节点出栈
//         while (n--) {
//             stk.pop();
//         }
//         // 当前栈顶节点即为待删除节点的前一个节点
//         ListNode* prev = stk.top();
//         prev -> next = prev -> next -> next;
//         // 保存头节点作为结果返回，并删除哑节点
//         ListNode* ans = dummy -> next;
//         delete dummy;
//         return ans;
//     }
// };

/**
 * 思路二：快慢指针
 * 
 * 时间复杂度：O(n)，其中 n 为链表长度
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 10.8 MB, less than 13.04% of C++ online submissions
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 增加哑节点，避免对头节点做特殊判断
        ListNode* dummy = new ListNode(0, head);
        // 定义快、慢指针，同时初始化在哑节点
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        // 快指针首先移动 n 位
        for (int i = 0; i < n; i++) {
            fast = fast -> next;
        }
        // 快、慢指针同时移动，直至快指针到达链表末尾
        while (fast -> next) {
            fast = fast -> next;
            slow = slow -> next;
        }
        // 此时慢指针指向即为待删除节点的前一个节点
        slow -> next = slow -> next -> next;
        // 保存头节点作为结果返回，并删除哑节点
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
    ListNode* val5 = new ListNode(5);
    ListNode* val4 = new ListNode(4, val5);
    ListNode* val3 = new ListNode(3, val4);
    ListNode* val2 = new ListNode(2, val3);
    ListNode* val1 = new ListNode(1, val2);
    int n = 2;
    ListNode* ans = solution->removeNthFromEnd(val1, n);
    ListNode* tmp = ans;
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}
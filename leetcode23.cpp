/*************************************************
Author: wenhaofang
Date: 2021-03-28
Description: leetcode23 - Merge k Sorted Lists
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
 * 思路一：多路归并 + 优先队列
 * 
 * 时间复杂度：O(kn × logk)，其中 k 为链表数量，n 为链表中元素的个数
 * 空间复杂度：O(k)，其中 k 为链表数量，n 为链表中元素的个数
 * 
 * 实际时间复杂度：Runtime: 24 ms, faster than 60.89% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 13.5 MB, less than 42.10% of C++ online submissions
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
//     // 优先队列默认实现为大顶堆
//     // 自定义结构体重载比较函数，将其改为小顶堆
//     struct Status {
//         int val;
//         ListNode* ptr;
//         bool operator < (const Status &rhs) const {
//             return val > rhs.val;
//         }
//     };

//     /**
//      * 初始化多个指针，每个指针分别指向各链表的第一个节点
//      * 每次将值最小的节点加入结果链表（优先队列实现）
//      * 然后当前链表的指针前移一位，直至所有指针都到达各个链表的结尾
//      */
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         // head: 头部指针，用于返回结果
//         // curr: 当前指针，用于添加节点
//         ListNode* head = new ListNode(0);
//         ListNode* curr = head;
//         // 优先队列，小顶堆实现，队首元素是最小元素
//         priority_queue<Status> q;
//         // 将所有链表的第一个节点添加到优先队列
//         for (auto first: lists) {
//             if (first) {
//                 q.push({first -> val, first});
//             }
//         }
//         // 每次从优先队列中取出最小节点，将其加入结果链表
//         // 然后从最小节点所在链表取下一个节点加入优先队列
//         // 直至优先队列为空
//         while (!q.empty()) {
//             auto top = q.top(); q.pop();
//             curr -> next = top.ptr;
//             curr = curr -> next;
//             if (top.ptr -> next) {
//                 q.push({top.ptr -> next -> val, top.ptr -> next});
//             }
//         }
//         // 返回结果
//         return head -> next;
//     }
// };

/**
 * 思路二：双路归并 + 分治
 * 
 * 时间复杂度：O(kn × logk)，其中 k 为链表数量，n 为链表中元素的个数
 * 空间复杂度：O(logk)，其中 k 为链表数量，n 为链表中元素的个数
 * 
 * 实际时间复杂度：Runtime: 16 ms, faster than 97.27% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 22.7 MB, less than 5.03% of C++ online submissions
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
    // 合并两个有序数组，具体请参考 leetcode21
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
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
        curr -> next = (l1 == nullptr) ? l2 : l1;
        return head -> next;
    }

    // 分治
    ListNode* merge(vector<ListNode*> &lists, int l, int r) {
        // 终止条件
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        // 分而治之
        int mid = (l + r) / 2;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<ListNode*> lists;
    ListNode* l1_2 = new ListNode(5);
    ListNode* l1_1 = new ListNode(4, l1_2);
    ListNode* l1_0 = new ListNode(1, l1_1);
    ListNode* l2_2 = new ListNode(4);
    ListNode* l2_1 = new ListNode(3, l2_2);
    ListNode* l2_0 = new ListNode(1, l2_1);
    ListNode* l3_1 = new ListNode(6);
    ListNode* l3_0 = new ListNode(2, l3_1);
    lists.push_back(l1_0);
    lists.push_back(l2_0);
    lists.push_back(l3_0);
    ListNode* ans = solution->mergeKLists(lists);
    ListNode* tmp = ans;
    while (tmp) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}
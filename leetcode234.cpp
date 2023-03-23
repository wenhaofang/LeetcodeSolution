/*************************************************
Author: wenhaofang
Date: 2023-03-23
Description: leetcode234 - Palindrome Linked List
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：转数组
 * 
 * 理论时间复杂度：O(n)，其中 n 为链表长度
 * 理论空间复杂度：O(n)，其中 n 为链表长度
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
//     bool isPalindrome(ListNode* head) {
//         vector<int> nums;
//         while (head) {
//             nums.push_back(head -> val);
//             head = head -> next;
//         }
//         int n = nums.size();
//         if (n % 2 == 0) {
//             int i = n / 2 - 1;
//             int j = n / 2;
//             while (i >= 0 && j <= n - 1) {
//                 if (nums[i] != nums[j]) {
//                     return false;
//                 }
//                 i--;
//                 j++;
//             }
//         }
//         else {
//             int k = n / 2;
//             int i = k - 1;
//             int j = k + 1;
//             while (i >= 0 && j <= n - 1) {
//                 if (nums[i] != nums[j]) {
//                     return false;
//                 }
//                 i--;
//                 j++;
//             }
//         }
//         return true;
//     }
// };

/**
 * 方法二：反转链表
 * 
 * 理论时间复杂度：O(n)，其中 n 为链表长度
 * 理论空间复杂度：O(1)
 */
/**
 * 思路
 * 
 * 反转一半链表之后比较，步骤如下：
 * 
 * 1. 找出链表中点
 * 2. 反转后半链表
 * 3. 比较是否回文
 * 4. 还原后半链表
 * 5. 最后返回答案
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
    bool isPalindrome(ListNode* head) {
        // 1
        ListNode* mid = findMid(head);
        // 2
        ListNode* hd2 = reverse(mid -> next);
        // 3
        ListNode* p1 = head;
        ListNode* p2 = hd2;
        bool ans = compare(p1, p2);
        // 4
        reverse(hd2);
        // 5
        return ans;
    }

    ListNode* findMid(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (
            fast -> next &&
            fast -> next -> next
        ) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    // leetcode206
    ListNode* reverse(ListNode* head) {
        if (!(head)) {
            return nullptr;
        }
        if (!(head -> next)) {
            return head;
        }
        ListNode* n1 = head;
        ListNode* n2 = head -> next;
        ListNode* n3 = head -> next -> next;
        head -> next = nullptr;
        while (1) {
            n2 -> next = n1;
            n1 = n2;
            n2 = n3;
            if (n3 == nullptr) {
                break;
            }
            n3 = n3 -> next;
        }
        return n1;
    }

    bool compare(ListNode* p1, ListNode* p2) {
        while  (p1 && p2) {
            if (p1 -> val != p2 -> val) {
                return false;
            }
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return true;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    ListNode* n4 = new ListNode(1);
    ListNode* n3 = new ListNode(2);
    ListNode* n2 = new ListNode(2);
    ListNode* n1 = new ListNode(1);
    n3 -> next = n4;
    n2 -> next = n3;
    n1 -> next = n2;
    bool ans = solution -> isPalindrome(n1);
    cout << ans << endl;
}
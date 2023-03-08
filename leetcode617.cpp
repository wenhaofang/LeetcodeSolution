/*************************************************
Author: wenhaofang
Date: 2023-03-08
Description: leetcode617 - Merge Two Binary Trees
*************************************************/

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>

using std::list;
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
using std::atoi;
using std::stoi;
using std::to_string;
using std::cin;
using std::cout;
using std::endl;

/**
 * 方法一：递归
 * 
 * 理论时间复杂度：O(n)，其中 n 为节点数量
 * 理论空间复杂度：O(n)，其中 n 为节点数量
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }
        else if (root1 != nullptr && root2 != nullptr) {
            TreeNode* cur = new TreeNode(root1 -> val + root2 -> val);
            cur -> left = mergeTrees(root1 -> left, root2 -> left);
            cur -> right = mergeTrees(root1 -> right, root2 -> right);
            return cur;
        }
        else if (root1 != nullptr && root2 == nullptr) {
            TreeNode* cur = new TreeNode(root1 -> val);
            cur -> left = mergeTrees(root1 -> left, nullptr);
            cur -> right = mergeTrees(root1 -> right, nullptr);
            return cur;
        }
        else if (root1 == nullptr && root2 != nullptr) {
            TreeNode* cur = new TreeNode(root2 -> val);
            cur -> left = mergeTrees(nullptr, root2 -> left);
            cur -> right = mergeTrees(nullptr, root2 -> right);
            return cur;
        }
        return nullptr;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    TreeNode* n31 = new TreeNode(5);
    TreeNode* n22 = new TreeNode(2);
    TreeNode* n21 = new TreeNode(3, n31, nullptr);
    TreeNode* n11 = new TreeNode(1, n21, n22);
    TreeNode* m34 = new TreeNode(7);
    TreeNode* m32 = new TreeNode(4);
    TreeNode* m22 = new TreeNode(3, m34, nullptr);
    TreeNode* m21 = new TreeNode(1, m32, nullptr);
    TreeNode* m11 = new TreeNode(2, m21, m22);
    TreeNode* ans = solution -> mergeTrees(n11, m11);
}
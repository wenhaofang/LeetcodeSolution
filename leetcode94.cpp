/*************************************************
Author: wenhaofang
Date: 2023-03-04
Description: leetcode94 - Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        myInorderTraversal(root, ans);
        return ans;
    }

    void myInorderTraversal(TreeNode* root, vector<int>& ans) {
        // 边界情况
        if (root == nullptr) {
            return;
        }
        // 基本情况
        myInorderTraversal(root -> left, ans);
        ans.push_back(root -> val);
        myInorderTraversal(root -> right, ans);
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    TreeNode* n33 = new TreeNode(3);
    TreeNode* n22 = new TreeNode(2, n33, nullptr);
    TreeNode* n11 = new TreeNode(1, nullptr, n22);
    vector<int> ans = solution -> inorderTraversal(n11);
    for (auto item: ans) {
        cout << item << " ";
    }
}
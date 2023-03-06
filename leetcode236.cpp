/*************************************************
Author: wenhaofang
Date: 2023-03-06
Description: leetcode236 - Lowest Common Ancestor of a Binary Tree
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
 * 理论空间复杂度：O(h)，其中 h 为树的高度
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
    TreeNode* ans;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        haveNodes(root, p, q);
        return ans;
    }

    bool haveNodes (TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return false;
        }
        bool left = haveNodes(root -> left, p, q);
        bool right = haveNodes(root -> right, p, q);

        if ((left && right) || ((root -> val == p -> val || root -> val == q -> val) && (left || right))) {
            ans = root;
        }

        return left || right || root -> val == p -> val || root -> val == q -> val;
    }
};


/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    TreeNode* n44 = new TreeNode(4);
    TreeNode* n43 = new TreeNode(7);
    TreeNode* n34 = new TreeNode(8);
    TreeNode* n33 = new TreeNode(0);
    TreeNode* n32 = new TreeNode(2, n43, n44);
    TreeNode* n31 = new TreeNode(6);
    TreeNode* n22 = new TreeNode(1, n33, n34);
    TreeNode* n21 = new TreeNode(5, n31, n32);
    TreeNode* n11 = new TreeNode(3, n21, n22);
    TreeNode* ans = solution -> lowestCommonAncestor(n11, n21, n22);
    cout << ans -> val << endl;
}
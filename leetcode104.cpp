/*************************************************
Author: wenhaofang
Date: 2023-03-06
Description: leetcode104 - Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        // 边界情况
        if (!root) {
            return 0;
        }
        // 基本情况
        int left = maxDepth(root -> left); // 左子树最大深度
        int right = maxDepth(root -> right); // 右子树最大深度
        int ans = max(left, right) + 1; // 后序位置
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    TreeNode* n34 = new TreeNode(7);
    TreeNode* n33 = new TreeNode(15);
    TreeNode* n22 = new TreeNode(20, n33, n34);
    TreeNode* n21 = new TreeNode(9);
    TreeNode* n11 = new TreeNode(3, n21, n22);
    int ans = solution -> maxDepth(n11);
    cout << ans << endl;
}
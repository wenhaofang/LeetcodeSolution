/*************************************************
Author: wenhaofang
Date: 2023-03-08
Description: leetcode101 - Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        return helper(root -> left, root -> right);
    }

    bool helper(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        if (root1 -> val != root2 -> val) {
            return false;
        }
        return (
            helper(root1 -> left, root2 -> right) &&
            helper(root2 -> left, root1 -> right)
        );
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    TreeNode* n34 = new TreeNode(3);
    TreeNode* n33 = new TreeNode(4);
    TreeNode* n32 = new TreeNode(4);
    TreeNode* n31 = new TreeNode(3);
    TreeNode* n22 = new TreeNode(2, n33, n34);
    TreeNode* n21 = new TreeNode(2, n31, n32);
    TreeNode* n11 = new TreeNode(1, n21, n22);
    bool ans = solution -> isSymmetric(n11);
    cout << ans << endl;
}
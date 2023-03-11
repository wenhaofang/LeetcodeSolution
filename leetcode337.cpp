/*************************************************
Author: wenhaofang
Date: 2023-03-11
Description: leetcode337 - House Robber III
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
    unordered_map<TreeNode*, int> true_map;
    unordered_map<TreeNode*, int> false_map;

    int rob(TreeNode* root) {
        return dfs(root, true);
    }

    int dfs(TreeNode* root, bool canSteal) {
        if (!root) {
            return 0;
        }
        if (canSteal) {
            if (true_map.find(root) == true_map.end()) {
                true_map[root] = dfs(root -> left, false) + dfs(root -> right, false) + root -> val;
            }
            if (false_map.find(root) == false_map.end()) {
                false_map[root] = dfs(root -> left, true) + dfs(root -> right, true);
            }
            return max(true_map[root], false_map[root]);
        }
        else {
            if (false_map.find(root) == false_map.end()) {
                false_map[root] = dfs(root -> left, true) + dfs(root -> right, true);
            }
            return false_map[root];
        }
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    TreeNode* n34 = new TreeNode(1);
    TreeNode* n32 = new TreeNode(3);
    TreeNode* n22 = new TreeNode(3, nullptr, n34);
    TreeNode* n21 = new TreeNode(2, nullptr, n32);
    TreeNode* n11 = new TreeNode(3, n21, n22);
    int ans = solution -> rob(n11);
    cout << ans << endl;
}
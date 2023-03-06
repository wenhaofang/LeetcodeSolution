/*************************************************
Author: wenhaofang
Date: 2023-03-06
Description: leetcode124 - Binary Tree Maximum Path Sum
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
    int ans = INT_MIN;

    int maxPathSum(TreeNode* root) {
        maxSideSum(root);
        return ans;
    }

    int maxSideSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = maxSideSum(root -> left);
        int right = maxSideSum(root -> right);
        int val = root -> val;
        int cur = max({val, left + val, right + val});
        ans = max({ans, cur, left + val + right});
        return cur;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    TreeNode* n22 = new TreeNode(3);
    TreeNode* n21 = new TreeNode(2);
    TreeNode* n11 = new TreeNode(1, n21, n22);
    int ans = solution -> maxPathSum(n11);
    cout << ans << endl;
}
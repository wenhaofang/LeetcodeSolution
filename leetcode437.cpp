/*************************************************
Author: wenhaofang
Date: 2023-03-11
Description: leetcode437 - Path Sum III
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
 * 理论时间复杂度：O(n^2)，其中 n 为节点数量
 * 理论空间复杂度：O(n)  ，其中 n 为节点数量
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
    int ans = 0;

    int pathSum(TreeNode* root, long long int targetSum) {
        traverse(root, targetSum);
        return ans;
    }

    void traverse(TreeNode* root, long long int targetSum) {
        if (!root) {
            return;
        }
        ans += rootSum(root, targetSum, 0);
        traverse(root -> left, targetSum);
        traverse(root -> right, targetSum);
    }

    int rootSum(TreeNode* root, long long int targetSum, long long int sourceSum) {
        if (!root) {
            return 0;
        }
        sourceSum += root -> val;
        int left = rootSum(root -> left, targetSum, sourceSum);
        int right = rootSum(root -> right, targetSum, sourceSum);
        return left + right + (targetSum == sourceSum ? 1 : 0);
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    TreeNode* n44 = new TreeNode(1);
    TreeNode* n42 = new TreeNode(-2);
    TreeNode* n41 = new TreeNode(3);
    TreeNode* n34 = new TreeNode(11);
    TreeNode* n32 = new TreeNode(2, nullptr, n44);
    TreeNode* n31 = new TreeNode(3, n41, n42);
    TreeNode* n22 = new TreeNode(-3, nullptr, n34);
    TreeNode* n21 = new TreeNode(5, n31, n32);
    TreeNode* n11 = new TreeNode(10, n21, n22);
    int targetSum = 8;
    int ans = solution -> pathSum(n11, targetSum);
    cout << ans << endl;
}
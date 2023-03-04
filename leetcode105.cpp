/*************************************************
Author: wenhaofang
Date: 2023-03-04
Description: leetcode105 - Construct Binary Tree from Preorder and Inorder Traversal
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
/**
 * 基本思路
 * 
 * 0. 前序遍历结果：[父节点, [左子树前序遍历结果], [右子树前序遍历结果]]
 *    中序遍历结果：[[左子树中序遍历结果], 父节点, [右子树中序遍历结果]]
 * 1. 从前序遍历结果可知父节点，很显然第一个值就是
 * 2. 从中序遍历结果搜索父节点，父节点左边的值就是左子树，父节点右边的值就是右子树，然后再统计左右子树元素数量
 * 3. 然后根据左右子树元素数量，从前序遍历结果分出左子树和右子树
 * 4. 最后再对左右子树递归上述的步骤
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
    unordered_map<int, int> val2idx;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 构造哈希映射
        // 可加速在中序遍历结果找到根节点
        for (int i = 0; i < inorder.size(); i++) {
            val2idx[inorder[i]] = i;
        }
        // 进入递归
        return myBuildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    // 递归函数
    TreeNode* myBuildTree(
        vector<int>& preorder,
        vector<int>& inorder,
        // 不修改原序列
        // 通过下标表示要处理的序列段
        int preorder_left,
        int preorder_right,
        int inorder_left,
        int inorder_right
    ) {
        // 边界情况
        if (preorder_left > preorder_right) {
            return nullptr;
        }

        // 基本情况
        int preorder_root = preorder_left;

        int root_value = preorder[preorder_root];
        TreeNode* root = new TreeNode(root_value);

        int inorder_root = val2idx[root_value];
        int left_subtree = inorder_root - inorder_left;

        root -> left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + left_subtree, inorder_left, inorder_root - 1);
        root -> right = myBuildTree(preorder, inorder, preorder_left + 1 + left_subtree, preorder_right, inorder_root + 1, inorder_right);

        return root;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode* ans = solution -> buildTree(preorder, inorder);
}
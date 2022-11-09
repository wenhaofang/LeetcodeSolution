/*************************************************
Author: wenhaofang
Date: 2022-11-08
Description: leetcode102 - Binary Tree Level Order Traversal
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
 * 方法一：广度优先搜索
 * 
 * 理论时间复杂度：O(n)，其中 n 为节点数量
 * 理论空间复杂度：O(n)，其中 n 为节点数量
 * 
 * 实际时间复杂度：Runtime: 3 ms, faster than 92.44% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 12.2 MB, less than 99.40% of C++ online submissions
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 特判
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        // 初始化队列为空
        queue<TreeNode*> q;
        // 将初始节点加入队列
        q.push(root);
        // 每次取出队列中的所有节点进行处理
        // 再把这些节点的左右子节点加入队列
        // 直至队列为空时结束
        while (!q.empty()) {
            ans.push_back(vector<int>());
            int num = q.size();
            while (num-- > 0) {
                // 当前元素出队
                TreeNode* node = q.front(); q.pop();
                // 并把当前元素加入结果
                ans.back().push_back(node -> val);
                // 相邻元素入队
                if (node -> left ) { q.push(node -> left ); }
                if (node -> right) { q.push(node -> right); }
            }
        }
        // 返回结果
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
    vector<vector<int>> ans = solution -> levelOrder(n11);
    for (vector<vector<int>>::iterator outer_iter = ans.begin(); outer_iter != ans.end(); outer_iter++) {
        for (vector<int>::iterator inner_iter = (*outer_iter).begin(); inner_iter != (*outer_iter).end(); inner_iter++) {
            cout << (*inner_iter) << " ";
        }
        cout << endl;
    }
}
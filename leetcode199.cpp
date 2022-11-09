/*************************************************
Author: wenhaofang
Date: 2022-11-10
Description: leetcode199 - Binary Tree Right Side View
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
 * 实际时间复杂度：Runtime: 3 ms, faster than 87.50% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 12 MB, less than 70.32% of C++ online submissions
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
    vector<int> rightSideView(TreeNode* root) {
        // 特判
        vector<int> ans;
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
            int num = q.size();
            while (num-- > 0) {
                // 当前元素出队
                TreeNode* node = q.front(); q.pop();
                // 如果当前节点符合要求，即该节点为最右侧节点
                // 那么将该节点加入结果
                if (num == 0) {
                    ans.push_back(node -> val);
                }
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
    TreeNode* n34 = new TreeNode(4);
    TreeNode* n32 = new TreeNode(5);
    TreeNode* n22 = new TreeNode(3, n32, n34);
    TreeNode* n21 = new TreeNode(2);
    TreeNode* n11 = new TreeNode(1, n21, n22);
    vector<int> ans = solution -> rightSideView(n11);
    for (auto item: ans) {
        cout << item << "\n";
    }
}
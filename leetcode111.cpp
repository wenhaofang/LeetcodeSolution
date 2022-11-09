/*************************************************
Author: wenhaofang
Date: 2022-11-09
Description: leetcode111 - Minimum Depth of Binary Tree
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
 * 方法一：深度优先搜索
 * 
 * 理论时间复杂度：O(n)，其中 n 为节点数量
 * 理论空间复杂度：O(m)，其中 m 为树的高度
 * 
 * 实际时间复杂度：Runtime: 328 ms, faster than 79.94% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 144.6 MB, less than 72.80% of C++ online submissions
 */

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         // 特判
//         if (!root) {
//             return 0;
//         }
//         // 递归
//         int ld = minDepth(root -> left);
//         int rd = minDepth(root -> right);
//         if (ld > 0 && rd > 0) {
//             return 1 + min(ld, rd);
//         } else {
//             return 1 + max(ld, rd);
//         }
//     }
// };

/**
 * 方法二：广度优先搜索
 * 
 * 理论时间复杂度：O(n)，其中 n 为节点数量
 * 理论空间复杂度：O(n)，其中 n 为节点数量
 * 
 * 实际时间复杂度：Runtime: 269 ms, faster than 97.81% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 144.7 MB, less than 44.84% of C++ online submissions
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
    int minDepth(TreeNode* root) {
        // 特判
        if (!root) {
            return 0;
        }
        // 初始化队列为空
        queue<TreeNode*> q;
        // 将初始节点加入队列
        q.push(root);
        // 初始化步数为一
        int step = 1;
        // 每次取出队列中的所有节点进行处理
        // 再把这些节点的左右子节点加入队列
        while (!q.empty()) {
            int num = q.size();
            while (num-- > 0) {
                // 当前元素出队
                TreeNode* node = q.front(); q.pop();
                // 如果满足结束条件，即到达叶节点
                // 那么马上返回结果
                if (node -> left == nullptr && node -> right == nullptr) { return step; }
                // 相邻元素入队
                if (node -> left ) { q.push(node -> left ); }
                if (node -> right) { q.push(node -> right); }
            }
            // 步数加一
            step++;
        }
        return -1;
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
    int ans = solution -> minDepth(n11);
    cout << ans << endl;
}
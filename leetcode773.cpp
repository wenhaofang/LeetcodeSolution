/*************************************************
Author: wenhaofang
Date: 2022-11-15
Description: leetcode773 - Sliding Puzzle
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
 * 理论时间复杂度：O((m * n)! * (m * n))，其中 m、n 分别为矩阵的宽和长
 * 理论空间复杂度：O((m * n)! * (m * n))，其中 m、n 分别为矩阵的宽和长
 * 
 * 实际时间复杂度：Runtime: 10 ms, faster than 88.65% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 8.1 MB, less than 96.40% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 1、将二维数组转化为单维的字符串，将当前问题转化为 leetcode752
 * 
 * 2、对相邻位置预处理
 */

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // 预处理
        string target = "123450";
        int m = board.size();
        int n = board[0].size();
        string input;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                input += char(board[i][j] + '0');
            }
        }
        vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        // 初始化步数
        int step = 0;
        // 初始化队列
        queue <string> q;
        q.push(input);
        // 初始化集合
        unordered_set<string> visited;
        visited.insert(input);
        // 每次取出队列中的所有节点进行处理
        // 然后把这些节点的相邻节点加入队列
        // 直至队列为空时结束
        while (!q.empty()) {
            int num = q.size();
            while (num-- > 0) {
                // 当前元素出队
                string str = q.front(); q.pop();
                // 如果元素能满足结束条件
                // 则返回对应结果
                if (str == target) {
                    return step;
                }
                // 将相邻元素入队
                int x = str.find('0');
                for (int y: neighbors[x]) {
                    // 交换
                    swap(str[x], str[y]);
                    // 判断是否曾经出现
                    if (visited.find(str) == visited.end()) {
                        q.push(str);
                        visited.insert(str);
                    }
                    // 还原
                    swap(str[x], str[y]);
                }
            }
            // 步数加一
            step++;
        }
        // 遍历完没找到目标
        return -1;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<vector<int>> board = {
        {1, 2, 3},
        {4, 0, 5},
    };
    int ans = solution -> slidingPuzzle(board);
    cout << ans << endl;
}
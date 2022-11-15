/*************************************************
Author: wenhaofang
Date: 2022-11-16
Description: leetcode127 - Word Ladder
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
 * 实际时间复杂度：Runtime: 136 ms, faster than 85.61% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 13.7 MB, less than 89.86% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 1、将当前问题转化为 leetcode752
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 初始化步数
        int step = 1;
        // 初始化队列
        queue <string> q;
        q.push(beginWord);
        // 初始化集合
        unordered_set<string> words {wordList.begin(), wordList.end()};
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
                if (str == endWord) {
                    return step;
                }
                // 将相邻元素入队
                char b;
                for (int i = 0; i < str.size(); i++) {
                    // 备份
                    b = str[i];
                    // 判断
                    for (char c = 'a'; c <= 'z'; c++) {
                        str[i] = c;
                        if (words.find(str) != words.end()) {
                            q.push(str);
                            words.erase(str);
                        }
                    }
                    // 还原
                    str[i] = b;
                }
            }
            // 步数加一
            step++;
        }
        // 遍历完没找到目标
        return 0;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    int ans = solution -> ladderLength(beginWord, endWord, wordList);
    cout << ans << endl;
}
/*************************************************
Author: wenhaofang
Date: 2022-11-14
Description: leetcode752 - Open the Lock
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
 * 理论时间复杂度：O(b ^ d * d ^ 2 + m * d)，其中 b、d、m 分别为数字进制、数字位数、死亡数字多少
 * 理论空间复杂度：O(b ^ d * d     + m    )，其中 b、d、m 分别为数字进制、数字位数、死亡数字多少
 * 
 * 实际时间复杂度：Runtime: 162 ms, faster than 92.57% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 35.3 MB, less than 62.02% of C++ online submissions
 */

// class Solution {
// public:
//     int openLock(vector<string>& deadends, string target) {
//         // 初始化步数
//         int step = 0;
//         // 初始化队列
//         queue <string> q;
//         q.push("0000");
//         // 初始化集合
//         unordered_set <string> deadeds {deadends.begin(), deadends.end()};
//         unordered_set <string> visited;
//         visited.insert("0000");
//         // 初始化辅助函数
//         auto addOne = [](char x) -> char {
//             return (x == '9' ? '0' : x + 1);
//         };
//         auto subOne = [](char x) -> char {
//             return (x == '0' ? '9' : x - 1);
//         };
//         // 每次取出队列中的所有节点进行处理
//         // 然后把这些节点的相邻节点加入队列
//         // 直至队列为空时结束
//         while (!q.empty()) {
//             int num = q.size();
//             while (num-- > 0) {
//                 // 当前元素出队
//                 string str = q.front(); q.pop();
//                 // 如果元素不满足约束条件
//                 // 则跳过当前元素
//                 if (deadeds.find(str) != deadeds.end()) {
//                     continue;
//                 }
//                 // 如果元素能满足结束条件
//                 // 则返回对应结果
//                 if (str == target) {
//                     return step;
//                 }
//                 // 将相邻元素入队
//                 char chr;
//                 for (int i = 0; i < 4; i++) {
//                     // 备份
//                     chr = str[i];
//                     // 第 i 个字符加 1
//                     str[i] = addOne(chr);
//                     if (visited.find(str) == visited.end()) {
//                         q.push(str);
//                         visited.insert(str);
//                     }
//                     // 第 i 个字符减 1
//                     str[i] = subOne(chr);
//                     if (visited.find(str) == visited.end()) {
//                         q.push(str);
//                         visited.insert(str);
//                     }
//                     // 还原
//                     str[i] = chr;
//                 }
//             }
//             // 步数加一
//             step++;
//         }
//         // 遍历完没找到目标
//         return -1;
//     }
// };

/**
 * 方法二：双向广度优先搜索
 * 
 * 理论时间复杂度：O(b ^ d * d ^ 2 + m * d)，其中 b、d、m 分别为数字进制、数字位数、死亡数字多少
 * 理论空间复杂度：O(b ^ d * d     + m    )，其中 b、d、m 分别为数字进制、数字位数、死亡数字多少
 * 
 * 实际时间复杂度：Runtime: 62 ms, faster than 97.36% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 18.9 MB, less than 94.31% of C++ online submissions
 */

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // 初始化步数
        int step = 0;
        // 初始化队列 (使用集合，方便判断是否有交集)
        unordered_set <string> q1 {"0000"};
        unordered_set <string> q2 {target};
        // 初始化集合
        unordered_set <string> deadeds {deadends.begin(), deadends.end()};
        unordered_set <string> visited;
        // 初始化辅助函数
        auto addOne = [](char x) -> char {
            return (x == '9' ? '0' : x + 1);
        };
        auto subOne = [](char x) -> char {
            return (x == '0' ? '9' : x - 1);
        };
        // 每次取出队列中的所有节点进行处理
        // 然后把这些节点的相邻节点加入队列
        // 直至队列为空时结束
        while (
            !q1.empty() &&
            !q2.empty()
        ) {
            // 构造临时集合
            unordered_set <string> q0;
            // 扩散小的集合
            // 取出当前元素
            if (q1.size() > q2.size()) {
                unordered_set <string> q3 = q1;
                q1 = q2;
                q2 = q3;
            }
            for (string str: q1) {
                // 如果元素不满足约束条件
                // 则跳过当前元素
                if (deadeds.find(str) != deadeds.end()) {
                    continue;
                }
                // 如果元素能满足结束条件
                // 则返回对应结果
                if (q2.find(str) != q2.end()) {
                    return step;
                }
                // 更新集合
                visited.insert(str);
                // 相邻元素入队
                char chr;
                for (int i = 0; i < 4; i++) {
                    // 备份
                    chr = str[i];
                    // 第 i 个字符加 1
                    str[i] = addOne(chr);
                    if (visited.find(str) == visited.end()) {
                        q0.insert(str);
                    }
                    // 第 i 个字符减 1
                    str[i] = subOne(chr);
                    if (visited.find(str) == visited.end()) {
                        q0.insert(str);
                    }
                    // 还原
                    str[i] = chr;
                }
            }
            // 步数加一
            step++;
            // 交换集合
            q1 = q2;
            q2 = q0;
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
    vector<string> deadends = {
        "0201",
        "0101",
        "0102",
        "1212",
        "2002",
    };
    string target = "0202";
    int ans = solution -> openLock(deadends, target);
    cout << ans << endl;
}
/*************************************************
Author: wenhaofang
Date: 2022-02-14
Description: leetcode71 - Simplify Path
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
 * 方法一：暴力模拟
 * 
 * 理论时间复杂度：O(n)，其中 n 为字符串长度
 * 理论空间复杂度：O(n)，其中 n 为字符串长度
 * 
 * 实际时间复杂度：Runtime: 4 ms, faster than 89.86% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 8.9 MB, less than 69.73% of C++ online submissions
 */
class Solution {
public:
    string simplifyPath(string path) {
        // 1. 以 `/` 为分隔符切割字符串
        int i = 0;
        int n = path.length();
        string folder;
        vector<string> oldFolders;
        while (i < n) {
            char c = path[i];
            if (c == '/' && folder.length() != 0) {
                if (folder != "/") {
                    oldFolders.emplace_back(folder);
                }
                folder.clear();
            } else {
                folder += c;
                i += 1;
            }
        }
        if (folder != "/") {
            oldFolders.emplace_back(folder);
        }
        // 2. 处理 `.` 和 `..` 的情况
        vector<string> newFolders;
        for (string curFolder: oldFolders) {
            if (curFolder == "/.") {
                continue;
            }
            else if (curFolder == "/..") {
                if (newFolders.size() > 0) {
                    newFolders.pop_back();
                }
                continue;
            }
            else {
                newFolders.emplace_back(curFolder);
            }
        }
        // 3. 返回答案
        string ans;
        for (string curFolder: newFolders) {
            ans  += curFolder;
        }
        if (ans.length() == 0) {
            ans = "/";
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string path = "/home//foo/";
    string ans = solution -> simplifyPath(path);
    cout << ans << endl;
}
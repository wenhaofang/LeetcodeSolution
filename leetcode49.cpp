/*************************************************
Author: wenhaofang
Date: 2022-01-25
Description: leetcode49 - Group Anagrams
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
 * 方法一：哈希映射
 * 
 * 理论时间复杂度：O(nklogk)，其中 n 为字符串数组大小，k 为字符串最大长度
 * 理论空间复杂度：O(nk)，其中 n 为字符串数组大小，k 为字符串最大长度
 * 
 * 实际时间复杂度：Runtime: 28 ms, faster than 93.68% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 19.5 MB, less than 79.75% of C++ online submissions
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 预处理：构造哈希映射
        unordered_map<string, vector<string>> mp;
        for (string & str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        // 主过程：读取哈希映射
        vector<vector<string>> ans;
        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
            ans.emplace_back(iter -> second);
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
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = solution -> groupAnagrams(strs);
    for (vector<vector<string>>::iterator outer_iter = ans.begin(); outer_iter != ans.end(); outer_iter++) {
        for (vector<string>::iterator inner_iter = (*outer_iter).begin(); inner_iter != (*outer_iter).end(); inner_iter++) {
            cout << (*inner_iter) << " ";
        }
        cout << "\n";
    }
}
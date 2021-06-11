/*************************************************
Author: wenhaofang
Date: 2021-06-10
Description: leetcode30 - Substring with Concatenation of All Words
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
using std::pair;
using std::cin;
using std::cout;
using std::endl;

/**
 * 方法一：哈希映射
 * 
 * 实际时间复杂度：Runtime: 280 ms, faster than 47.70% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 26.3 MB, less than 47.14% of C++ online submissions
 */
/**
 * 基本思路
 * 
 * 遍历字符串中所有可能子串，判断每个子串是否包含单词数组中的所有单词
 * 
 * 根据上述思路，需要解决两个问题：
 * 
 * 问题 1：怎么遍历字符串中所有可能子串？
 * 
 * 解决 1：因为子串的长度是固定的，所以按顺序截取子串即可
 * 
 * 举个例子，假如字符串长度为 8，单词数量为 2，单词长度为 3，则截取的子串依次为：(012 345)67、0(123 456)7、01(234 567)
 * 
 * 问题 2：怎么判断子串是否包含单词数组中的所有单词？
 * 
 * 解决 2：利用两个哈希映射进行判断，第一个映射记录单词数组中出现的所有单词及其出现次数，第二个映射记录当前子串中出现的所有单词及其出现次数
 * 
 * 理论上可以先分别构建两个映射再判断两个映射是否相等，实际上为了加速可以在构建第二个映射的同时进行判断
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int str_len = s.length();
        int word_num = words.size();
        int word_len = words[0].length();
        int substr_len = word_num * word_len;
        // 特判
        vector<int> ans;
        if (str_len < substr_len) {
            return ans;
        }
        // 哈希映射 m1 用于统计单词数组中 单词出现次数
        unordered_map<string, int> m1;
        // 遍历单词数组
        for (string word: words) {
            m1[word] += 1;
        }
        // 哈希映射 m2 用于统计字符子串中 单词出现次数
        unordered_map<string, int> m2;
        // 遍历字符子串
        for (int i = 0; i <= str_len - substr_len; i += 1) {
            bool isMatch = true;
            // 遍历字符子串中的每个单词
            for (int j = i; j <= i + substr_len - word_len; j += word_len) {
                // 如果字符子串中出现的单词 在 m1 中出现的次数为零
                // 则说明子串不符合要求，将 isMatch 设置为 false，并跳出当前循环
                string word = s.substr(j, word_len);
                if (m1[word] == 0) {
                    isMatch = false;
                    break;
                } else {
                    // 如果字符子串中出现的单词 在 m1 中出现的次数小于其在子串中出现的次数
                    // 则说明子串不符合要求，将 isMatch 设置为 false，并跳出当前循环
                    m2[word] += 1;
                    if (m1[word] < m2[word]) {
                        isMatch = false;
                        break;
                    }
                }
            }
            // 若 isMatch 为 true，则说明当前子串符合要求，将其加入答案数组
            if (isMatch) {
                ans.push_back(i);
            }
            // 在遍历下一个子串前，清空 m2
            m2.clear();
        }
        // 返回结果
        return ans;
    }
};

/**
 * 方法二：滑动窗口
 * 
 * 实际时间复杂度：Runtime: 68 ms, faster than 87.85% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 28.7 MB, less than 44.01% of C++ online submissions
 */
/**
 * 进阶思路
 * 
 * 上述思路的问题在于：每次得到一个子串时，都需要重新对其构建哈希映射
 * 
 * 改进思路的核心在于：改变遍历子串的顺序，让前一个子串构建的哈希映射能延续用在下一个子串中
 * 
 * 上述在遍历子串时每次移动一个字母，而改进后将会每次移动一个单词，这样能保留之前单词的映射关系
 * 
 * 随之而来的是需要指定多个遍历起点，以保证能遍历到所有的子串
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int str_len = s.length();
        int word_num = words.size();
        int word_len = words[0].length();
        int substr_len = word_num * word_len;
        // 特判
        vector<int> ans;
        if (str_len < substr_len) {
            return ans;
        }
        // 哈希映射 m1 用于统计单词数组中 单词出现次数
        unordered_map<string, int> m1;
        // 遍历单词数组
        for (string word: words) {
            m1[word] += 1;
        }
        // 哈希映射 m2 用于统计字符子串中 单词出现次数
        unordered_map<string, int> m2;
        // 遍历所有起点
        for (int i = 0; i < word_len; i++) {
            // 使用滑动窗口算法寻找合适子串，其中，p1 为左指针，p2 为右指针
            int p1 = i;
            int p2 = i;
            while (p2 + word_len <= str_len) {
                string add_word = s.substr(p2, word_len);
                p2 += word_len;
                if (m1[add_word] == 0) {
                    m2.clear();
                    p1 = p2;
                } else {
                    m2[add_word] += 1;
                    while (m1[add_word] < m2[add_word]) {
                        string sub_word = s.substr(p1, word_len);
                        p1 += word_len;
                        m2[sub_word] -= 1;
                    }
                    if (p2 - p1 == substr_len) {
                        ans.push_back(p1);
                        string sub_word = s.substr(p1, word_len);
                        p1 += word_len;
                        m2[sub_word] -= 1;
                    }
                }
            }
            // 在遍历下一个起点前，清空 m2 
            m2.clear();
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
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> ans = solution->findSubstring(s, words);
    for (auto item: ans) {
        cout << item << " ";
    }
}
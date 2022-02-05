/*************************************************
Author: wenhaofang
Date: 2022-02-11
Description: leetcode68 - Text Justification
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
 * 理论时间复杂度：O(m)，其中 m 为数组中所有字符串的长度之和
 * 理论空间复杂度：O(m)，其中 m 为数组中所有字符串的长度之和
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 7.3 MB, less than 81.88% of C++ online submissions
 */
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size(); // 表示所有要处理的单词数量
        vector<string> ans;   // 储存每一行的字符串，也即答案
        vector<string> tmp;   // 储存当前行的单词组
        int rowLength = 0;    // 表示当前行的常规长度
        int wordIndex = 0;    // 表示当前在处理的单词下标
        // 进入循环，直至处理完所有单词时停止
        while(wordIndex < n) {
            string word = words[wordIndex];
            int tmpLength = word.length();
            if (rowLength + tmpLength + (rowLength == 0 ? 0 : 1) <= maxWidth) {
                // 如果当前在处理的单词能够加入当前行，则将该单词加入当前行
                rowLength = tmpLength + (rowLength == 0 ? 0 : 1) + rowLength;
                tmp.emplace_back(word);
                wordIndex += 1;
            } else {
                // 如果当前在处理的单词不能加入当前行，则将当前行转化为正确的格式后加入答案
                int numVector = tmp.size();
                if (numVector == 1) {
                    // 如果当前行只有一个单词，则对齐格式是左端对齐
                    // 意思是单词位于当前行的第一个位置，之后用空白填满整行
                    string row = tmp[0] + string(maxWidth - tmp[0].length(), ' ');
                    ans.emplace_back(row);
                } else {
                    // 如果当前行不只一个单词，则对齐格式是两端对齐
                    string row = "";
                    int blankSlot = numVector - 1;                    // 需要填充空格的位置的数量
                    int blankPNum = maxWidth - rowLength + blankSlot; // 总共可以填充的空格的数量
                    int a = blankPNum / blankSlot; // 每个位置需要有 a 个空格
                    int b = blankPNum % blankSlot; // 前 b 个位置空格数量加一
                    for (int i = 0, j = b; i < numVector; i++, j--) {
                        row += tmp[i];
                        if (i < numVector - 1) {
                            if (j > 0) {
                                row += string(a + 1, ' ');
                            } else {
                                row += string(a, ' ');
                            }
                        }
                    }
                    ans.emplace_back(row);
                }
                // 已经处理完一行，需要将当前行相关的变量清空
                tmp.clear();
                rowLength = 0;
            }
        }
        // 包尾
        // 最后一行的对齐格式是左端对齐
        int numVector = tmp.size();
        if (numVector > 0) {
            string row = "";
            for (int i = 0; i < numVector; i++) {
                row += tmp[i];
                if (i < numVector - 1) {
                    row += " ";
                }
            }
            if (rowLength < maxWidth) {
                row += string(maxWidth - rowLength, ' ');
            }
            ans.emplace_back(row);
        }
        // 返回答案
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<string> words = {"Listen","to","many,","speak","to","a","few."};
    int maxWidth = 6;
    vector<string> ans = solution -> fullJustify(words, maxWidth);
    for (auto item: ans) {
        cout << item << "\n";
    }
}
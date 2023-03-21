/*************************************************
Author: wenhaofang
Date: 2023-03-21
Description: leetcode394 - Decode String
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：栈 (括号)
 * 
 * 理论时间复杂度：O(n)，其中 n 为字符串长度
 * 理论空间复杂度：O(n)，其中 n 为字符串长度
 */

class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        stack<int> num;
        stack<string> str;
        int readN = -1;
        for (char c: s) {
            if ('0' <= c && c <= '9') {
                if (readN == -1) {
                    readN = c - '0';
                } else {
                    readN = readN * 10 + (c - '0');
                }
            }
            if ('a' <= c && c <= 'z') {
                if (readN != -1) {
                    num.push(readN);
                    readN = -1;
                }
                if (str.empty()) {
                    ans += c;
                } else {
                    string s(1, c);
                    str.push(s);
                }
            }
            if (c == '[') {
                if (readN != -1) {
                    num.push(readN);
                    readN = -1;
                }
                string s(1, c);
                str.push(s);
            }
            if (c == ']') {
                int tmpN = num.top();
                num.pop();
                vector<string> tmpS;
                while (str.top() != "[") {
                    tmpS.push_back(str.top());
                    str.pop();
                }
                str.pop();
                string newTmpS = "";
                for (int i = tmpS.size() - 1; i >= 0; i--) {
                    newTmpS += tmpS[i];
                }
                string newNewTmpS = "";
                for (int i = 0; i < tmpN; i++) {
                    newNewTmpS += newTmpS;
                }
                if (str.empty()) {
                    ans += newNewTmpS;
                } else {
                    str.push(newNewTmpS);
                }
            }
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    string s = "3[a]2[bc]";
    string ans = solution -> decodeString(s);
    cout << ans << endl;
}
/*************************************************
Author: wenhaofang
Date: 2023-03-04
Description: leetcode297 - Serialize and Deserialize Binary Tree
*************************************************/

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>

using std::list;
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
using std::atoi;
using std::stoi;
using std::to_string;
using std::cin;
using std::cout;
using std::endl;

/**
 * 方法一：递归
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:
    // 序列化
    // 递归函数：序列化以参数节点为根节点的子树
    string serialize(TreeNode* root) {
        // 边界情况
        // 空指针要记录下来
        if (!root) {
            return "#";
        }
        // 基本情况
        // 前序遍历
        return to_string(root -> val) + "," + 
               serialize(root -> left) + "," +
               serialize(root -> right);
    }

    // 反序列化
    TreeNode* deserialize(string data) {
        // 先转列表
        string temp;
        list<string> dataList;
        for (char& ch: data) {
            if (ch == ',') {
                dataList.push_back(temp);
                temp.clear();
            } else {
                temp += ch;
            }
        }
        if (!temp.empty()) {
            dataList.push_back(temp);
            temp.clear();
        }
        // 进入递归
        return my_deserialize(dataList);
    }

    // 递归函数：构造以参数列表第一个元素为根节点的子树，注意参数列表是动态变化的
    TreeNode*  my_deserialize(list<string>& dataList) {
        // 边界情况
        if (dataList.front() == "#") {
            dataList.erase(dataList.begin());
            return nullptr;
        }
        // 基本情况
        TreeNode* root = new TreeNode(stoi(dataList.front()));
        dataList.erase(dataList.begin());
        root -> left = my_deserialize(dataList);
        root -> right = my_deserialize(dataList);
        return root;
    }
};

/**
 * 测试
 */
int main() {
    Codec* codec = new Codec();
    TreeNode* n34 = new TreeNode(5);
    TreeNode* n33 = new TreeNode(4);
    TreeNode* n22 = new TreeNode(3, n33, n34);
    TreeNode* n21 = new TreeNode(2);
    TreeNode* n11 = new TreeNode(1, n21, n22);
    string data = codec -> serialize(n11);
    TreeNode* r11 = codec -> deserialize(data);
}
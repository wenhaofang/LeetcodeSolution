/*************************************************
Author: wenhaofang
Date: 2021-07-04
Description: Backtrack
*************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::cout;

/**
 * 回溯概述
 * 
 * 使用场景：搜索所有可能的情况
 * 
 * 核心要点：选择路径、选择列表、剪枝条件、结束条件
 */

/**
 * 模板 1：排列 (数组不含重复元素)
 */
class Permutation {
public:
    vector<vector<int>> solution(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        bool* map = new bool[nums.size()]();
        backtrack(ans, cur, nums, map);
        return ans;
    }

    void backtrack(
        vector<vector<int>>& ans, // 所有答案
        vector<int>& cur,         // 选择路径
        vector<int>& nums,        // 选择列表
        bool* map                 // 辅助剪枝
    ) {
        // 结束条件
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        // 遍历选择列表
        for (int i = 0; i < nums.size(); i++) {
            // 剪枝条件
            if (map[i] == true) {
                continue;
            }
            // 做出选择
            cur.push_back(nums[i]);
            map[i] = true;
            // 递归
            backtrack(ans, cur, nums, map);
            // 撤销选择
            cur.pop_back();
            map[i] = false;
        }
    }
};

/**
 * 模板 1：排列 (数组含有重复元素)
 */
class PermutationUnique {
public:
    vector<vector<int>> solution(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        bool* map = new bool[nums.size()]();
        sort(nums.begin(), nums.end());
        backtrack(ans, cur, nums, map);
        return ans;
    }

    void backtrack(
        vector<vector<int>>& ans, // 所有答案
        vector<int>& cur,         // 选择路径
        vector<int>& nums,        // 选择列表
        bool* map                 // 辅助剪枝
    ) {
        // 结束条件
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        // 遍历选择列表
        for (int i = 0; i < nums.size(); i++) {
            // 剪枝条件
            if (
                (map[i] == true) ||
                (i > 0 && nums[i] == nums[i - 1] && map[i - 1] == false)
            ) {
                continue;
            }
            // 做出选择
            cur.push_back(nums[i]);
            map[i] = true;
            // 递归
            backtrack(ans, cur, nums, map);
            // 撤销选择
            cur.pop_back();
            map[i] = false;
        }
    }
};

/**
 * 模板 2：组合 (数组不含重复元素)
 */
class Combination {
public:
    vector<vector<int>> solution(vector<int>& nums, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(ans, cur, nums, n, 0);
        return ans;
    }

    void backtrack(
        vector<vector<int>>& ans, // 所有答案
        vector<int>& cur,         // 选择路径
        vector<int>& nums,        // 选择列表
        int n,                    // 路径长度
        int begin                 // 辅助剪枝
    ) {
        // 结束条件
        if (cur.size() == n) {
            ans.push_back(cur);
            return;
        }
        // 剪枝条件
        if (cur.size() + nums.size() - begin < n) {
            return;
        }
        // 遍历选择列表
        for (int i = 0; i < nums.size(); i++) {
            // 剪枝条件
            if (i < begin) {
                continue;
            }
            // 做出选择
            cur.push_back(nums[i]);
            // 递归
            backtrack(ans, cur, nums, n, i + 1);
            // 撤销选择
            cur.pop_back();
        }
    }
};

/**
 * 模板 2：组合 (数组含有重复元素)
 */
class CombinationUnique {
public:
    vector<vector<int>> solution(vector<int>& nums, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        backtrack(ans, cur, nums, n, 0);
        return ans;
    }

    void backtrack(
        vector<vector<int>>& ans, // 所有答案
        vector<int>& cur,         // 选择路径
        vector<int>& nums,        // 选择列表
        int n,                    // 路径长度
        int begin                 // 辅助剪枝
    ) {
        // 结束条件
        if (cur.size() == n) {
            ans.push_back(cur);
            return;
        }
        // 剪枝条件
        if (cur.size() + nums.size() - begin < n) {
            return;
        }
        // 遍历选择列表
        for (int i = 0; i < nums.size(); i++) {
            // 剪枝条件
            if (
                (i < begin) ||
                (i > begin && nums[i] == nums[i - 1])
            ) {
                continue;
            }
            // 做出选择
            cur.push_back(nums[i]);
            // 递归
            backtrack(ans, cur, nums, n, i + 1);
            // 撤销选择
            cur.pop_back();
        }
    }
};

/**
 * 模板 3：子集 (数组不含重复元素)
 */
class Subset {
public:
    vector<vector<int>> solution(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(ans, cur, nums, 0);
        return ans;
    }

    void backtrack(
        vector<vector<int>>& ans, // 所有答案
        vector<int>& cur,         // 选择路径
        vector<int>& nums,        // 选择列表
        int begin                 // 辅助剪枝
    ) {
        // 结束条件：无
        ans.push_back(cur);
        // 遍历选择列表
        for (int i = 0; i < nums.size(); i++) {
            // 剪枝条件
            if (i < begin) {
                continue;
            }
            // 做出选择
            cur.push_back(nums[i]);
            // 递归
            backtrack(ans, cur, nums, i + 1);
            // 撤销选择
            cur.pop_back();
        }
    }
};

/**
 * 模板 3：子集 (数组含有重复元素)
 */
class SubsetUnique {
public:
    vector<vector<int>> solution(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        backtrack(ans, cur, nums, 0);
        return ans;
    }

    void backtrack(
        vector<vector<int>>& ans, // 所有答案
        vector<int>& cur,         // 选择路径
        vector<int>& nums,        // 选择列表
        int begin                 // 辅助剪枝
    ) {
        // 结束条件：无
        ans.push_back(cur);
        // 遍历选择列表
        for (int i = 0; i < nums.size(); i++) {
            // 剪枝条件
            if (
                (i < begin) ||
                (i > begin && nums[i] == nums[i - 1])
            ) {
                continue;
            }
            // 做出选择
            cur.push_back(nums[i]);
            // 递归
            backtrack(ans, cur, nums, i + 1);
            // 撤销选择
            cur.pop_back();
        }
    }
};

/**
 * 测试
 */
void print(vector<int>& vec) {
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
        cout << (*iter) << " ";
    }
    cout << "\n";
}

void print(vector<vector<int>>& vec) {
    for (vector<vector<int>>::iterator outer_iter = vec.begin(); outer_iter != vec.end(); outer_iter++) {
        for (vector<int>::iterator inner_iter = (*outer_iter).begin(); inner_iter != (*outer_iter).end(); inner_iter++) {
            cout << (*inner_iter) << " ";
        }
        cout << "\n";
    }
}

int main() {
    Permutation* permutation = new Permutation();
    Combination* combination = new Combination();
    Subset* subset = new Subset();
    PermutationUnique* permutationUnique = new PermutationUnique();
    CombinationUnique* combinationUnique = new CombinationUnique();
    SubsetUnique* subsetUnique = new SubsetUnique();

    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {1, 1, 2, 3};
    int m = 2;
    int n = 3;

    vector<vector<int>> ans1 = permutation -> solution(nums1);
    vector<vector<int>> ans2 = combination -> solution(nums1, m);
    vector<vector<int>> ans3 = subset -> solution(nums1);
    vector<vector<int>> ans4 = permutationUnique -> solution(nums2);
    vector<vector<int>> ans5 = combinationUnique -> solution(nums2, n);
    vector<vector<int>> ans6 = subsetUnique -> solution(nums2);

    cout << "===== Origin Data =====\n";
    print(nums1);
    cout << "===== Permutation =====\n";
    print(ans1);
    cout << "===== Combination =====\n";
    print(ans2);
    cout << "=======  Subset =======\n";
    print(ans3);
    cout << "===== Origin Data =====\n";
    print(nums2);
    cout << "===== Permutation =====\n";
    print(ans4);
    cout << "===== Combination =====\n";
    print(ans5);
    cout << "=======  Subset =======\n";
    print(ans6);
}
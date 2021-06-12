/*************************************************
Author: wenhaofang
Date: 2021-06-12
Description: leetcode31 - Next Permutation
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
 * 方法一：背景规则
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 12.1 MB, less than 33.89% of C++ online submissions
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 特判
        int n = nums.size();
        if (n <= 1) {
            return;
        }
        // 从右往左寻找第一个不符合升序排列的数 a
        // 例如：4 [2] 5 3 1
        int a = -1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                a = i - 1;
                break;
            }
        }
        // 如果没找到，则说明该数组已经是最大的排列，直接反转整个数组
        // 如果能找到，则继续执行以下步骤
        if (a != -1) {
            // 从右往左寻找第一个大于 a 的数 b
            // 例如：4 2 5 [3] 1
            int b = -1;
            for (int i = n - 1; i > a; i--) {
                if (nums[i] > nums[a]) {
                    b = i;
                    break;
                }
            }
            // 交换 a 和 b
            // 例如：4 [2] 5 [3] 1 -> 4 [3] 5 [2] 1
            int num_a = nums[a];
            int num_b = nums[b];
            nums[a] = num_b;
            nums[b] = num_a;
        }
        // 反转 a 以后的数
        // 例如：4 3 (5 2 1) -> 4 3 (1 2 5)
        int p1 = a + 1;
        int p2 = n - 1;
        while (p1 < p2) {
            int num_p1 = nums[p1];
            int num_p2 = nums[p2];
            nums[p1] = num_p2;
            nums[p2] = num_p1;
            p1++;
            p2--;
        }
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {1, 2, 3};
    solution -> nextPermutation(nums);
    for (auto item: nums) {
        cout << item << " ";
    }
}
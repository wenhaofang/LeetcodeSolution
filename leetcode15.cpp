/*************************************************
Author: wenhaofang
Date: 2021-03-20
Description: leetcode15 - 3Sum
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
 * 思路一：双指针 (简单易懂版)
 * 
 * 时间复杂度：O(n^2)，其中 n 为数组大小
 * 空间复杂度：O(logn)，其中 n 为数组大小
 * 
 * 实际时间复杂度：Runtime: 76 ms, faster than 78.88% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 20.1 MB, less than 76.22% of C++ online submissions
 */
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> ans;
//         // 数组排序
//         sort(nums.begin(), nums.end());
//         // 遍历数组，若将 -nums[i] 作为 target，则此题转换为 Two Sum
//         for (int i = 0; i < n; i++) {
//             // 前处理，特殊情况
//             // nums[i] 作为三个数中的最小值，如果 nums[i] > 0，则三数之和不可能为零
//             if (nums[i] > 0) {
//                 break;
//             }
//             // 前处理，特殊情况
//             // 由于题目要求三元组不重复，所以指针 i 直接移动到下一个不相同的数
//             if (i != 0 && nums[i] == nums[i - 1]) {
//                 continue;
//             }
//             // 指针 j 初始化在数组始端，指针 k 初始化在数组末端
//             int j = i + 1;
//             int k = n - 1;
//             // 双指针向数组中间移动，直至相遇
//             while (j < k) {
//                 int sum = nums[i] + nums[j] + nums[k];
//                 if (sum == 0) {
//                     // 如果三数之和等于零
//                     // 那么此时找到一组解，将其加入 ans
//                     ans.push_back({nums[i], nums[j], nums[k]});
//                     // 并且指针 j 向右移动，直至遇到第一个不相同的数或到达 n
//                     // 同时指针 k 向左移动，直至遇到第一个不相同的数或到达 i
//                     while (++j < n && nums[j] == nums[j - 1]);
//                     while (--k > i && nums[k] == nums[k + 1]);
//                 } else if (sum < 0) {
//                     // 如果三数之和小于零
//                     // 那么指针 j 向右移动，直至遇到第一个不相同的数或到达 n
//                     while (++j < n && nums[j] == nums[j - 1]);
//                 } else if (sum > 0) {
//                     // 如果三数之和大于零
//                     // 那么指针 k 向左移动，直至遇到第一个不相同的数或到达 i
//                     while (--k > i && nums[k] == nums[k + 1]);
//                 }
//             }
//         }
//         return ans;
//     }
// };

/**
 * 思路二：双指针 (修改加速版)
 * 
 * 时间复杂度：O(n^2)，其中 n 为数组大小
 * 空间复杂度：O(logn)，其中 n 为数组大小
 * 
 * 实际时间复杂度：Runtime: 48 ms, faster than 99.14% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 19.9 MB, less than 89.41% of C++ online submissions
 */
class Solution {
public:
    // 解题过程中需要多次从 vector 中访问相同元素值 numI、numJ、numK
    // 因此可以将该值保存下来，加速后续访问
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int numI = nums[i];
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int numJ = nums[j];
                int numK = nums[k];
                int sum = numI + numJ + numK;
                if (sum == 0) {
                    ans.push_back({numI, numJ, numK});
                    while (++j < n && nums[j] == numJ);
                    while (--k > i && nums[k] == numK);
                } else if (sum < 0) {
                    while (++j < n && nums[j] == numJ);
                } else if (sum > 0) {
                    while (--k > i && nums[k] == numK);
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
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = solution->threeSum(nums);
    for (vector<vector<int>>::iterator iter_outer = ans.begin(); iter_outer != ans.end(); iter_outer++) {
        for (vector<int>::iterator iter_inner = (*iter_outer).begin(); iter_inner != (*iter_outer).end(); iter_inner++) {
            cout << (*iter_inner) << " ";
        }
        cout << endl;
    }
}
/*************************************************
Author: wenhaofang
Date: 2023-03-12
Description: leetcode152 - Maximum Product Subarray
*************************************************/

#include  <bits/stdc++.h>
using namespace std;

/**
 * 方法一：动态规划 / 剪枝角度
 * 
 * 理论时间复杂度：O(n)，其中 n 为数组大小
 * 理论空间复杂度：O(n)，其中 n 为数组大小
 */
/**
 * 思路
 * 
 * 首先试一下动态规划的思路，dp[n] = max{ dp[n - 1] * nums[n], nums[n] }
 * 
 * 但是当数组中有负数时不满足最优子结构
 * 
 * 例如 [-2, 3, -2]，此时 dp[1] = max{-6, 3} = 3，但实际上当 dp[1] = -6 时 dp[2] 会有最大值 12
 * 
 * 画出搜索树，对于 [a1, a2, a3, a4, ...]
 * 
 * 1. 以 a1 结尾的可能一种：a1
 * 
 * 2. 以 a2 结尾的可能两种：a1 * a2 ，a2
 * 
 * 3. 以 a3 结尾的可能三种：a1 * a2 * a3 ，a2 * a3 ，a3
 * 
 * 4. 以 a4 结尾的可能四种：a1 * a2 * a3 * a4 ，a2 * a3 * a4 ，a3 * a4 ，a4
 * 
 * 5. ...
 * 
 * 若要使得以当前元素结尾的序列取最大值，要且只要知道上一个元素的负数最大值和正数最大值 (这里指绝对值最大)
 * 
 * 根据这一想法可以对搜索树剪枝，即每步只保留两个数即可，这有点像维特比算法
 * 
 * 另外为了统一处理，可以给负数最大值和正数最大值默认值设置为零
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 特判
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        // 剪枝
        int ans = INT_MIN;
        int minVal = 0; // 负数最大值
        int maxVal = 0; // 正数最大值
        for (int num: nums) {
            int minTmp = min(num, min(num * minVal, num * maxVal));
            int maxTmp = max(num, max(num * minVal, num * maxVal));
            minVal = minTmp;
            maxVal = maxTmp;
            ans = max(ans, maxTmp);
        }
        return ans;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums = {2, 3, -2, 4};
    int ans = solution -> maxProduct(nums);
    cout << ans << endl;
}
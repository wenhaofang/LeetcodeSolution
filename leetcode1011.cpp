/*************************************************
Author: wenhaofang
Date: 2022-12-04
Description: leetcode1011 - Capacity To Ship Packages Within D Days
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
 * 方法一：二分查找
 * 
 * 理论时间复杂度：O(nlogm)，其中 n 为数组大小，m 为数组总和
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 42 ms, faster than 98.65% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 26 MB, less than 66.49% of C++ online submissions
 */

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int p1 = 0;
        int p2 = 0;
        for (int weight: weights) {
            p1 = max(p1, weight);
            p2 = p2 + weight;
        }
        while (p1 <= p2) {
            int mid = p1 + (p2 - p1) / 2;
            int tmp = getTime(weights, mid);
            if (tmp == days) {
                p2 = mid - 1;
            } else if (tmp < days) {
                p2 = mid - 1;
            } else if (tmp > days) {
                p1 = mid + 1;
            }
        }
        return p1;
    }

    int getTime(vector<int>& weights, int capacity) {
        int curr = 0;
        int need = 1;
        for (int weight: weights) {
            if (curr + weight > capacity) {
                curr = 0;
                need = need + 1;
            }
            curr = curr + weight;
        }
        return need;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    int ans = solution -> shipWithinDays(weights, days);
    cout << ans << "\n";
}
/*************************************************
Author: wenhaofang
Date: 2022-12-04
Description: leetcode875 - Koko Eating Bananas
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
 * 理论时间复杂度：O(nlogm)，其中 n 为数组大小，m 为数组中最大值
 * 理论空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 31 ms, faster than 99.82% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 19 MB, less than 34.56% of C++ online submissions
 */

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int p1 = 1;
        int p2 = 0;
        for (int pile: piles) {
            p2 = max(p2, pile);
        }
        while (p1 <= p2) {
            int mid = p1 + (p2 - p1) / 2;
            long long int tmp = getTime(piles, mid);
            if (tmp == h) {
                p2 = mid - 1;
            } else if (tmp < h) {
                p2 = mid - 1;
            } else if (tmp > h) {
                p1 = mid + 1;
            }
        }
        return p1;
    }

    long long int getTime(vector<int>& piles, int speed) {
        long long int time = 0;
        for (int pile: piles) {
            time += (pile + speed - 1) / speed; // 相当于 plie / speed 向上取整
        }
        return time;
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    int ans = solution -> minEatingSpeed(piles, h);
    cout << ans << "\n";
}
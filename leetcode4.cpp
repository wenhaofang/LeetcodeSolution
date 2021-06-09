/*************************************************
Author: wenhaofang
Date: 2021-03-07
Description: leetcode4 - Median of Two Sorted Arrays
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
 * 思路一：归并
 * 
 * 时间复杂度：O(m + n)，其中 m、n 分别为两个数组的大小
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 24 ms, faster than 93.13% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 89 MB, less than 84.97% of C++ online submissions
 */
/**
 * 基础思路
 * 
 * 使用归并算法合并两个数组，得到有序数组之后直接取中位数即可
 * 如果两数组共有奇数个元素，则中位数下标为 (m + n) / 2
 * 如果两数组共有偶数个元素，则中位数下标为 (m + n) / 2 和 ((m + n) / 2) - 1
 */
/**
 * 进阶思路
 * 
 * 由于两个数组长度已知，所以其中位数的下标也是确定的
 * 因此可以维护两个指针，初始时分别指向两个数组的第一个元素
 * 之后每次将指向较小值的指针向右移动一位，直至到达中位数的下标即可
 */
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size(), n = nums2.size();
//         // i: 指向 nums1 数组的指针，初始化指向该数组的第一个元素
//         // j: 指向 nums2 数组的指针，初始化指向该数组的第一个元素
//         // k: 用于表示当前数字的下标值，每次加一直至等于 (m + n) / 2
//         int i = 0, j = 0, k = 0;
//         // 由于两数组的总元素个数可能是奇数个，也可能是偶数个
//         // 因此使用两个数字保存指针指向的最后两位，即 (m + n) / 2 和 ((m + n) / 2) - 1
//         int arr[2] = {0, 0};
//         // 如果 i、j 指针都未到达数组末尾，则将指向较小值的指针向右移动一位
//         // 并且 k 每次加一直至等于 (m + n) / 2
//         while (i < m && j < n && k < (m + n) / 2 + 1) {
//             if (nums1[i] < nums2[j]) {
//                 arr[k++ % 2] = nums1[i++];
//             } else {
//                 arr[k++ % 2] = nums2[j++];
//             }
//         }
//         // 此时 j 指针已经到达数组末尾，之后只需移动 i 指针即可
//         // 并且 k 每次加一直至等于 (m + n) / 2
//         while (i < m && k < (m + n) / 2 + 1) {
//             arr[k++ % 2] = nums1[i++];
//         }
//         // 此时 i 指针已经到达数组末尾，之后只需移动 j 指针即可
//         // 并且 k 每次加一直至等于 (m + n) / 2
//         while (j < n && k < (m + n) / 2 + 1) {
//             arr[k++ % 2] = nums2[j++];
//         }
//         // 计算中位数
//         if ((m + n) % 2 != 0) {
//             // 若两数组的总元素个数是奇数，则中位数只有一个
//             return arr[(k - 1) % 2] / 1.0;
//         } else {
//             // 若两数组的总元素个数是偶数，则中位数会有两个
//             return (arr[0] + arr[1]) / 2.0;
//         }
//     }
// };

/**
 * 思路二：二分查找
 * 
 * 时间复杂度：O(log(m + n))，其中 m、n 分别为两个数组的大小
 * 空间复杂度：O(1)
 * 
 * 实际时间复杂度：Runtime: 20 ms, faster than 97.28% of C++ online submissions
 * 实际空间复杂度：Memory Usage: 88.8 MB, less than 95.42% of C++ online submissions
 */
class Solution {
public:
    /**在两个有序数组中查找第 k 小元素 (k > 1)
     * 首先计算 pivot1 = nums1[k/2 - 1] 以及 pivot2 = nums2[k/2 - 1]
     * 那么，在 nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2 - 2] 共计 k/2 - 1 个
     * 同理，在 nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2 - 2] 共计 k/2 - 1 个
     * 取 pivot = min(pivot1, pivot2)，则两个数组中小于等于 pivot 的元素不会超过 k - 2 个，而 pivot 最大也只是第 k - 1 小
     * 如果 pivot == pivot1，那么 nums1[0 .. k/2 - 1] 都不可能是第 k 小的元素，把这些元素 “删除”，剩下的元素作为 nums1
     * 如果 pivot == pivot2，那么 nums2[0 .. k/2 - 1] 都不可能是第 k 小的元素，把这些元素 “删除”，剩下的元素作为 nums2
     * 由于部分元素被 “删除”，而这些元素都小于第 k 小的元素，所以 k 的值需要更新，即减去 “删除” 的元素个数
     * 将更新后的 nums1、nums2、k 重新代入上述计算过程，直至 k == 1
     */
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        // i: 用于标识 nums1 数组的起始位置（起始位置的偏移量）
        // j: 用于标识 nums2 数组的起始位置（起始位置的偏移量）
        int i = 0, j = 0;
        // 进入循环
        while (true) {
            // 边界条件：此时 nums1 已经耗尽，故直接取 nums2 中第 k 小的元素即可
            if (i == m) {
                return nums2[j + k - 1];
            }
            // 边界条件：此时 nums2 已经耗尽，故直接取 nums1 中第 k 小的元素即可
            if (j == n) {
                return nums1[i + k - 1];
            }
            // 边界条件：返回两个有序数组中第 1 小的元素
            if (k == 1) {
                return min(nums1[i], nums2[j]);
            }
            // 计算 pivot1、pivot2
            int ii = min(i + k / 2 - 1, m - 1);
            int jj = min(j + k / 2 - 1, n - 1);
            int pivot1 = nums1[ii];
            int pivot2 = nums2[jj];
            // 更新 nums1、nums2、k
            if (pivot1 <= pivot2) {
                k = k - (ii - i + 1);
                i = ii + 1;
            } else {
                k = k - (jj - j + 1);
                j = jj + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int length = nums1.size() + nums2.size();
        if (length % 2 != 0) {
            return  getKthElement(nums1, nums2, length / 2 + 1) / 1.0;
        } else {
            return (getKthElement(nums1, nums2, length / 2 + 1) + getKthElement(nums1, nums2, length / 2)) / 2.0;
        }
    }
};

/**
 * 测试
 */
int main() {
    Solution* solution = new Solution();
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double ans = solution->findMedianSortedArrays(nums1, nums2);
    cout << ans << endl;
}
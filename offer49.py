'''
Author: wenhaofang
Date: 2023-04-25
Description: offer49 - 丑数
'''

import collections
import functools

'''思路一：动态规划

时间复杂度: O(n^2)
空间复杂度: O(n)
'''

# class Solution(object):
#     def nthUglyNumber(self, n):
#         """
#         :type n: int
#         :rtype: int
#         """
#         dp = [float('inf') for _ in range(n)]
#         dp[0] = 1
#         for i in range(1, n):
#             for j in range(0, i):
#                 if  dp[j] * 2 > dp[i - 1]:
#                     dp[i] = min(dp[i], dp[j] * 2)
#                 if  dp[j] * 3 > dp[i - 1]:
#                     dp[i] = min(dp[i], dp[j] * 3)
#                 if  dp[j] * 5 > dp[i - 1]:
#                     dp[i] = min(dp[i], dp[j] * 5)
#         return  dp[n - 1]

'''思路二：动态规划 + 剪枝

时间复杂度: O(n)
空间复杂度: O(n)
'''

class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [float('inf') for _ in range(n)]
        dp[0] = 1
        x = 0
        y = 0
        z = 0
        for i in range(1, n):
            num2 = dp[x] * 2
            num3 = dp[y] * 3
            num5 = dp[z] * 5
            dp[i] = min(num2, num3, num5)
            if dp[i] == num2: x += 1
            if dp[i] == num3: y += 1
            if dp[i] == num5: z += 1
        return dp[n - 1]

if  __name__ == '__main__':
    solution = Solution()
    n = 10
    result = solution.nthUglyNumber(n)
    print(result)

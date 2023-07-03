'''
Author: wenhaofang
Date: 2023-07-03
Description: offer60 - n个骰子的点数
'''

import collections
import functools

'''思路一：动态规划

时间复杂度: O(n^2)，其中 n 为给定数字
空间复杂度: O(n^2)，其中 n 为给定数字
'''

class Solution(object):
    def dicesProbability(self, n):
        """
        :type n: int
        :rtype: List[float]
        """
        dp = [[0 for _ in range(n * 6 + 1)] for _ in range(n + 1)]

        for i in range(1, 2):
            for j in range(i, i * 6 + 1):
                dp[i][j] += 1

        for i in range(2, n + 1):
            for j in range(i, i * 6 + 1):
                for k in range(1, 6 + 1):
                    if  j >= k:
                        dp[i][j] += dp[i - 1][j - k]

        ans = []
        for i in range(n, n + 1):
            for j in range(i, i * 6 + 1):
                ans.append(dp[i][j] * 1.0 / 6**n)

        return ans

if  __name__ == '__main__':
    solution = Solution()
    n = 1
    result = solution.dicesProbability(n)
    print(result)

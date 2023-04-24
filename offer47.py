'''
Author: wenhaofang
Date: 2023-04-24
Description: offer47 - 礼物的最大价值
'''

import collections
import functools

'''思路一：动态规划

时间复杂度: O(mn)，其中 m、n 分别为矩阵的宽和高
空间复杂度: O(mn)，其中 m、n 分别为矩阵的宽和高
'''

class Solution(object):
    def maxValue(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]
        dp[0][0] = grid[0][0]
        for i in range(1, m):
            dp[i][0] = dp[i - 1][0] + grid[i][0]
        for j in range(1, n):
            dp[0][j] = dp[0][j - 1] + grid[0][j]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
        return dp[m - 1][n - 1]

if  __name__ == '__main__':
    solution = Solution()
    grid = [
        [1, 3, 1],
        [1, 5, 1],
        [4, 2, 1],
    ]
    result = solution.maxValue(grid)
    print(result)

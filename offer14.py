'''
Author: wenhaofang
Date: 2023-04-20
Description: offer14 - 剪绳子
'''

'''思路一：动态规划

时间复杂度: O(n^2)，其中 n 为数组大小
空间复杂度: O(n)  ，其中 n 为数组大小
'''

class Solution(object):
    def cuttingRope(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0 for _ in range(n + 1)]
        dp[2] = 1
        for i in range(3, n + 1):
            for j in range(1, i):
                dp[i] = max(dp[i], dp[j] * (i - j), j * (i - j))
        return dp[n] # 大数取余

if  __name__ == '__main__':
    solution = Solution()
    n = 3
    result = solution.cuttingRope(n)
    print(result)

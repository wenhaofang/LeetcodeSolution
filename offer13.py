'''
Author: wenhaofang
Date: 2023-04-19
Description: offer13 - 机器人的运动范围
'''

'''思路一：深度优先搜索

时间复杂度: O(mn)
空间复杂度: O(mn)
'''

class Solution(object):
    def movingCount(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        self.re = 0
        self.vi = set()
        self.di = dict()
        for i in range(max(m, n)):
            a = i
            b = 0
            while a != 0:
                b = b + a % 10
                a = a // 10
            self.di[i] = b

        self.dfs(m, n, k, 0, 0)
        return self.re

    def dfs(self, m, n, k, i, j):
        if  (
            0 <= i <= m - 1 and
            0 <= j <= n - 1 and
            self.di[i] + self.di[j] <= k and (i, j) not in self.vi
        ):
            self.re += 1
            self.vi.add((i, j))
            self.dfs(m, n, k, i + 1, j)
            self.dfs(m, n, k, i - 1, j)
            self.dfs(m, n, k, i, j + 1)
            self.dfs(m, n, k, i, j + 1)

if  __name__ == '__main__':
    solution = Solution()
    m = 2
    n = 3
    k = 1
    result = solution.movingCount(m, n, k)
    print(result)

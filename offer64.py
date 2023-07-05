'''
Author: wenhaofang
Date: 2023-07-05
Description: offer64 - 求1+2+…+n
'''

import collections
import functools

'''思路一：递归

时间复杂度: O(n)，其中 n 为给定数字
空间复杂度: O(n)，其中 n 为给定数字
'''

class Solution(object):
    def sumNums(self, n):
        """
        :type n: int
        :rtype: int
        """
        if  n == 0:
            return 0
        else:
            return n + self.sumNums(n - 1)

if  __name__ == '__main__':
    solution = Solution()
    n = 3
    result = solution.sumNums(n)
    print(result)

'''
Author: wenhaofang
Date: 2023-07-06
Description: offer66 - 构建乘积数组
'''

import collections
import functools

'''思路一：预处理

时间复杂度: O(n)，其中 n 为数组大小
空间复杂度: O(n)，其中 n 为数组大小
'''

class Solution(object):
    def constructArr(self, a):
        """
        :type a: List[int]
        :rtype: List[int]
        """
        lll = 0
        rrr = len(a) - 1
        l2r = [1] * len(a)
        r2l = [1] * len(a)
        res = [1] * len(a)
        for i in range(lll + 1, rrr + 1, +1):
            l2r[i] = l2r[i - 1] * a[i - 1]
        for i in range(rrr - 1, lll - 1, -1):
            r2l[i] = r2l[i + 1] * a[i + 1]
        for i in range(lll, rrr + 1):
            res[i] = l2r[i] * r2l[i]
        return res

if  __name__ == '__main__':
    solution = Solution()
    a = [1, 2, 3, 4, 5]
    result = solution.constructArr(a)
    print(result)

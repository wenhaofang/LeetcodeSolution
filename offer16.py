'''
Author: wenhaofang
Date: 2023-04-20
Description: offer16 - 数值的整数次方
'''

'''思路一：快速幂

时间复杂度: O(logn)
空间复杂度: O(logn)
'''

class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        return self.quickMul(x, n) if n >= 0 else 1.0 / self.quickMul(x, -n)

    def quickMul(self, x, n):
        if  n == 0:
            return 1.0
        y = self.quickMul(x, n // 2)
        return y * y if n % 2 == 0 else y * y * x

if  __name__ == '__main__':
    solution = Solution()
    x = 2.00000
    n = 10
    result = solution.myPow(x, n)
    print(result)

'''
Author: wenhaofang
Date: 2023-04-24
Description: offer44 - 数字序列中某一位的数字
'''

import collections

'''思路一：数学

时间复杂度: O(logn)
空间复杂度: O(logn)
'''

class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        bits = []
        nums = []
        sums = []
        '''      bit  num
        0         1     1
        1-9       1     9
        10-99     2    90
        100-999   3   900
        1000-9999 4  9000
        '''
        bits.append(1)
        nums.append(1)
        sums.append(1)

        bits.append(1)
        nums.append(9)
        sums.append(sums[-1] + bits[-1] * nums[-1])

        while True:
            if  sums[-1] >= n:
                break
            bits.append(bits[-1] + 1)
            nums.append(nums[-1] * 10)
            sums.append(sums[-1] + bits[-1] * nums[-1])

        base = 10**(bits[-1] - 1)

        offs = n - sums[-2]

        cnum = str(base + offs // bits[-1])

        cbit = int(cnum[offs % bits[-1]])

        return cbit

if  __name__ == '__main__':
    solution = Solution()
    n = 3
    result = solution.findNthDigit(n)
    print(result)

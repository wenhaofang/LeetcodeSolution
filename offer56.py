'''
Author: wenhaofang
Date: 2023-05-11
Description: offer56 - 数组中数字出现的次数
'''

import collections
import functools

'''思路一：位运算

时间复杂度: O(n)
空间复杂度: O(1)
'''

class Solution(object):
    def singleNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = 0
        for num in nums:
            n ^= num
        m = 1
        while n & m == 0:
            m <<= 1
        x = 0
        y = 0
        for num in nums:
            if  num & m:
                x ^= num
            else:
                y ^= num
        return [x, y]

if  __name__ == '__main__':
    solution = Solution()
    nums = [4, 1, 4, 6]
    result = solution.singleNumbers(nums)
    print(result)

'''
Author: wenhaofang
Date: 2023-07-02
Description: offer56 - 数组中数字出现的次数
'''

import collections
import functools

'''思路一：位运算 I

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

'''思路一：位运算 II

时间复杂度: O(n)
空间复杂度: O(1)
'''

# class Solution(object):
#     def singleNumber(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         bits = [0] * 22
#         for num in nums:
#             tmp = num
#             pos = 0
#             while tmp != 0:
#                 bits[pos] += tmp % 3
#                 tmp //= 3 #!
#                 pos += 1

#         ans = 0
#         tmp = 1
#         for bit in bits:
#             ans += tmp * (bit % 3)
#             tmp *= 3

#         return ans

if  __name__ == '__main__':
    solution = Solution()
    nums = [4, 1, 4, 6]
    result = solution.singleNumbers(nums)
    print(result)

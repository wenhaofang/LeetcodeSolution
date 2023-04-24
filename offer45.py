'''
Author: wenhaofang
Date: 2023-04-24
Description: offer45 - 把数组排成最小的数
'''

import collections
import functools

'''思路一：排序

时间复杂度: 
空间复杂度: 
'''

class Solution(object):
    def minNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        def cmp(s1, s2):
            if  s1 + s2 == s2 + s1:
                return 0
            elif s1 + s2 < s2 + s1:
                return -1
            elif s1 + s2 > s2 + s1:
                return +1

        strs = list(map(str, nums))
        strs.sort(key = functools.cmp_to_key(cmp))
        return ''.join(strs)

if  __name__ == '__main__':
    solution = Solution()
    nums = [10, 2]
    result = solution.minNumber(nums)
    print(result)

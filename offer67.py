'''
Author: wenhaofang
Date: 2023-07-07
Description: offer67 - 把字符串转换成整数
'''

import collections
import functools

'''思路一：暴力模拟

时间复杂度: O(n)，其中 n 为字符串长度
空间复杂度: O(1)
'''

class Solution(object):
    def strToInt(self, str):
        """
        :type str: str
        :rtype: int
        """
        ptr = 0
        pos = 0
        ans = 0
        while (
            ptr < len(str) and str[ptr] == ' '
        ):
            ptr += 1
        if  (
            ptr < len(str) and str[ptr] != '+' and str[ptr] != '-'
        ):
            pos = +1
        elif (
            ptr < len(str) and str[ptr] == '+'
        ):
            pos = +1
            ptr += 1
        elif (
            ptr < len(str) and str[ptr] == '-'
        ):
            pos = -1
            ptr += 1
        while (
            ptr < len(str) and str[ptr].isdigit()
        ):
            ans = ans * 10 + pos * int(str[ptr])
            ptr = ptr + 1
        if  ans >= +2**31 - 1:
            return +2**31 - 1
        if  ans <= -2**31:
            return -2**31
        return ans

if  __name__ == '__main__':
    solution = Solution()
    str = "42"
    result = solution.strToInt(str)
    print(result)

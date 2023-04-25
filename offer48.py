'''
Author: wenhaofang
Date: 2023-04-25
Description: offer48 - 最长不含重复字符的子字符串
'''

import collections
import functools

'''思路一：滑动窗口

时间复杂度: O(n)，其中 n 为字符串长度
空间复杂度: O(n)，其中 n 为字符串长度
'''

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = 0
        map = {}
        lp = 0
        rp = -1
        while True:
            rp += 1
            if  rp >= len(s):
                break
            if  s[rp] not in map or map[s[rp]] < lp:
                map[s[rp]] = rp
                ans = max(ans, rp - lp + 1)
            else:
                lp = map[s[rp]] + 1
                map[s[rp]] = rp
        return  ans

if  __name__ == '__main__':
    solution = Solution()
    s = "abcabcbb"
    result = solution.lengthOfLongestSubstring(s)
    print(result)

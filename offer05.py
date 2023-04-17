'''
Author: wenhaofang
Date: 2023-04-17
Description: offer05 - 替换空格
'''

# import 

'''思路一：正则

时间复杂度: O(n)，其中 n 为字符串长度
空间复杂度: O(1)
'''

class Solution(object):
    def replaceSpace(self, s):
        """
        :type s: str
        :rtype: str
        """
        return s.replace(' ', '%20')

if  __name__ == '__main__':
    solution = Solution()
    s = "We are happy."
    result = solution.replaceSpace(s)
    print(result)

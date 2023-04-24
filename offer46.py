'''
Author: wenhaofang
Date: 2023-04-24
Description: offer46 - 把数字翻译成字符串
'''

import collections
import functools

'''思路一：深度优先搜索

时间复杂度: 
空间复杂度: 
'''

# class Solution(object):
#     def translateNum(self, num):
#         """
#         :type num: int
#         :rtype: int
#         """
#         self.ans = 0
#         self.dfs(str(num), 0)
#         return self.ans

#     def dfs(self, num, i):
#         if  i >= len(num):
#             self.ans += 1
#         if  i <= len(num) - 1 and 0 <= int(num[i]) <= 25:
#             self.dfs(num, i + 1)
#         if  i <= len(num) - 2 and 0 <= int(num[i:i+2]) <= 25 and num[i] != '0':
#             self.dfs(num, i + 2)

'''思路二：动态规划

时间复杂度: O(n)，其中 n 为数字位数
空间复杂度: O(n)，其中 n 为数字位数
'''

class Solution(object):
    def translateNum(self, num):
        """
        :type num: int
        :rtype: int
        """
        num = str(num)
        dp = [0 for _ in range(0, len(num) + 1)]
        dp[0] = 1
        dp[1] = 1
        for i in range(2, len(num) + 1):
            if 10 <= int(num[i - 2: i]) <= 25:
                dp[i] = dp[i - 1] + dp[i - 2]
            else:
                dp[i] = dp[i - 1]
        return  dp[len(num)]

if  __name__ == '__main__':
    solution = Solution()
    num = 12258
    result = solution.translateNum(num)
    print(result)

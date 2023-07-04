'''
Author: wenhaofang
Date: 2023-07-04
Description: offer63 - 股票的最大利润
'''

import collections
import functools

'''思路一：两次遍历

时间复杂度: O(n^2)，其中 n 为数组大小
空间复杂度: O(1)
'''

# class Solution(object):
#     def maxProfit(self, prices):
#         """
#         :type prices: List[int]
#         :rtype: int
#         """
#         ans = 0
#         for i in range(0, len(prices)):
#             for j in range(i + 1, len(prices)):
#                 ans = max(ans, prices[j] - prices[i])
#         return  ans

'''思路二：一次遍历

时间复杂度: O(n)，其中 n 为数组大小
空间复杂度: O(1)
'''

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        currMaxValue = 0
        pastMinValue = float('inf')
        for price in prices:
            currMaxValue = max(currMaxValue, price - pastMinValue)
            pastMinValue = min(pastMinValue, price)
        return currMaxValue

if  __name__ == '__main__':
    solution = Solution()
    prices = [7, 1, 5, 3, 6, 4]
    result = solution.maxProfit(prices)
    print(result)

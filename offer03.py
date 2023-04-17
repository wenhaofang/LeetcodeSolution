'''
Author: wenhaofang
Date: 2023-04-17
Description: offer03 - 数组中重复的数字
'''

# import 

'''思路一：哈希集合

时间复杂度: O(n)，其中 n 为数组大小
空间复杂度: O(n)，其中 n 为数组大小
'''

class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s = set()
        for num in nums:
            if num in s:
                return num
            else:
                s.add(num)

if  __name__ == '__main__':
    solution = Solution()
    nums = [2, 3, 1, 0, 2, 5, 3]
    result = solution.findRepeatNumber(nums)
    print(result)

'''
Author: wenhaofang
Date: 2023-04-17
Description: offer04 - 二维数组中的查找
'''

# import 

'''思路一：二分查找

时间复杂度: 
空间复杂度: 
'''

class Solution(object):
    def findNumberIn2DArray(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix)
        if  m == 0:
            return False
        n = len(matrix[0])
        isFind = self.dfs(matrix, target, 0, 0, m - 1, n - 1)
        return isFind

    def dfs(self, matrix, target, x1, y1, x2, y2):
        m = len(matrix)
        n = len(matrix[0])
        if (
            x1 < 0 or x1 >= m or
            y1 < 0 or y1 >= n or
            x2 < 0 or x2 >= m or
            y2 < 0 or y2 >= n or
            x1 > x2 or
            y1 > y2
        ):
            return False
        xm = (x1 + x2) // 2
        ym = (y1 + y2) // 2
        if  matrix[xm][ym] == target:
            return True
        elif matrix[xm][ym] < target:
            return (
                self.dfs(matrix, target, xm + 1, y1, x2, y2) or
                self.dfs(matrix, target, x1, ym + 1, xm, y2)
            )
        elif matrix[xm][ym] > target:
            return (
                self.dfs(matrix, target, x1, y1, xm - 1, y2) or
                self.dfs(matrix, target, xm, y1, x2, ym - 1)
            )

if  __name__ == '__main__':
    solution = Solution()
    matrix = [
        [1,   4,  7, 11, 15],
        [2,   5,  8, 12, 19],
        [3,   6,  9, 16, 22],
        [10, 13, 14, 17, 24],
        [18, 21, 23, 26, 30],
    ]
    target = 5
    result = solution.findNumberIn2DArray(matrix, target)
    print(result)

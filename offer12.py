'''
Author: wenhaofang
Date: 2023-04-19
Description: offer12 - 矩阵中的路径
'''

'''思路一：回溯

时间复杂度: O(mn * 3^l)，其中 m、n 分别为矩阵的宽和长，并且 l 为字符串的长度
空间复杂度: O(1)
'''

class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        m = len(board)
        if  m == 0 and word == "":
            return True
        if  m == 0 and word != "":
            return False
        n = len(board[0])
        if  n == 0 and word == "":
            return True
        if  n == 0 and word != "":
            return False
        for i in range(m):
            for j in range(n):
                if  self.dfs(board, word, i, j, 0):
                    return True
        return False

    def dfs(self, board, word, i, j, k):
        s = "0"
        m = len(board)
        n = len(board[0])
        if  len(word) == k:
            return True
        if  i < 0 or i >= m or j < 0 or j >= n:
            return False
        if  board[i][j] == word[k]:
            t = board[i][j]
            board[i][j] = s
            r = (
                self.dfs(board, word, i + 1, j, k + 1) or
                self.dfs(board, word, i - 1, j, k + 1) or
                self.dfs(board, word, i, j + 1, k + 1) or
                self.dfs(board, word, i, j - 1, k + 1)
            )
            board[i][j] = t
            return r
        else:
            return False

if  __name__ == '__main__':
    solution = Solution()
    board = [
        ["A","B","C","E"],
        ["S","F","C","S"],
        ["A","D","E","E"],
    ]
    word = "ABCCED"
    result = solution.exist(board, word)
    print(result)

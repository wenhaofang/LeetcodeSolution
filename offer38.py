'''
Author: wenhaofang
Date: 2023-04-24
Description: offer38 - 字符串的排列
'''

import collections

'''思路一：回溯

时间复杂度: O(n * n!)，其中 n 为字符串长度
空间复杂度: O(n)     ，其中 n 为字符串长度
'''

class Solution(object):
    def permutation(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        s_list = list(s)
        v_list = [False] * len(s)
        c_list = []

        s_list.sort()

        self.ans = []
        self.dfs(s_list, v_list, c_list)
        return self.ans

    def dfs(self, s_list, v_list, c_list):

        if  len(c_list) == len(s_list):
            self.ans.append(''.join(c_list))
        else:
            for i in range(len(s_list)):
                if  v_list[i] == True:
                    continue
                if  i > 0 and s_list[i - 1] == s_list[i] and v_list[i - 1] == False:
                    continue
                v_list[i] = True
                c_list.append(s_list[i])
                self.dfs(s_list, v_list, c_list)
                c_list.pop()
                v_list[i] = False

if  __name__ == '__main__':
    solution = Solution()
    s = "abc"
    result = solution.permutation(s)
    print(result)

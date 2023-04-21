'''
Author: wenhaofang
Date: 2023-04-21
Description: offer31 - 栈的压入、弹出序列
'''

'''思路一：模拟

时间复杂度: 
空间复杂度: 
'''

class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        pushed_s = [] # stack

        pushed_q = list(reversed(pushed))
        popped_q = list(reversed(popped))

        while len(popped_q) != 0:
            if  len(pushed_s) > 0 and popped_q[-1] == pushed_s[-1]:
                popped_q.pop()
                pushed_s.pop()
            else:
                if  len(pushed_q) == 0:
                    return False
                else:
                    while len(pushed_q) != 0:
                        if  popped_q[-1] == pushed_q[-1]:
                            popped_q.pop()
                            pushed_q.pop()
                            break
                        else:
                            pushed_s.append(pushed_q[-1])
                            pushed_q.pop()
                            continue

        return len(popped_q) == 0 and len(pushed_q) == 0 and len(pushed_s) == 0

if  __name__ == '__main__':
    solution = Solution()
    pushed = [1, 2, 3, 4, 5]
    popped = [4, 5, 3, 2, 1]
    result = solution.validateStackSequences(pushed, popped)
    print(result)

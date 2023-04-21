'''
Author: wenhaofang
Date: 2023-04-20
Description: offer20 - 表示数值的字符串
'''

'''思路一：模拟

时间复杂度: O(n)，其中 n 为字符串长度
空间复杂度: O(1)
'''

class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        digits = set(['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'])

        cur = 0
        end = len(s)

        # 1. 空格
        while  cur < end and s[cur] == ' ':
            cur += 1

        if  cur == end:
            return False

        # 2. 符号
        if  s[cur] == '+' or s[cur] == '-':
            cur += 1

        # 3. 数字 (整数或小数)
        dot = 0
        num = 0
        while cur < end:
            if  s[cur] == '.':
                cur += 1
                dot += 1
                continue
            if  s[cur] in digits:
                cur += 1
                num += 1
                continue
            break

        if  dot >= 2 or num <= 0:
            return False

        if  cur == end:
            return True

        # 4. 科学计数法
        if  s[cur] == 'e' or s[cur] == 'E':
            cur += 1

            if  cur == end:
                return False

            # 5. 符号
            if  s[cur] == '+' or s[cur] == '-':
                cur += 1

            # 6. 数字 (整数)
            num = 0
            while cur < end:
                if  s[cur] in digits:
                    cur += 1
                    num += 1
                    continue
                break

            if  num == 0:
                return False

        # 7. 空格
        while  cur < end and s[cur] == ' ':
            cur += 1

        if  cur == end:
            return True
        else:
            return False

if  __name__ == '__main__':
    solution = Solution()
    s = "0"
    result = solution.isNumber(s)
    print(result)

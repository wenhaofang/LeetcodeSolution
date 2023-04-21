'''
Author: wenhaofang
Date: 2023-04-21
Description: offer26 - 树的子结构
'''

'''思路一：递归

时间复杂度: 
空间复杂度: 
'''

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isSubStructure(self, A, B):
        """
        :type A: TreeNode
        :type B: TreeNode
        :rtype: bool
        """
        if  B == None:
            return False
        if  A == None:
            return False

        return (
            self.check(A, B) or self.isSubStructure(A.left, B) or self.isSubStructure(A.right, B)
        )

    def check(self, A, B):
        if  B == None:
            return True
        if  A == None:
            return False

        return (
            self.check(A.left, B.left) and self.check(A.right, B.right) if A.val == B.val else False
        )

if  __name__ == '__main__':
    solution = Solution()
    a11 = TreeNode(3)
    a21 = TreeNode(4)
    a22 = TreeNode(5)
    a31 = TreeNode(1)
    a32 = TreeNode(2)
    a11.left = a21
    a11.right = a22
    a21.left = a31
    a21.right = a32
    b11 = TreeNode(4)
    b21 = TreeNode(1)
    b11.left = b21
    result = solution.isSubStructure(a11, b11)
    print(result)

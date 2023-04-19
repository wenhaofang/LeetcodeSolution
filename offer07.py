'''
Author: wenhaofang
Date: 2023-04-19
Description: offer07 - 重建二叉树
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
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if  len(preorder) == 0 or len(inorder) == 0:
            return None

        root_val = preorder[0]
        root_idx = inorder.index(root_val)

        root = TreeNode(root_val)
        root.left = self.buildTree(preorder[1: root_idx + 1], inorder[0: root_idx])
        root.right = self.buildTree(preorder[root_idx + 1:], inorder[root_idx + 1:])

        return root

if  __name__ == '__main__':
    solution = Solution()
    preorder = [3, 9, 20, 15, 7]
    inorder = [9, 3, 15, 20, 7]
    result = solution.buildTree(preorder, inorder)
    # print(result)

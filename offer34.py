'''
Author: wenhaofang
Date: 2023-04-22
Description: offer34 - 二叉树中和为某一值的路径
'''

import collections

'''思路一：回溯

时间复杂度: O(n)，其中 n 为节点数量
空间复杂度: O(n)，其中 n 为节点数量
'''

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def pathSum(self, root, target):
        """
        :type root: TreeNode
        :type target: int
        :rtype: List[List[int]]
        """
        if  root == None:
            return []
        self.ans = []
        pathways = []
        self.dfs(root, target, pathways)
        return self.ans

    def dfs(self, root, target, pathways):
        if  root.left == None and root.right == None and root.val == target:
            pathways.append(root.val)
            self.ans.append(pathways[:])
            pathways.pop()
        pathways.append(root.val)
        if  root.left != None:
            self.dfs(root.left, target - root.val, pathways)
        if  root.right != None:
            self.dfs(root.right, target - root.val, pathways)
        pathways.pop()

if  __name__ == '__main__':
    solution = Solution()
    n11 = TreeNode(5)
    n21 = TreeNode(4)
    n22 = TreeNode(8)
    n31 = TreeNode(11)
    n33 = TreeNode(13)
    n34 = TreeNode(4)
    n41 = TreeNode(7)
    n42 = TreeNode(2)
    n47 = TreeNode(5)
    n48 = TreeNode(1)
    n11.left = n21
    n11.right = n22
    n21.left = n31
    n22.left = n33
    n22.right = n34
    n31.left = n41
    n31.right = n42
    n34.left = n47
    n34.right = n48
    target = 22
    result = solution.pathSum(n11, target)
    print(result)

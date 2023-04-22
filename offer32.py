'''
Author: wenhaofang
Date: 2023-04-22
Description: offer32 - 从上到下打印二叉树
'''

import collections

'''思路一：宽度优先搜索

时间复杂度: O(n)，其中 n 为节点数量
空间复杂度: O(n)，其中 n 为节点数量
'''

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if  root == None:
            return []
        r = []
        q = collections.deque(maxlen = None)
        q.append (root)
        while len(q) != 0:
            num = len(q)
            for _ in range(num):
                node = q.popleft()
                r.append(node.val)
                if  node.left != None:
                    q.append(node.left)
                if  node.right != None:
                    q.append(node.right)
        return r

if  __name__ == '__main__':
    solution = Solution()
    n11 = TreeNode(3)
    n21 = TreeNode(9)
    n22 = TreeNode(20)
    n33 = TreeNode(15)
    n34 = TreeNode(7)
    n11.left = n21
    n11.right = n22
    n22.left = n33
    n22.right = n34
    result = solution.levelOrder(n11)
    print(result)

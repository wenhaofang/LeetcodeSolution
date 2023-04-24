'''
Author: wenhaofang
Date: 2023-04-24
Description: offer36 - 二叉搜索树与双向链表
'''

import collections

'''思路一：递归

时间复杂度: O(n)，其中 n 为节点数量
空间复杂度: O(n)，其中 n 为节点数量
'''

class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def treeToDoublyList(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if  root == None:
            return  None
        head, tail = self.recursive(root)
        head.left = tail
        tail.right = head
        return head

    def recursive(self, root):
        if  root == None:
            return (None, None)
        if (
            root.left == None and
            root.right == None
        ):
            return (root, root)
        if (
            root.left != None and
            root.right == None
        ):
            head, tail = self.recursive(root.left)
            root.left = tail
            tail.right = root
            return (head, root)
        if (
            root.left == None and
            root.right != None
        ):
            head, tail = self.recursive(root.right)
            root.right = head
            head.left = root
            return (root, tail)
        if (
            root.left != None and
            root.right != None
        ):
            l_head, l_tail = self.recursive(root.left)
            r_head, r_tail = self.recursive(root.right)
            root.left = l_tail
            l_tail.right = root
            root.right = r_head
            r_head.left = root
            return (l_head, r_tail)

if  __name__ == '__main__':
    solution = Solution()
    n11 = Node(4)
    n21 = Node(2)
    n22 = Node(5)
    n31 = Node(1)
    n32 = Node(3)
    n11.left = n21
    n11.right = n22
    n21.left = n31
    n21.right = n32
    result = solution.treeToDoublyList(n11)
    print(result)

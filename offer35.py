'''
Author: wenhaofang
Date: 2023-04-22
Description: offer35 - 复杂链表的复制
'''

import collections

'''思路一：哈希映射

时间复杂度: O(n)，其中 n 为链表长度
空间复杂度: O(n)，其中 n 为链表长度
'''

class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if  head == None:
            return  head
        newH = Node(head.val)
        # next
        newP = newH
        oldP = head
        newI = {} # id2idx
        oldI = {} # id2idx
        newL = []
        oldL = []
        newI[id(newP)] = len(newL)
        oldI[id(oldP)] = len(oldL)
        newL.append(newP)
        oldL.append(oldP)
        while oldP.next:
            node = Node(oldP.next.val)
            newP.next = node
            newP = newP.next
            oldP = oldP.next
            newI[id(newP)] = len(newL)
            oldI[id(oldP)] = len(oldL)
            newL.append(newP)
            oldL.append(oldP)
        # random
        for i in range(len(newL)):
            if  oldL[i].random != None:
                newL[i].random = newL[oldI[id(oldL[i].random)]]
        # return
        return newH

if  __name__ == '__main__':
    solution = Solution()
    n1 = Node(7)
    n2 = Node(13)
    n3 = Node(11)
    n4 = Node(10)
    n5 = Node(1)
    n1.next = n2
    n2.next = n3
    n3.next = n4
    n4.next = n5
    n2.random = n1
    n3.random = n5
    n4.random = n3
    n5.random = n1
    result = solution.copyRandomList(n1)
    print(result)

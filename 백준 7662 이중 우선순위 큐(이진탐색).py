import sys
from collections import deque


class Node:
    parentNode = None
    leftNode = None
    rightNode = None
    value = None
    count = 0

    def __init__(self, value):
        self.value = value
        self.count = 1


class Tree:
    rootNode = None

    def max(self):
        now = self.rootNode
        while now.rightNode:
            now = now.rightNode
        return now

    def min(self):
        now = self.rootNode
        while now.leftNode:
            now = now.leftNode
        return now

    def maxPop(self):
        now = self.rootNode
        if not now:
            return
        while now.rightNode:
            now = now.rightNode
        self.delete(now)

    def minPop(self):
        now = self.rootNode
        if not now:
            return
        while now.leftNode:
            now = now.leftNode
        self.delete(now)

    def add(self, node):
        now = self.rootNode

        if not now:
            self.rootNode = node
            return

        while True:
            if (node.value < now.value):
                if not now.leftNode:
                    now.leftNode = node
                    node.parentNode = now
                    return
                else:
                    now = now.leftNode
            elif (node.value > now.value):
                if not now.rightNode:
                    now.rightNode = node
                    node.parentNode = now
                    return
                else:
                    now = now.rightNode
            else:
                now.count += 1
                return

    def delete(self, node):

        if node.count >= 2:
            node.count -= 1
            return

        if node.value == self.rootNode.value:
            if node.rightNode:
                self.rootNode = self.rootNode.rightNode
            elif node.leftNode:
                self.rootNode = self.rootNode.leftNode
            else:
                self.rootNode = None
            return

        if node.parentNode.leftNode and (node.parentNode.leftNode.value == node.value):
            isLeft = True
        else:
            isLeft = False

        if node.rightNode:
            if isLeft:
                node.parentNode.leftNode = node.rightNode
                node.rightNode.parentNode = node.parentNode
            else:
                node.parentNode.rightNode = node.rightNode
                node.rightNode.parentNode = node.parentNode
        elif node.leftNode:
            if isLeft:
                node.parentNode.leftNode = node.leftNode
                node.leftNode.parentNode = node.parentNode
            else:
                node.parentNode.rightNode = node.leftNode
                node.leftNode.parentNode = node.parentNode
        else:
            if isLeft:
                node.parentNode.leftNode = None
            else:
                node.parentNode.rightNode = None

    def print(self):
        queue = deque()
        queue.append(self.rootNode)
        while len(queue) > 0:
            temp = queue.popleft()
            if temp:
                print(temp.value, end=" ")
                queue.append(temp.leftNode)
                queue.append(temp.rightNode)
            else: print(None , end = " ")
        print("")


t = int(sys.stdin.readline().rstrip())

for i in range(t):
    n = int(sys.stdin.readline().rstrip())
    tree = Tree()
    for j in range(n):
        statement = sys.stdin.readline().rstrip().split()
        if statement[0] == "I":
            temp = Node(int(statement[1]))
            tree.add(temp)
        elif statement[0] == "D":
            if statement[1] == "1":
                tree.maxPop()
            elif statement[1] == "-1":
                tree.minPop()
    if tree.rootNode == None:
        print("EMPTY")
    else:
        print(tree.max().value, tree.min().value)
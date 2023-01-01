import sys
from collections import deque


class Node:
    leftNode = None
    rightNode = None
    value = None

    def __init__(self, value):
        self.value = value

class Tree:
    root = None

    def add(self, node, lNode, rNode):
        if not self.root:
            self.root = node
            node.leftNode = lNode
            node.rightNode = rNode
            return
        queue = deque()
        queue.append(self.root)
        while len(queue) > 0:
            now = queue.popleft()
            if now.value == node.value:
                now.leftNode = lNode
                now.rightNode = rNode
                return
            if now.leftNode:
                queue.append(now.leftNode)
            if now.rightNode:
                queue.append(now.rightNode)

    def preOrder(self, node):
        if node:
            print(node.value, end="")
            self.preOrder(node.leftNode)
            self.preOrder(node.rightNode)

    def inOnder(self, node):
        if node:
            self.inOnder(node.leftNode)
            print(node.value, end="")
            self.inOnder(node.rightNode)

    def postOrder(self, node):
        if node:
            self.postOrder(node.leftNode)
            self.postOrder(node.rightNode)
            print(node.value, end="")


n = int(sys.stdin.readline().rstrip())
tree = Tree()
for j in range(n):
    a, b, c = sys.stdin.readline().rstrip().split()
    node = Node(a)
    lNode = None
    rNode = None
    if not b == ".":
        lNode = Node(b)
    if not c == ".":
        rNode = Node(c)
    tree.add(node, lNode, rNode)

tree.preOrder(tree.root)
print("")
tree.inOnder(tree.root)
print("")
tree.postOrder(tree.root)

import sys

global STACK_SIZE
STACK_SIZE = 10000

def push(stack, x, t):
    t += 1
    stack[t] = x
    return t
def pop(stack, t):
    if empty(t):
        return -1, t
    item = stack[t]
    t -= 1
    return item, t
def size(t):
    return t + 1
def empty(t):
    if (t == -1):
        return 1
    return 0
def top(stack, t):
    if empty(t):
        return -1
    return stack[t]


n = int(input())
stack = [-1] * n
t = -1

for i in range(n):
    statement = sys.stdin.readline().rstrip().split()
    if(statement[0] == "push"):
        t = push(stack, int(statement[1]), t)
    elif(statement[0] == "pop"):
        item, t = pop(stack, t)
        print(item)
    elif(statement[0] == "size"):
        print(size(t))
    elif(statement[0] == "empty"):
        print(empty(t))
    elif(statement[0] == "top"):
        print(top(stack, t))

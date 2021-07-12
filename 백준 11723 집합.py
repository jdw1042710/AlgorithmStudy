import sys


r, c = map(int, sys.stdin.readline().rstrip().split())
board = [[0 for _ in range(c)] for _ in range(r)]
tomato = set()
nxt = list()
for i in range(r):
    arr = list(map(int, sys.stdin.readline().rstrip().split()))
    for j in range(c):
        board[i][j] = arr[j]
        if(arr[j] == 0):
            tomato.add([i,j])
        elif(arr[j] == 1):
            nxt.append([i,j])
if len(tomato) == 0:
    print(0)
else:
    while len(nxt) != 0:
    now = nxt.pop()

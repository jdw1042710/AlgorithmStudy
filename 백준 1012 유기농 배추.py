import sys

global direction
direction = [[0,-1],[1,0],[0,1],[-1,0]]
def search(arr, visited, x, y):
    del visited[(x, y)]
    dir = 0
    while(dir < 4):
        if(arr[y + 1 + direction[dir][1]][x + 1 + direction[dir][0]] == 1) and ((x + direction[dir][0], y + direction[dir][1]) in visited):
            search(arr, visited, x + direction[dir][0], y + direction[dir][1])
        dir += 1


num = int(input())

for i in range(num):
    count = 0
    m, n, k= map(int, sys.stdin.readline().rstrip().split())
    field = [[0 for _ in range(m + 2)] for _ in range(n + 2)]
    visited = dict()
    for j in range(k):
        x, y = map(int, sys.stdin.readline().rstrip().split())
        field[y + 1][x + 1] = 1
        visited[(x, y)] = False
    while(len(visited) > 0):
        x, y = list(visited.keys())[0]
        search(field, visited, x, y)
        count += 1
    print(count)



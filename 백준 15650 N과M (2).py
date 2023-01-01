import sys

def dfs(start, n, m, queue):
    for i in range(start, n - m + 2):
        if m == 0:
            for j in queue:
                print(j, end=" ")
            print("")
            return
        queue.append(i)
        dfs(i + 1, n, m - 1, queue)
        queue.pop()

n, m = map(int, sys.stdin.readline().rstrip().split())
queue = list()
dfs(1, n, m, queue)

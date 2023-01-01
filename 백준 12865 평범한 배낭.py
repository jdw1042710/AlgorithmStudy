import sys
sys.setrecursionlimit(10**6)
global cost, cash, n


def pack(capacity, start):
    if start == n:
        return 0
    arr = list()
    if cash[capacity][start] != -1:
        ##print("겹침")
        return cash[capacity][start]
    if cost[start][0] <= capacity:
        arr.append(cost[start][1] + pack(capacity - cost[start][0], start + 1))
    arr.append(pack(capacity, start + 1))
    cash[capacity][start] = max(arr)
    return cash[capacity][start]


n, k = map(int, sys.stdin.readline().rstrip().split())
cost = []
for i in range(n):
    cost.append(list(map(int, sys.stdin.readline().rstrip().split())))
cash = [[-1 for _ in range(n)] for _ in range(k + 1)]
print(pack(k, 0))

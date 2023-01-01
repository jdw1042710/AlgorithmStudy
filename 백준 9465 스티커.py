import sys
sys.setrecursionlimit(10**6)
global cash, cost


def choice(x, y, n):
    if x >= n:
        return 0
    if x == n - 1:
        return cost[y][x]
    if cash[y][x] != -1:
        return cash[y][x]
    cash[y][x] = cost[y][x] + max(choice(x + 1, (y + 1) % 2, n), choice(x + 2, y, n), choice(x + 2, (y + 1) % 2, n))
    return cash[y][x]


t = int(sys.stdin.readline().rstrip())
for _ in range(t):
    n = int(sys.stdin.readline().rstrip())
    cost = []
    cash = [[-1 for _ in range(n)] for _ in range(2)]
    for i in range(2):
        cost.append(list(map(int, sys.stdin.readline().rstrip().split())))
    print(max(choice(0, 0, n), choice(0, 1, n)))
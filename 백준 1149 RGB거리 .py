import sys
sys.setrecursionlimit(10**6)
global cash, cost


def paint(i, color, n):
    if i == n - 1:
        return cost[i][color]
    if cash[i][color] != 0:
        return cash[i][color]
    cash[i][color] = cost[i][color] + min(paint(i + 1, (color + 1) % 3, n), paint(i + 1, (color + 2) % 3, n))
    return cash[i][color]


n = int(sys.stdin.readline().rstrip())
cost = []
cash = [[0, 0, 0] for _ in range(n)]
for i in range(n):
    cost.append(list(map(int, sys.stdin.readline().rstrip().split())))
print(min(paint(0, 0, n), paint(0, 1, n), paint(0, 2, n)))

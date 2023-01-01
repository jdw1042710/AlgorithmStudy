import sys
global arr, n
sys.setrecursionlimit(10**6)


def com(n, r):
    if r == 0:
        return 1
    if n == r:
        return 1
    if cash[n][r] == -1:
        cash[n][r] = com(n-1, r) + com(n-1, r-1)
    return cash[n][r]

n, r = map(int, sys.stdin.readline().rstrip().split())
cash = [[-1 for _ in range(r + 1)] for _ in range(n + 1)]
print(com(n, r))
import sys
global arr, n
sys.setrecursionlimit(10**6)


def LIS(start):
    if cash[start] != -1:
        return cash[start]
    temp = [1]
    for j in range(start + 1, n):
        if arr[start] < arr[j]:
            temp.append(1 + LIS(j))
    cash[start] = max(temp)
    return cash[start]


n = int(sys.stdin.readline().rstrip())
arr = list(map(int, sys.stdin.readline().rstrip().split()))
cash = [-1 for _ in range(n)]
print(max([LIS(i) for i in range (n)]))
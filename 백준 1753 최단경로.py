import sys, heapq
from collections import deque
global adjacent, visit, cost, heap
sys.setrecursionlimit(10**6)


def dijkstra(index):
    visit[index] = True
    for i in adjacent[index]:
        if (not visit[i[0]]) and(cost[i[0]] > cost[index] + i[1]):
            cost[i[0]] = cost[index] + i[1]
            heapq.heappush(heap, [cost[i[0]], i[0]])
    if len(heap) == 0:
        return
    temp = heapq.heappop(heap)
    while visit[temp[1]]:
        if len(heap) == 0:
            return
        temp = heapq.heappop(heap)
    dijkstra(temp[1])

v, e= map(int, sys.stdin.readline().rstrip().split())
start = int(sys.stdin.readline().rstrip())
adjacent = [[] for _ in range(v + 1)]
visit = [False for _ in range(v + 1)]
cost = [99999999999 for _ in range(v + 1)]
heap = [[99999999999, i] for i in range(1, v + 1)]
cost[start] = 0

for _ in range(e):
    a, b, w = map(int, sys.stdin.readline().rstrip().split())
    isExist = False
    adjacent[a].append([b, w])

dijkstra(start)
for i in range(1, v+1):
    if cost[i] == 99999999999:
        print("INF")
    else:
        print(cost[i])

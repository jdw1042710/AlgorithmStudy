import heapq
import sys


def delHeap(heap, valid):
    if len(heap) == 0:
        return
    temp = heapq.heappop(heap)
    while valid[temp[1]] != True:
        if len(heap) == 0:
            return
        temp = heapq.heappop(heap)
    valid[temp[1]] = False

t = int(sys.stdin.readline().rstrip())
for i in range(t):
    n = int(sys.stdin.readline().rstrip())
    minHeap = list()
    maxHeap = list()
    valid = [True for _ in range(1000001)]

    for j in range(n):
        a, b = sys.stdin.readline().rstrip().split()
        if a == 'I':
            heapq.heappush(minHeap, [int(b), j])
            heapq.heappush(maxHeap, [-1 * int(b), j])
        elif a == 'D':
            if b == '1':
                delHeap(maxHeap, valid)
            elif b == '-1':
                delHeap(minHeap, valid)

    while (len(minHeap) > 0) and (valid[minHeap[0][1]] == False):
        heapq.heappop(minHeap)
    while (len(maxHeap) > 0) and (valid[maxHeap[0][1]] == False):
        heapq.heappop(maxHeap)

    if len(maxHeap) * len(minHeap) == 0:
        print("EMPTY")
    else:
        print(-1 * maxHeap[0][0], minHeap[0][0])

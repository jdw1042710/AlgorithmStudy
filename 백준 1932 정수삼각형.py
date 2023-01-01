import sys


n = int(sys.stdin.readline().rstrip())
triangle = []
for _ in range(n):
    triangle.append(list(map(int,sys.stdin.readline().rstrip().split())))

for i in range(1, n):
    for j in range(i + 1):
        if j == 0:
            triangle[i][0] += triangle[i - 1][0]
        elif j == i:
            triangle[i][j] += triangle[i - 1][j-1]
        else:
            triangle[i][j] += max(triangle[i - 1][j-1], triangle[i - 1][j])
print(max(triangle[n-1]))


patern = [['W','B'], ['B', 'W']]

def repaint(board, a, b):
    countA = 0
    standard = patern[0]
    for i in range(8):
        for j in range(8):
            if (board[a + i][b + j] != standard[(i + j) % 2]):
                countA = countA + 1
    countB = 0
    standard = patern[1]
    for i in range(8):
        for j in range(8):
            if (board[a + i][b + j] != standard[(i + j) % 2]):
                countB = countB + 1
    if (countA > countB):
        return countB
    else:
        return countA

N, M = input().split(' ')
N = int(N)
M = int(M)
board = []

Min = 99999

for i in range(N):
    board.append(input())

for i in range(N - 7):
    for j in range(M - 7):
        temp = repaint(board, i, j)
        if (Min > temp):
            Min = temp

print(Min)

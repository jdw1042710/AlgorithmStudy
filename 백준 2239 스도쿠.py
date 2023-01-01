import sys, heapq
global sudoku
from collections import deque
sys.setrecursionlimit(10**5)


def isValid(row, col, num):
    for i in range(9):
        if sudoku[i][col] == num:
            return False
        if sudoku[row][i] == num:
            return False
    blockRow = row - (row % 3)
    blockCol = col - (col % 3)
    for i in range(blockRow, blockRow + 3):
        for j in range(blockCol, blockCol + 3):
            if sudoku[i][j] == num:
                return False
    return True


def fill(row, col):
    if row == 9:
        return True
    nxtCol = (col + 1) % 9
    nxtRow = row + ((col + 1) // 9)
    if sudoku[row][col] != 0:
        if fill(nxtRow, nxtCol):
            return True
        else:
            return False
    for i in range(1, 10):
        if isValid(row, col, i):
            sudoku[row][col] = i
            if fill(nxtRow, nxtCol):
                return True
            sudoku[row][col] = 0
    return False


sudoku = [[0 for _ in range(9)] for _ in range(9)]
for i in range(9):
    row = sys.stdin.readline().rstrip()
    for j in range(9):
        sudoku[i][j] = int(row[j])

fill(0, 0)


for i in range(9):
    for j in range(9):
        print(sudoku[i][j], end = "")
    print("")


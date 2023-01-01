import sys

def matrixMul(matrix1, matrix2):
    n = 2
    k = 2
    m = 2
    matrix = [[0 for _ in range(m)] for _ in range(n)]
    for i in range(n):
        for j in range(m):
            for l in range(k):
                matrix[i][j] += (matrix1[i][l] * matrix2[l][j]) % 1000000007
    return matrix


def matrixPow(matrix, n):
    if n == 1:
        return matrix

    m = matrixPow(matrix, n // 2)
    temp = matrixMul(m, m)
    for i in range(2):
        for j in range(2):
            temp[i][j] %= 1000000007
    if n % 2 == 0:
        return temp
    if n % 2 == 1:
        return matrixMul(temp, matrix)


n = int(sys.stdin.readline().rstrip())
matrix = [[1, 1], [1, 0]]
print(matrixPow(matrix, n)[0][1])

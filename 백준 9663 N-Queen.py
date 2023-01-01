import sys


def isValid(invalid, row, col):
    if col in invalid[0]:
        return False
    if row - col in invalid[1]:
        return False
    if row + col in invalid[2]:
        return False
    return True


def queen(row, invalid, n):
    count = 0
    for col in range(n):
        if row == n:
            return 1
        if isValid(invalid, row, col):
            invalid[0].add(col)
            invalid[1].add(row-col)
            invalid[2].add(row+col)
            count += queen(row + 1, invalid, n)
            invalid[0].discard(col)
            invalid[1].discard(row-col)
            invalid[2].discard(row+col)
    return count


n = int(sys.stdin.readline().rstrip())

invalid_col = set()
invalid_diag = set()
invalid_inv_diag = set()
invalid = [invalid_col, invalid_diag, invalid_inv_diag]
print(queen(0, invalid, n))

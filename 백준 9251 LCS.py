import sys
sys.setrecursionlimit(10**6)
global cash, str1, str2


def LCS(s1, s2):
    if (s1 >= len(str1)) or (s2 >= len(str2)):
        return 0
    if str1[s1] == str2[s2]:
        return 1 + LCS(s1 + 1, s2 + 1)
    if cash[s1][s2] == -1:
        cash[s1][s2] = max(LCS(s1 + 1, s2), LCS(s1, s2 + 1))
    return cash[s1][s2]


str1 = sys.stdin.readline().rstrip()
str2 = sys.stdin.readline().rstrip()
cash = [[-1 for _ in range(len(str2))] for _ in range(len(str1))]
print(LCS(0, 0))
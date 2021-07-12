import sys
sys.setrecursionlimit(10**6)
def search(a, b, n, dp):
    if(n == 1):
        return True
    if(dp[n] == 1):
        return False
    dp[n] = 1
    if(n <= 0):
        return False
    isA = False
    if(n % a == 0):
        isA = search(a, b, n//a, dp)
    isB = search(a, b, n - b, dp)
    return isA or isB


t = int(sys.stdin.readline().rstrip())
for i in range(t):
    dp = [0]*(10**9 + 1)
    n, a, b = map(int,sys.stdin.readline().rstrip().split())
    if(search(a,b,n, dp)):
        print("Yes")
    else:
        print("No")

def one(dp, n):
    array = list()
    if(n % 3 == 0):
        array.append(dp[n // 3] + 1)
    if(n % 2 == 0):
        array.append(dp[n // 2] + 1)
    array.append(dp[n-1] + 1)
    dp[n] = min(array)

n = int(input())
dp = [-1] * (n + 1)
dp[1]= 0

i = 2
while(i <= n):
    one(dp, i)
    i += 1
print(dp[n])

n, k = map(int, input().split())

array = list(range(1,n + 1))
target = k - 1
print("<", end = "")
while(True):
    print(array[target], end = "")
    del array[target]
    n -= 1 
    if(n <= 0):
        break
    else:
        target = (target + k - 1) % n
        print(", ", end = "")
print(">")

n = int(input())
array = list(range(1, n+1))
remove = 0
top = 0
while(remove < n - 1):
    top += 1
    remove += 1
    array.append(array[top])
    top += 1
print(array[top])

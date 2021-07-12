x, y, w, h = input().split(' ')
x = int(x)
y = int(y)
w = int(w)
h = int(h)

Min = x
if(Min > y):
    Min = y
if(Min > w - x):
    Min = w - x
if(Min > h - y):
    Min = h - y

print(Min)

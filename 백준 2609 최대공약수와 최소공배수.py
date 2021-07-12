def gcd(a, b):
    if(a < b):
        a, b = b, a
    n = a % b
    if(n == 0):
        return b
    else:
        return gcd(b, n)


a, b = map(int , input().split())
GCD = gcd(a, b)
print(GCD)
print(a*b//GCD)

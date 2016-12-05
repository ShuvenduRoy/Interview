import math
def isPrime(n):
    if n==2:
        return True
    m = math.ceil(math.sqrt(n))
    for i in range(2,m+1):
        if n%i ==0:
            return False
    return True

def sol():
    n = int(input())
    if isPrime(n):
        return 1
    if isPrime(n-2):
        return 2
    if not (n & 1):
        return 2
    return 3

print(sol())


# Longest sum not continus


def rec(A, n):
    if n==0:
        return 0

    sum = max(rec(A, n-1), A[n-1] + rec(A, n-1))
    return sum


A = [-2,-3,4,-1,-2,1,5,-3]
print(rec(A,len(A)))
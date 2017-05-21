import sys


def MatrixChainOrder(arr, n):
    table = [[0 for i in range(n)] for i in range(n)]

    for l in range(2,n):
        for i in range(1, n-l+1):           # why +1, because range does mot include last index
            j = i+l-1                       # why -1, because i is one matrix itself
            table[i][j] = sys.maxsize

            for k in range(i, j):
                q = table[i][k]+table[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if q< table[i][j]:
                    table[i][j] = q
    return table[1][n-1]

arr = [1, 2, 3, 4]
size = len(arr)

print("Minimum number of multiplications is " +
      str(MatrixChainOrder(arr, size)))
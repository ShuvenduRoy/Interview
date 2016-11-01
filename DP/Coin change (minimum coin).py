import sys


def count(cost, m, n):
    table = [[sys.maxsize for x in range(n+1)] for x in range(m)]
    table[0][0] = 0;

    for i in range(1,n+1):
        if i>=cost[0]:
            table[0][i] = min(table[0][i], table[0][i - cost[0]] + 1)

    for i in range(1,m):
        for j in range(1,n+1):
            if j >= cost[i]:
                table[i][j] = min(table[i - 1][j], 1 + table[i][j - cost[i]])
            else:
                table[i][j] = table[i-1][j]
    return table[m-1][n]

cost = [1,2,3]
m = len(cost)
n = 5
print(count(cost, m, n))
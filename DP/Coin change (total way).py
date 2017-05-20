def count(cost, m, n):
    table = [[0 for x in range(n+1)] for x in range(m)]

    for i in range(m):
        table[i][0] = 1

    for i in range(m):
        for j in range(1, n+1):
            if j >= cost[i]:
                table[i][j] = table[i-1][j] + table[i][j - cost[i]]
            else:
                table[i][j] = table[i-1][j]

    return table[m-1][n]


cost = [1, 2, 3]
m = len(cost)
n = 4
print(count(cost, m, n))
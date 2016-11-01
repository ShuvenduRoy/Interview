def minCost(cost, m, n):
    table = [[0 for x in range(n)] for x in range (m)]

    table[0][0] = cost[0][0]
    for i in range(1,m):
        table[i][0] = table[i-1][0] + cost[i][0]

    for j in range (1,n):
        table[0][j] = table[0][j-1] + cost[0][j]

    for i in range(1,m):
        for j in range(1,n):
            table[i][j] = min(table[i-1][j], table[i][j-1], table[i-1][j-1]) + cost[i][j]

    return table[m-1][n-1]


cost = [[1, 2, 3],
        [4, 8, 2],
        [1, 5, 3]]
print(minCost(cost, 3, 3))
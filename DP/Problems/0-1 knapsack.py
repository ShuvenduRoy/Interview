def knapSack(w, wt, val, n):
    table = [[0 for i in range(w+1)] for i in range(n+1)]

    for i in range(1, n+1):
        for j in range(1, w+1):
            if j >= wt[i-1]:
                if table[i][j] < val[i-1] + table[i][j-wt[i-1]]:
                    table[i][j] = val[i - 1] + table[i-1][j - wt[i - 1]]
                else:
                    table[i][j] = table[i-1][j]
    print(table)
    return table[n][w]


val = [60, 100, 120]
wt = [10, 20, 30]
W = 50
n = len(val)
print(knapSack(W, wt, val, n))
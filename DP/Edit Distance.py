def editDistDP(str1, str2, m,n):
    table = [[0 for x in range(n+1)] for x in range(m+1)]
    print (table)

    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0:
                table[i][j] = j
            elif j == 0:
                table[i][j] = i
            elif str1[i-1] == str2[j-1]:
                table[i][j] = table[i-1][j-1]
            else:
                table[i][j] = 1+ min(table[i][j-1],
                                  table[i-1][j],
                                  table[i-1][j-1])
    return table[m][n]

str1 = "sunday"
str2 = "saturday"

print(editDistDP(str1, str2, len(str1), len(str2)))
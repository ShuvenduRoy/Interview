class Solution(object):
    def maximalRectangle(self, matrix):
        m = len(matrix)
        if m==0:
            return 0
        n = len(matrix[0])

        row = [[0 for j in range(n)] for i in range(m)]
        col = [[0 for j in range(n)] for i in range(m)]

        ans = 0
        if matrix[0][0] == 1:
            ans = 1

        for i in range(1,m):
            if matrix[i][0] == 1:
                row[i][0] = row[i-1][0] + 1
            else:
                row[i][0] = 0

        for j in range(1,n):
            if matrix[0][i] == 1:
                col[0][i] = col[0][i-1] + 1
            else:
                col[0][i] = 0


        for i in range(1,m):
            for j in range(1,n):
                if matrix[i][j]==0:
                    row[i][j]=0
                    col[i][j]=0
                else:
                    if matrix[i-1][j] == matrix[i][-1]==1:
                        row[i][j] = row[i-1][j] + 1
                        col[i][j] = col[i][j-1]+1



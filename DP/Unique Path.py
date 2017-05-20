class Solution(object):
    def uniquePaths(self, m, n):
        path = [[0 for x in range(n)] for y in range(m)]

        for x in range(m):
            path[x][0] = 1
        for y in range(n):
            path[0][y] = 1

        for i in range(1,m):
            for j in range(1,n):
                path[i][j] = path[i-1][j] + path[i][j-1]

        return path[m-1][n-1]

s = Solution()
print(s.uniquePaths(3,7))
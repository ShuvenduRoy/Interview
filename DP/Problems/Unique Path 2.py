class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        dp = [[0 if obstacleGrid[y][x] == 1 else 1 for x in range(n)] for y in range(m)]

        for x in range(1,m):
            if obstacleGrid[x][0] == 1:
                dp[x][0] = 0
            else:
                dp[x][0] = dp[x-1][0]

        for y in range(1,n):
            if obstacleGrid[0][y] == 1:
                dp[0][y] = 0
            else:
                dp[0][y] = dp[0][y-1]

        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0;
                else:
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

        return dp[m-1][n-1]

test = [[0,0],[0,1]]
s = Solution()
print(s.uniquePathsWithObstacles(test))
class Solution(object):
    def minPathSum(self, grid):
        m = len(grid)
        n = len(grid[0])

        dp = [[0 for _ in range(n)] for _ in range(m)]
        dp[-1][-1] = grid[-1][-1]

        for x in range(m-2, -1, -1):
            dp[x][-1] = dp[x+1][-1] + grid[x][-1]

        for x in range(n-2, -1, -1):
            dp[-1][x] = dp[-1][x+1] + grid[-1][x]

        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j]

        return dp[0][0]

text = [[1,2],[1,1]]
s = Solution()
print(s.minPathSum(text))
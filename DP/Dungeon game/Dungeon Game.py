"""
Leetcode 174
This is a bottom up dynamic programming problem,
Atleast i could not solve it with top down manner
"""

class Solution(object):
    def calculateMinimumHP(self, dungeon):
        m = len(dungeon)
        n = len(dungeon[0])

        dp = [[0 for _ in range(n)] for _ in range(m)]
        dp[-1][-1] = 1 if dungeon[-1][-1]>0 else 1-dungeon[-1][-1]

        for i in range(n - 2, -1, -1):
            dp[-1][i] = max(1, dp[-1][i + 1] - dungeon[-1][i])
        for j in range(m - 2, -1, -1):
            dp[j][-1] = max(1, dp[j + 1][-1] - dungeon[j][-1])


        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                dp[i][j] = max(1, min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j])

        return dp[0][0]


test = [[1,-3,3],[0,-2,0],[-3,-3,-3]]
s = Solution()
print(s.calculateMinimumHP(test))
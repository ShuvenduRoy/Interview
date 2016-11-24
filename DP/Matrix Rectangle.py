def calc(ans, a, b):
    temp = (a ) * (b )
    if temp > ans:
        ans = temp
    return ans


class Solution(object):
    def maximalRectangle(self, matrix):
        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])

        dp = [[0 for j in range(n)] for i in range(m)]
        for i in range(m):
            dp[i][0] = int(matrix[i][0])
        for i in range(n):
            dp[0][i] = int(matrix[0][i])

        for i in range(1,m):
            for j in range(1,n):
                if matrix[i][j] == '1':
                    dp[i][j] = min(int(matrix[i-1][j]),
                                       int(matrix[i][j-1]),
                                           int(matrix[i-1][j-1]))+1
                else:
                    dp[i][j] = 0
        return dp[i][j]


test = ["10100","10111","11111","10010"]
s = Solution()
print(s.maximalRectangle(test))

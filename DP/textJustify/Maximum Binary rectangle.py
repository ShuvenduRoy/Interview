# Leetcode 85 (dp problem)
# Logic OK
# Time limit exceed

class Solution(object):
    def largestArea(self, height):
        n = len(height)
        ans = 0
        for i in range(n):
            for j in range(i, n):
                l = j-i+1
                m = min(height[i:j+1])
                if (l*m) > ans:
                    ans = l*m
        return ans


    def maximalRectangle(self, matrix):
        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])
        ans = 0

        dp = [0 for _ in range(n)]

        for i in range(m):
            for j in range(n):
                if(matrix[i][j] == '1'):
                    dp[j] = dp[j] +1
                else:
                    dp[j] = 0
            ans = max(ans, self.largestArea(dp))
        return ans

test = ["10100","10111","11111","10010"]
s = Solution()
print(s.maximalRectangle(test))

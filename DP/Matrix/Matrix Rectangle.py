def findMax(dp):
    tempMax = 0;
    sum = 0
    n = len(dp)
    for i in range(n):
        sum += dp[i]
        if sum>tempMax:
            tempMax = sum
    return tempMax


class Solution(object):
    def maximalRectangle(self, matrix):
        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])
        ans = 0

        dp = [0 for _ in range(m)]

        for i in range(n):
            for j in range(i,n):
                for k in range(m):
                    dp[k] = dp[k] + int(matrix[k][j])
                temp = findMax(dp)
                if temp>ans:
                    ans = temp

            dp = [0 for _ in range(m)]
        return ans

test = ["10100","10111","11111","10010"]
s = Solution()
print(s.maximalRectangle(test))

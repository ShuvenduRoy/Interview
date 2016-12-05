# Leetcode 413
# Solution in iteration but got TLE
class Solution(object):
    def numberOfArithmeticSlices(self, A):
        def check(i,j):
            dif = A[i+1] - A[i]
            for k in range(i+1,j):
                if A[k] - A[k-1] != dif:
                    return 0
            return 1

        n = len(A)
        if n < 3:
            return 0
        ans = 0

        for l in range(3,n+1):
            for i in range(n-l+1):
                j = i+l
                ans += check(i,j)
        return ans

A = [1, 2, 3, 4]
s = Solution()
print(s.numberOfArithmeticSlices(A))
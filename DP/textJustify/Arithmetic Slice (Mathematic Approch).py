class Solution(object):
    def numberOfArithmeticSlices(self, A):
        n = len(A)
        if n<3:
            return 0

        ans = cnt = 0
        dif = A[1] - A[0]

        for i in range(2,n):
            if A[i] - A[i-1] == dif:
                cnt +=1
                ans += cnt
            else:
                dif = A[i] - A[i-1]
                cnt = 0
        return ans
# Leetcode 44 : Wild card Matching
# Created by : Bikash , 21 nov, 2016

class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """

        m = len(s)
        n = len(p)

        table = [[False for x in range(n+1)] for y in range (m+1)]
        table[0][0] = True

        for i in range(1, n+1):
            if p[i-1] == '*':
                table[0][i] = table[0][i-1]

        for i in range(1, m+1):
            for j in range(1, n+1):
                if s[i-1] == p[j-1] or p[j-1] == '?':
                    table[i][j] = table[i-1][j-1]
                elif p[j-1] == '*':
                    table[i][j] = table[i-1][j] or table[i][j-1]
                else:
                    table[i][j] = False

        return table[m][n]

taxt = ''
pattern = '?'
s = Solution()
print(s.isMatch(taxt,pattern))

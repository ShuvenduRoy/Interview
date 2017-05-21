class Solution(object):
    def isMatch(self, s, p):
        """
        Leetcode 10
        :type s: str
        :type p: str
        :rtype: bool
        """
        m = len(s)
        n = len(p)

        table = [[False for x in range(n+1)] for y in range(m+1)]
        table[0][0] = True

        for j in range(1, n+1):
            if p[j-1]=='*':
                table[0][j] = table[0][j-2]

        for i in range(1,m+1):
            for j in range(1, n+1):
                if s[i-1]==p[j-1] or p[j-1]=='.':               # Indexing starting from 1 so there is the extra -1
                    table[i][j] = table[i-1][j-1]

                elif p[j-1] == '*':
                    table[i][j] = table[i][j-2]
                    if s[i-1]==p[j-1-1] or p[j-1-1]=='.':
                        table[i][j] = table[i][j] or table[i-1][j]

                else:
                    table[i][j] = False


        return table[m][n]

text = 'aa'
pattern = '.*'
s = Solution()
print(s.isMatch(text,pattern))
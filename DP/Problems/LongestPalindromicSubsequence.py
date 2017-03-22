# Leetcode 516
# Time limit exceeded

class Solution(object):
    def longestPalindromeSubseq(self, s):
        n = len(s)+1

        table = [[0 for j in range(n)] for i in range(n)]

        for i in range(n):
            for j in range(n):
                if i==0 or j==0:
                    table[i][j]=0;
                elif(s[i-1] == s[n-j-1]):
                    table[i][j] = table[i-1][j-1]+1;
                else:
                    table[i][j] = max(table[i][j-1], table[i-1][j])
        return(table[n-1][n-1])

s= Solution()
print(s.longestPalindromeSubseq("bbbab"))
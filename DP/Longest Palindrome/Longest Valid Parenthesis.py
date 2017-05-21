class Solution(object):
    def longestValidParentheses(self, s):
        n = len(s)
        if n==0:
            return 0
        maxLen = 0;
        isValid = [[False for x in range(n)] for y in range(n)]

        for l in (2 ** n for n in range(1, int(n ** (1 / 2) + 1))):
            for start in range(n-l+1):
                if (s[start]=='(' and s[start+l-1]==')') and (l==2 or isValid[start+1][start+l-2]):
                    isValid[start][start+l-1] = True
                    maxLen = max(maxLen, l)

        return maxLen


text = '()()'
s = Solution()
print(s.longestValidParentheses(text))
# unfinished

class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        isMatch = True
        if not p:
            return not s
        i, j = 0, 0
        c = None
        while i < len(p):
            if p[i] == '.':
                c = s[i]
                i = i + 1
                j = j + 1
                if p[i] == '*':
                    i = i + 1
                    while j < len(s) and s[j] == c:
                        j = j + 1
            else:
                if p[i] != s[j]:
                    return False
        return isMatch


s = "aa"
p = "a"
sol = Solution()
print(sol.isMatch(s, p))

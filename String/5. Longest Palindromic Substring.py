class RecursiveSolution(object):

    def palindrom(self, s, i, j):
        if i == j:
            return True
        elif j == i+1 and s[i] == s[j]:
            return True
        elif self.cache[i][j] != -1:
            return self.cache[i][j]
        else:
            return s[i] == s[j] and self.palindrom(s, i + 1, j - 1)

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        max_len = 0
        max_str = ""
        for i in range(len(s)):
            for j in range(i, len(s)):
                if self.palindrom(s, i, j):
                    max_len = max(max_len, j - i + 1)
                    if max_len == j - i + 1:
                        max_str = s[i:j + 1]
        return max_str

    def longestPalindromewithhash(self, s):
        """
        :type s: str
        :rtype: str
        """
        self.cache = [[-1 for _ in range(len(s))] for _ in range(len(s))]
        max_len = 0
        max_str = ""
        for i in range(len(s)):
            for j in range(i, len(s)):
                if self.cache[i][j] == -1:
                    self.cache[i][j] = int(self.palindrom(s, i, j))
                if self.cache[i][j]:
                    max_len = max(max_len, j - i + 1)
                    if max_len == j - i + 1:
                        max_str = s[i:j + 1]
        return max_str


class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        max_len = 0
        max_str = ""
        for i in range(len(s)):
            l, r = i, i
            while l >= 0 and r < len(s) and s[l] == s[r]:
                if r - l + 1 >= max_len:
                    max_len = r - l + 1
                    max_str = s[l: r+1]
                l -= 1
                r += 1

            l, r = i, i+1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                if r - l + 1 >= max_len:
                    max_len = r - l + 1
                    max_str = s[l: r+1]
                l -= 1
                r += 1
        return max_str


s = RecursiveSolution()
print(s.longestPalindromewithhash("babad"))  # 3
print(s.longestPalindromewithhash("cbbd"))  # 3

s = Solution()
print(s.longestPalindrome("babad"))  # 3
print(s.longestPalindrome("cbbd"))  # 3

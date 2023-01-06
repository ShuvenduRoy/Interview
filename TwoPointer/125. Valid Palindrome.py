class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = s.lower().strip()
        if len(s) < 2:
            return True
        start, end = 0, len(s) - 1
        while start < end:
            while not s[start].isalnum() and start < end:
                start += 1
            while not s[end].isalnum() and start < end:
                end -= 1
            if s[start] != s[end]:
                return False
            start += 1
            end -= 1
        return True


s = Solution()
print(s.isPalindrome('A man, a plan, a canal: Panama'))
print(s.isPalindrome('.,'))
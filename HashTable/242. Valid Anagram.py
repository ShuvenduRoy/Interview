class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        for a in set(s):
            if s.count(a) != t.count(a):
                return False
        return len(s) == len(t)


s = Solution()
print(s.isAnagram('anagram', 'nagaram'))
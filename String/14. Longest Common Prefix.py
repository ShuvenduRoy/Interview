class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        smallest = min(strs, key=len)
        result = 0
        for i in range(len(smallest)):
            for j in range(len(strs)):
                if not strs[j].startswith(smallest[:i+1]):
                    return smallest[:i]
        return smallest


s = Solution()
print(s.longestCommonPrefix(["flower","flow","flight"]))
print(s.longestCommonPrefix([""]))
print(s.longestCommonPrefix(["a"]))
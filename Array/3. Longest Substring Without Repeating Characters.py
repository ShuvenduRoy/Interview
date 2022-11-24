class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        index_arr = {}
        max_len = 0
        current_start = 0
        for i in range(len(s)):
            c = s[i]
            if c in index_arr and index_arr[c] >= current_start:
                max_len = max(max_len, i - current_start)
                current_start = index_arr[c] + 1
            elif i == len(s) - 1:
                max_len = max(max_len, i - current_start + 1)
            index_arr[c] = i
        return max_len

s = Solution()
print(s.lengthOfLongestSubstring("abba"))  # 2
print(s.lengthOfLongestSubstring("abcabcbb"))  # 3
print(s.lengthOfLongestSubstring("abc"))  # 3
print(s.lengthOfLongestSubstring("tmmzuxt"))  # 5
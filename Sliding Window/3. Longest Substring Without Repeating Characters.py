#
# class Solution:
#     def lengthOfLongestSubstring(self, s: str) -> int:
#         if not s:
#             return 0
#         max_length = 0
#         left, right = 0, 1
#         while right < len(s):
#             if s[right] in s[left:right]:
#                 left = max(left, s.index(s[right], left, right) + 1)
#             else:
#                 max_length = max(max_length, right-left+1)
#             right += 1
#         return max_length

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        left, right = 0, 1
        max_len = 1
        dict = {s[0]: 0}
        while right < len(s):
            if s[right] in dict:
                max_len = max(max_len, right -left)
                left = max(left, dict[s[right]] + 1)
                dict[s[right]] = right
            else:
                dict[s[right]] = right
            right += 1
        return max(max_len, right -left)

s = Solution()
print(s.lengthOfLongestSubstring("abcabcbb"))
print(s.lengthOfLongestSubstring("pwwkew"))
print(s.lengthOfLongestSubstring("au"))
print(s.lengthOfLongestSubstring("abba"))

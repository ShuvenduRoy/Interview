class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left, right, next_start, max_len = 0, 0, 0, 0
        while right<len(s)-1 or len(s) - left > max_len:
            right, next_start, remaining_k = left + 1, left, k
            while True:
                if s[right] == s[left]:
                    right += 1
                    if right >= len(s):
                        max_len = max(max_len, right - left)
                        break
                else:
                    if remaining_k == k:
                        next_start = right
                    if remaining_k == 0:
                        max_len = max(max_len, right-left)
                        left = next_start
                        break
                    elif right >= len(s) -1:
                        max_len = max(max_len, right-left+1)
                        left = next_start
                        break
                    remaining_k -= 1
                    right += 1
                if right >= len(s):
                    break

        return max_len

s = Solution()
print(s.characterReplacement("ABAB", 2))
print(s.characterReplacement("AABABBA", 1))
print(s.characterReplacement("AAAA", 1))
print(s.characterReplacement("AAAB", 0))

# https://leetcode.com/problems/longest-consecutive-sequence/

class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        nums_set = set(nums)
        max_length = 0
        for n in nums:
            if n -1 not in nums_set:
                current_len = 1
                while n + 1 in nums_set:
                    current_len += 1
                    n += 1
                max_length = max(max_length, current_len)
        return max_length
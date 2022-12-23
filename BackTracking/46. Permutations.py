# https://leetcode.com/problems/permutations/

class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        results = []
        if len(nums) == 1:
            return [nums[:]]

        for i in range(len(nums)):
            c = nums.pop(0)
            for p in self.permute(nums):
                p.append(c)
                results.append(p)
            nums.append(c)

        return results


s = Solution()
print(s.permute([1,2,3]))

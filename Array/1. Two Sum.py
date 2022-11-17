class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        key_dict = {}
        for i, n in enumerate(nums):
            if n in key_dict:
                return [key_dict[n], i]
            else:
                key_dict[target - n] = i


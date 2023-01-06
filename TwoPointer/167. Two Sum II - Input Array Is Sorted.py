# https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        start, end = 0, len(numbers) -1
        while start <= end:
            sum = numbers[start] + numbers[end]
            if sum < target:
                start += 1
            elif sum > target:
                end -= 1
            else:
                return [start+1, end+1]
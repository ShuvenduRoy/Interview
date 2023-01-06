# https://leetcode.com/problems/product-of-array-except-self/

class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        contains_zero = False
        total_product = 1
        for n in nums:
            if n == 0:
                if contains_zero:
                    return [0] * len(nums)
                else:
                    contains_zero = True
            else:
                total_product *= n

        result = []
        for n in nums:
            if n == 0:
                result.append(total_product)
            else:
                if contains_zero:
                    result.append(0)
                else:
                    result.append(total_product / n)
        return result
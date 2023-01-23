from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        i = 0
        for i in range(1, len(nums)):
            if nums[i] < nums[i-1]:
                nums = nums[i:] + nums[:i]
                break

        left, right = 0, len(nums)-1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] < nums[mid-1]:
                return nums[mid]
            elif nums[mid] < nums[right]:
                right = mid - 1
            else:
                left = mid + 1

s = Solution()
print(s.findMin([3,4,5,1,2]))

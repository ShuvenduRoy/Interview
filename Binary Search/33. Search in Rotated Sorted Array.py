from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        padding = 0
        for i in range(1, len(nums)):
            if nums[i] < nums[i-1]:
                nums = nums[i:] + nums[:i]
                padding = i
                break

        left, right = 0, len(nums)-1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return (mid + padding) % len(nums)
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid -1
        return -1


s = Solution()
print(s.search([4,5,6,7,0,1,2], 0))
print(s.search([1], 0))
print(s.search([1,3], 1))

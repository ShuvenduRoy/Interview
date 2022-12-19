class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        closest = float('inf')
        distance = float('inf')
        for i, a in enumerate(nums):
            l, r = i + 1, len(nums) - 1
            while l < r:
                total = a + nums[l] + nums[r]
                if abs(target - total) < distance:
                    distance = abs(target - total)
                    closest = total
                if total > target:
                    r -= 1
                elif total < target:
                    l += 1
                else:
                    return closest
        return closest


s = Solution()
print(s.threeSumClosest([-1, 2, 1, -4], 1))
print(s.threeSumClosest([0, 0, 0], 1))
print(s.threeSumClosest([0, 1, 2], 3))

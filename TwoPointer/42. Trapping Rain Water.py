# https://leetcode.com/problems/trapping-rain-water/

class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if len(height) < 3:
            return 0
        left_max = [0] * len(height)
        right_max = [0] * len(height)
        for i in range(1, len(height)):
            left_max[i] = max(left_max[i-1], height[i-1])
        for i in range(len(height)-2, -1, -1):
            right_max[i] = max(right_max[i+1], height[i+1])

        water_amount = 0
        for i in range(len(height)):
            water_amount += max(0, min(left_max[i], right_max[i]) - height[i])
        return water_amount
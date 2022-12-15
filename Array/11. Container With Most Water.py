class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        maxarea = 0
        i, j = 0, len(height) - 1
        while i < j:
            area = min(height[i], height[j]) * (j - i)
            maxarea = max(maxarea, area)
            if height[i] < height[j]:
                i = i + 1
            else:
                j = j - 1
        return maxarea

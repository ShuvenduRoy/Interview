# https://leetcode.com/problems/car-fleet/

class Solution(object):
    def carFleet(self, target, position, speed):
        """
        :type target: int
        :type position: List[int]
        :type speed: List[int]
        :rtype: int
        """
        if not position:
            return 0
        cars = sorted(zip(position, speed), reverse=True)
        stack = []
        for p, s in cars:  # Reverse Sorted Order
            stack.append((target - p) / s)
            if len(stack) >= 2 and stack[-1] <= stack[-2]:
                stack.pop()
        return len(stack)


s = Solution()
print(s.carFleet(12, [10, 8, 0, 5, 3], [2, 4, 1, 1, 3]))
print(s.carFleet(10, [6,8], [3,2]))
# https://leetcode.com/problems/daily-temperatures/

class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        results = [0] * len(temperatures)
        stack = []
        for i, t in enumerate(temperatures):
            while stack and temperatures[i] > stack[-1][0]:
                results[stack[-1][1]] = i - stack[-1][1]
                stack.pop()
            stack.append([t, i])
        return results


s = Solution()
print(s.dailyTemperatures([73, 74, 75, 71, 69, 72, 76, 73]))
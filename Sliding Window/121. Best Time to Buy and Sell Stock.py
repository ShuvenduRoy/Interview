from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        max_profit = 0
        left, right = 0, 1
        while right < len(prices):
            if prices[right] < prices[left]:
                left = right
            else:
                max_profit = max(max_profit, prices[right]-prices[left])
            right += 1
        return max_profit


s = Solution()
print(s.maxProfit([7,1,5,3,6,4]))

# https://leetcode.com/problems/koko-eating-bananas/
from typing import List


class Solution:
    def ceil(self, a, b):
        return (a + b - 1) // b

    def can_eat(self, piles, h, k):
        return sum(self.ceil(p, k) for p in piles)

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # brute force solution
        # for i in range(1, max(piles) + 1):
        #     if self.can_eat(piles, h, i):
        #         return i
        left, right = 1, max(piles)
        min_hour = right
        while left <= right:
            mid = (left + right) // 2
            if self.can_eat(piles, h, mid) <= h:
                min_hour = mid
                right = mid - 1
            else:
                left = mid + 1

        return min_hour



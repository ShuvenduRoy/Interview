# https://leetcode.com/problems/search-a-2d-matrix/
from typing import List


class Solution:
    def binarySearch(self, row, target):
        left, right = 0, len(row)
        while left <= right:
            mid = (left + right) // 2
            if row[mid] == target:
                return True
            elif row[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return False

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        left, right = 0, len(matrix) - 1
        while left <= right:
            mid = (left + right) // 2
            if matrix[mid][0] <= target <= matrix[mid][len(matrix[mid]) - 1]:
                return self.binarySearch(matrix[mid], target)
            elif matrix[mid][0] <= target:
                left = mid + 1
            else:
                right = mid - 1
        return False

s= Solution()
print(s.searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]], 3))
print(s.searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]], 13))
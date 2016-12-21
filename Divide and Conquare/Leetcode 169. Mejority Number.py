import collections
class Solution(object):
    def majorityElement(self, nums):
        newCounted = collections.Counter(nums)
        return newCounted.most_common(1)[0][0]

testArr = [1,2,2,3,4,4,4,5]
s = Solution()
s.majorityElement(testArr)
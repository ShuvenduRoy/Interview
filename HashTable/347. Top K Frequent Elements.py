# https://leetcode.com/problems/top-k-frequent-elements/

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        count_dict = {}
        for n in nums:
            if n in count_dict:
                count_dict[n] += 1
            else:
                count_dict[n] = 1
        values = set(sorted(count_dict.values(), reverse=True)[:k])
        result = []
        for key, value in count_dict.items():
            if value in values:
                result.append(key)
        return result


s = Solution()
print(s.topKFrequent([1,1,1,2,2,3], 2))



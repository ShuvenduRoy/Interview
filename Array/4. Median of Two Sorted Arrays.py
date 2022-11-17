class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        new_list = []
        i, j = 0, 0
        n, m = len(nums1), len(nums2)
        while i < n and j < m:
            if nums1[i] < nums2[j]:
                new_list.append(nums1[i])
                i += 1
            else:
                new_list.append(nums2[j])
                j += 1
        while i < n:
            new_list.append(nums1[i])
            i += 1
        while j < m:
            new_list.append(nums2[j])
            j += 1

        if len(new_list) % 2 == 0:
            return (new_list[len(new_list) // 2] + new_list[len(new_list) // 2 - 1]) / 2.0
        else:
            return new_list[len(new_list) // 2]
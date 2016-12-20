import math
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        l1 = len(nums1)
        l2 = len(nums2)
        newList = []
        i,j=0,0
        while(i<l1 and j<l2):
            if nums1[i] < nums2[j]:
                newList.append(nums1[i])
                i+=1;
            else:
                newList.append(nums2[j])
                j+=1;

        while(i<l1):
            newList.append(nums1[i])
            i += 1;

        while(j<l2):
            newList.append(nums2[j])
            j += 1;

        # newSet = set(newList)
        # n = len(newSet)
        # newList = sorted(list(newSet))

        n = len(newList)
        if n%2==0:
            n = int(n/2)
            return (newList[n] *1.0 + newList[n-1] * 1.0)/2
        else:
            return newList[int(math.floor(n/2))]*1.0

nums1 = [4,5,6,7,8]
nums2 = []
s = Solution()
print(s.findMedianSortedArrays(nums1,nums2))
# https://leetcode.com/problems/group-anagrams/

class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        d = {}
        for s in strs:
            word_hash = {}
            for a in s:
                if a in word_hash:
                    word_hash[a] += 1
                else:
                    word_hash[a] = 1
            str_hash = ''
            for a in sorted(word_hash):
                str_hash += a + str(word_hash[a])
            if str_hash in d:
                d[str_hash].append(s)
            else:
                d[str_hash] = [s]
        return d.values()

s = Solution()
print(s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
class Solution:
    def checkDict(self, dict_s1, dict_s2):
        for key in dict_s1:
            if key not in dict_s2 or dict_s1[key] != dict_s2[key]:
                return False
        return True

    def checkInclusion(self, s1: str, s2: str) -> bool:
        # init dict
        dict_s1 = {}
        for c in s1:
            if c in dict_s1:
                dict_s1[c] += 1
            else:
                dict_s1[c] = 1
        dict_s2 = {}
        left, right = 0, len(s1)
        for c in s2[:right]:
            if c in dict_s2:
                dict_s2[c] += 1
            else:
                dict_s2[c] = 1
        if self.checkDict(dict_s1, dict_s2):
            return True

        while right < len(s2):
            # remove left from dict
            dict_s2[s2[left]] -= 1
            # add new right to dict
            if s2[right] in dict_s2:
                dict_s2[s2[right]] += 1
            else:
                dict_s2[s2[right]] = 1
            # check if dict_s1 == dict_s2
            if self.checkDict(dict_s1, dict_s2):
                return True
            left += 1
            right += 1
        return False

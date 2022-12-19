class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        key_map = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        res = []

        def back_track(pointer, curStr):
            if len(curStr) == len(digits):
                res.append(curStr)
                return
            for c in key_map[digits[pointer]]:
                back_track(pointer+1, curStr+c)
        if digits:
            back_track(0, '')
        return res

s = Solution()
print(s.letterCombinations('23'))
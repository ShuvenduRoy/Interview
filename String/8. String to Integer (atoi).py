class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.strip()
        if not s:
            return 0
        if s[0] == '-':
            sign = -1
        else:
            sign = 1
        if s[0] in ['-', '+']:
            s = s[1:]

        res = 0
        for c in s:
            if c.isdigit():
                res = res * 10 + int(c)
            else:
                break
        return max(-2**31, min(sign * res, 2**31 - 1))
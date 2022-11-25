class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        ans = 0
        is_neg = False
        if x < 0:
            is_neg = True
            x = -x
        while x > 0:
            ans = ans * 10 + x % 10
            x = x // 10
        if is_neg:
            ans = -ans
        return ans if -2**31 <= ans <= 2**31 - 1 else 0
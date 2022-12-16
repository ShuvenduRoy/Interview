class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        key_dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000, 'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900}
        key_list = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
        result = 0
        while s:
            for key in key_list:
                if s.startswith(key):
                    result += key_dict[key]
                    s = s[len(key):]
                    break
        return result

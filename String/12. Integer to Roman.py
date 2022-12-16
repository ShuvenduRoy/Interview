class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        key_dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000, 'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900}
        key_list = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
        result = ''
        while num > 0:
            for key in key_list:
                if num >= key_dict[key]:
                    result += key
                    num -= key_dict[key]
                    break
        return result


s = Solution()
print(s.intToRoman(3))
print(s.intToRoman(4))
print(s.intToRoman(9))
print(s.intToRoman(58))
print(s.intToRoman(1994))
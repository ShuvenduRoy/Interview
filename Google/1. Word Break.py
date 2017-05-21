# Given an input string and a dictionary of words, find out if the input string can be segmented into a
# space-separated sequence of dictionary words. See following examples for more details. This is a famous Google
# interview question, also being asked by many other companies now a days.
#
# Consider the following dictionary
# { i, like, sam, sung, samsung, mobile, ice,
#   cream, icecream, man, go, mango}
#
# Input:  ilike
# Output: Yes
# The string can be segmented as "i like".
#
# Input:  ilikesamsung
# Output: Yes
# The string can be segmented as "i like samsung" or "i like sam sung".

class WB:
    @staticmethod
    def check(str):
        dictionary = ["mobile", "samsung", "sam", "sung", "man", "mango", "icecream", "and", "go", "i", "like", "ice", "cream"]

        n = len(str)
        if n==0:
            return True

        wb = [False] * (n+1)

        for i in range(1, n+1):
            if wb[i] == False and str[0:i] in dictionary:
                wb[i] = True

            if wb[i]:
                if i == n:
                    return True
                for j in range (i+1, n+1):
                    if wb[j] == False and str[i:j] in dictionary:
                        wb[j] = True

                    if j == n and wb[j] == True:
                        return True

        return False

print(WB.check('iliked'))
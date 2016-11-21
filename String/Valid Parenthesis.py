class Solution(object):
    def isValid(self, s):

        n = len(s)
        stack = []

        for i in range(n):
            if s[i]=='(' or s[i]=='{' or s[i]=='[':
                stack.append(s[i])
            else:
                if len(stack)==0:
                    return False
                else:
                    x = stack.pop()


                if s[i] == ')' and x=='(':
                    continue
                elif s[i] == '}' and x=='{':
                    continue
                elif s[i] == ']' and x=='[':
                    continue
                else:
                    return False

        if len(stack)==0:
            return True
        else:
            return False


text = '()([])'
s = Solution()
print(s.isValid(text))
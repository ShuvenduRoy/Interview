class Solution(object):
    def longestValidParentheses(self, s):
        n = len(s)

        stk = []
        stk.append(-1)

        result = 0

        for i in range(n):
            if s[i]=='(':
                stk.append(i)

            else:
                stk.pop()

                if len(stk) !=0 :
                    result = max(result, i-stk[len(stk)-1])
                else:
                    stk.append(i)

        return result
text = '()()'
s = Solution()
print(s.longestValidParentheses(text))
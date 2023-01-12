class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """

        def generateParenthesisHelper(currentStack, left, right):
            if left == right == n:
                result.append(''.join(currentStack))
                return
            if right == left:
                currentStack.append('(')
                generateParenthesisHelper(currentStack, left + 1, right)
                currentStack.pop()
            else:
                if left < n:
                    currentStack.append('(')
                    generateParenthesisHelper(currentStack, left + 1, right)
                    currentStack.pop()
                    currentStack.append(')')
                    generateParenthesisHelper(currentStack, left, right + 1)
                    currentStack.pop()
                else:
                    currentStack.append(')')
                    generateParenthesisHelper(currentStack, left, right + 1)
                    currentStack.pop()

        result = []
        currentStack = ['(']

        generateParenthesisHelper(currentStack, 1, 0)
        return result

s = Solution()
print(s.generateParenthesis(3))
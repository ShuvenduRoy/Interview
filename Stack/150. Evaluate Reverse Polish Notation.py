# https://leetcode.com/problems/evaluate-reverse-polish-notation/
from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        """
        :type tokens: List[str]
        :rtype: int
        """
        total = 0
        stack = []
        for token in tokens:
            if token in ['+', '-', '*', '/']:
                right = stack.pop()
                left = stack.pop()
                if token == '+':
                    total = left + right
                elif token == '-':
                    total = left - right
                elif token == '*':
                    total = left * right
                elif token == '/':
                    total = int(left / right)
                stack.append(total)
            else:
                stack.append(int(token))
        return stack.pop()

s = Solution()
print(s.evalRPN(["2", "1", "+", "3", "*"]))
print(s.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]))
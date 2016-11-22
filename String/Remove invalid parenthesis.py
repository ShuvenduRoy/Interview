class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]

        Idea is to use dfs
        """

        def dfs(s):
            mi = calc(s)                            # getting total number of miss match in the giver string
            # if miss match is 0, means it is a solution, so we return it as a set
            if mi==0:
                return [s]

            # final answer storing variable
            ans=[]
            for x in range (len(s)):
                if s[x] in ('(', ')'):
                    # (KEY IDEA) try to find all string excluding current one, and find if it has less miss match
                    # if so, try to start dfs from it
                    ns = s[:x] + s[x+1:]
                    if ns not in visited and calc(ns)<mi:
                        # it means it has got a less miss match string, so it will try to find solution in it
                        # but one thin to notice here is, it will not come this stage when it will find a solution, it will return from top
                        # so, try to find solution that has length less than already found solution is not impossible
                        # it will sustain the requirment for removing minimum number of parenthesis
                        visited.add(ns)
                        ans.extend(dfs(ns))         # When we get one with less miss match we start searching with it

            return ans

        # Returns total number of miss match
        def calc(s):
            a = b = 0
            for c in s:
                a += {'(' : 1, ')':-1}.get(c,0)     # here dict for (=1, and )=-1 with other =0
                b += a<0                            # a for '(' miss match, b or ')" miss match
                a = max(a,0)
            return a+b
            # Point here is, we can't just return abs(a)
            # it will make error calculation in case of input like this, ()())(

        visited = set([s])
        return dfs(s)


text = '()())'
s = Solution()
print(s.removeInvalidParentheses(text))
# https://leetcode.com/problems/word-search/


class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        row, col = len(board), len(board[0])
        currentPath = set()

        def backTrack(r, c, i):
            if i == len(word):
                return True
            if r < 0 or r >= row or c < 0 or c >= col or (r, c) in currentPath or board[r][c] != word[i]:
                return False
            currentPath.add((r, c))
            res = backTrack(r+1, c, i+1) or backTrack(r-1, c, i+1) or backTrack(r, c+1, i+1) or backTrack(r, c-1, i+1)
            currentPath.remove((r, c))
            return res

        for r in range(row):
            for c in range(col):
                if backTrack(r, c, 0):
                    return True
        return False


s = Solution()
s.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], 'ABCCED')
s.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], 'SEE')
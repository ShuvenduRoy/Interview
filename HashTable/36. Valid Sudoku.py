# https://leetcode.com/problems/valid-sudoku/

class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for i in range(9):
            current_set = set()
            for j in range(9):
                if board[i][j] != '.':
                    if board[i][j] in current_set:
                        return False
                    else:
                        current_set.add(board[i][j])
        for j in range(9):
            current_set = set()
            for i in range(9):
                if board[i][j] != '.':
                    if board[i][j] in current_set:
                        return False
                    else:
                        current_set.add(board[i][j])

        for i in range(3):
            for j in range(3):
                current_set = set()
                for k in range(3):
                    for l in range(3):
                        if board[3*i+k][3*j+l] != '.':
                            if board[3*i+k][3*j+l] in current_set:
                                return False
                            else:
                                current_set.add(board[3*i+k][3*j+l])
        return True
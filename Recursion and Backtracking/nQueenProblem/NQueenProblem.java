package nQueenProblem;

import java.util.Arrays;

public class NQueenProblem {
	
	class Position{
		int row,col;
		Position(int r, int c){
			row = r;
			col = c;
		}
	}
	
	public Position[] solveNQueen(int n){
		Position position[] = new Position[n];
		boolean hasSolution = solveNQueenUtil(n,0,position);
		
		if(hasSolution){
			return position;
		}else{
			return new Position[0];
		}
	}
	
	private boolean solveNQueenUtil(int n, int row, Position[] position){
		if(n == row)
			return true;
		
		int col;
		for(col=0; col<n; col++){
			boolean foundSafe = true;
			
			for(int queen = 0; queen<row; queen++){
				if(position[queen].col == col || position[queen].row - position[queen].col == row-col || position[queen].row + position[queen].col == row+col){
					foundSafe = false;
					break;
				}
			}
			
			if(foundSafe){
				position[row] = new Position(row, col);
				if(solveNQueenUtil(n, row + 1, position)){
					return true;
				}
			}
		}
		return false;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		NQueenProblem s = new NQueenProblem();
		Position[] positions = s.solveNQueen(6);
		Arrays.stream(positions).forEach(position -> System.out.println(position.row + " "+position.col));
	}

}

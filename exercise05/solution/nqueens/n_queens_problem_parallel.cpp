#include <iostream>  // std::cout, cin, cerr ...
#include <iomanip>   // modify std::out
#include <omp.h>

void setQueen_parallel(int queens[], int row, int col, int size, int &numberOfSolutions) {
	//check all previously placed rows for attacks
	for(int i=0; i<row; i++) {
	   // vertical attacks
	   if (queens[i]==col) {
		   return;
	   }

	   // diagonal attacks
	   if (abs(queens[i]-col) == (row-i) ) {
		  return;
	   }
	}

	// column is ok, set the queen
	queens[row]=col;
	if(row==size-1) {
		#pragma omp atomic
		numberOfSolutions++;  //Placed final queen, found a solution
	}
	else {
		 // try to fill next row
		 for(int i=0; i<size; i++) {
			 setQueen_parallel(queens, row+1, i, size, numberOfSolutions);
		 }
	}
}

//Function to find all solutions for nQueens problem on size x size chessboard.
int solve_parallel(int size) {
	int numberOfSolutions = 0;
	#pragma omp parallel for
    for(int i=0; i<size; i++) {
         // try all positions in first row
         int * queens = new int[size];  //array representing queens placed on a chess board.  Index is row position, value is column.
         setQueen_parallel(queens, 0, i, size, numberOfSolutions);
         delete[](queens);
     }
     return numberOfSolutions;
}

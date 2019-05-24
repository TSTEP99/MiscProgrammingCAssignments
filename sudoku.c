#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int SudokuBoard[9][9];
void printBoard(int board[9][9]);
int emptyLocation(int board[9][9],int l[2]);
int possibleEntry(int board[9][9],int i, int j,int num);
int sudokuSolver(int board[9][9]);

int main()
{
SudokuBoard[0][0] = 9;
SudokuBoard[0][1] = 5;
SudokuBoard[0][2] = 0;
SudokuBoard[0][3] = 8;
SudokuBoard[0][4] = 2;
SudokuBoard[0][5] = 7;
SudokuBoard[0][6] = 0;
SudokuBoard[0][7] = 0;
SudokuBoard[0][8] = 0;
SudokuBoard[1][0] = 0;
SudokuBoard[1][1] = 2;
SudokuBoard[1][2] = 1;
SudokuBoard[1][3] = 0;
SudokuBoard[1][4] = 0;
SudokuBoard[1][5] = 0;
SudokuBoard[1][6] = 8;
SudokuBoard[1][7] = 9;
SudokuBoard[1][8] = 3;
SudokuBoard[2][0] = 0;
SudokuBoard[2][1] = 6;
SudokuBoard[2][2] = 0;
SudokuBoard[2][3] = 1;
SudokuBoard[2][4] = 0;
SudokuBoard[2][5] = 0;
SudokuBoard[2][6] = 7;
SudokuBoard[2][7] = 0;
SudokuBoard[2][8] = 2;
SudokuBoard[3][0] = 0;
SudokuBoard[3][1] = 8;
SudokuBoard[3][2] = 0;
SudokuBoard[3][3] = 0;
SudokuBoard[3][4] = 0;
SudokuBoard[3][5] = 4;
SudokuBoard[3][6] = 0;
SudokuBoard[3][7] = 1;
SudokuBoard[3][8] = 9;
SudokuBoard[4][0] = 0;
SudokuBoard[4][1] = 0;
SudokuBoard[4][2] = 5;
SudokuBoard[4][3] = 0;
SudokuBoard[4][4] = 7;
SudokuBoard[4][5] = 0;
SudokuBoard[4][6] = 3;
SudokuBoard[4][7] = 0;
SudokuBoard[4][8] = 0;
SudokuBoard[5][0] = 2;
SudokuBoard[5][1] = 3;
SudokuBoard[5][2] = 0;
SudokuBoard[5][3] = 5;
SudokuBoard[5][4] = 0;
SudokuBoard[5][5] = 0;
SudokuBoard[5][6] = 0;
SudokuBoard[5][7] = 7;
SudokuBoard[5][8] = 0;
SudokuBoard[6][0] = 5;
SudokuBoard[6][1] = 0;
SudokuBoard[6][2] = 6;
SudokuBoard[6][3] = 0;
SudokuBoard[6][4] = 0;
SudokuBoard[6][5] = 2;
SudokuBoard[6][6] = 0;
SudokuBoard[6][7] = 3;
SudokuBoard[6][8] = 0;
SudokuBoard[7][0] = 3;
SudokuBoard[7][1] = 9;
SudokuBoard[7][2] = 4;
SudokuBoard[7][3] = 0;
SudokuBoard[7][4] = 0;
SudokuBoard[7][5] = 0;
SudokuBoard[7][6] = 2;
SudokuBoard[7][7] = 8;
SudokuBoard[7][8] = 0;
SudokuBoard[8][0] = 0;
SudokuBoard[8][1] = 0;
SudokuBoard[8][2] = 0;
SudokuBoard[8][3] = 3;
SudokuBoard[8][4] = 4;
SudokuBoard[8][5] = 9;
SudokuBoard[8][6] = 0;
SudokuBoard[8][7] = 6;
SudokuBoard[8][8] = 5;

printBoard(SudokuBoard);

sudokuSolver(SudokuBoard);
printf("\n");

printBoard(SudokuBoard);

}

void printBoard(int board[9][9])// prints the board;
{
	int i;
	int j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}

int emptyLocation(int board[9][9], int l[2])
{
	int i;
	int j;
	
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if (board[i][j]==0)
			{
				l[0]=i;
				l[1]=j;
				return 1;
			}
		}
	}
	
	return 0;
}

int possibleEntry(int board[9][9], int i, int j, int num)
{
	int y;
	int x;
	
	for(y=0;y<9;y++)
	{
		if (board[i][y]==num)
		{
			return 0;
		}
	}
	
	for(x=0;x<9;x++)
	{
		if (board[x][j]==num)
		{
			return 0;
		}
	}
	
	int k=i-i%3;
	int l=j-j%3;
	
	for(y=0;y<3;y++)
	{
		for(x=0;x<3;x++)
		{
			if (board[k+x][l+y]==num)
			{
				return 0;	
			}
		}
	}
	
	return 1;
	
}

int sudokuSolver(int board[9][9])
{
	int l[2];
	if(!emptyLocation(board,l))
	{
		return 1;
	}
	
	int i=l[0];
	int j=l[1];
	
	int num;
	
	for(num=1;num<10;num++)
	{
		if(possibleEntry(board,i,j,num))
		{
			board[i][j]=num;
			
			if(sudokuSolver(board))
			{
				return 1;
			}
			
			board[i][j]=0;
			
		}
		
	}
	
	return 0;
}
#include <iostream>
#include <string.h>
#include <list>



using namespace std;

extern int boardArray[8][8];





class position
{
	private:
	int posX;//first argument for array
	int posY;//Second Argument for array
	int pieceNum;//tells the piece number assigned to it
	
	public:
	int GetX(){return posX;}//return x,y and age
	int GetY(){return posY;}
	int GetPiece(){return pieceNum;}
	void SetX(int x);//sets x,y and age
	void SetY(int y);
	void SetPiece(int num);//X,Y must be set before this can be used
	void SetPos(int x,int y);//Sets the board to new position while getting ride of the old;
		
};



void position::SetPos(int x,int y)
{
	boardArray[posX][posY]=0;
	posX=x;
	posY=y;
	
	boardArray[x][y]=pieceNum;
	
}

void position::SetX(int x)
{

	posX=x;
	
}

void position::SetY(int y)
{

	posY=y;

}

void position::SetPiece (int num)
{
	boardArray[posX][posY]=0;
	pieceNum=num;
	boardArray[posX][posY]=pieceNum;
}
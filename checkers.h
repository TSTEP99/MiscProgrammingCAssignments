#include <iostream>
#include <string>
#include <list>

int boardArray[8][8];

enum Pieces {PAWN,KNIGHT,BISHOP,ROOK,QUEEN,KING};


using namespace std;
//Start of position class
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

//End of position class

//start of piece class
class piece
{
	private:
    position Location;//tells position of piece
	unsigned team :1;//tells whether belongs to player 1 or 2
	
	public:
	int GetpieceNum(){return Location.GetPiece();}
	void SetLocation(int x,int y,int num);
	piece(int x,int y,int num,unsigned tnum);
	~piece();
	int move(int x,int y);
	bool operator==(piece& compPiece) 
	{
		return (this->GetpieceNum())==(compPiece.GetpieceNum());
	}
};
int piece::move(int x,int y)
{
	
	
	
}
void piece::SetLocation(int x,int y,int num)
{
	Location.SetX(x);
	Location.SetY(y);
	Location.SetPiece(num);//sets the piece to new position;
	
}

piece::piece(int x,int y,int num,unsigned tnum)
{
	Location.SetX(x);//initializes location
	Location.SetY(y);
	Location.SetPiece(num);
	team=tnum;
}

piece::~piece()
{
	cout<<"piece is killed"<<endl;
	Location.SetPiece(0);
	
}


//end of piece class


int main()
{
	list <piece> listpiece;
	
	
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			cout.width(2);
			cout<<boardArray[i][j];
			
		}
			
		cout<<endl;
	}

	

}
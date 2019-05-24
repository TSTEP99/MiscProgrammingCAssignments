#include <iostream>
#include <string.h>
#include <list>
#include <cmath>


#define NAME(x) piece ##x
#define DEBUG

#ifdef DEBUG
#define ASSERT(x)\
if(x)\
{\
cout<<"Error has occured"<<endl;\
}
#endif

using namespace std;
int boardArray[8][8];

bool check(int x, int y);


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
	//boardArray[posX][posY]=0;
	pieceNum=num;
	boardArray[posX][posY]=pieceNum;
}

//End of position class

//start of piece class
class piece
{
	protected:
    position Location;//tells position of piece
	unsigned team :1;//tells whether belongs to player 1 or 2
	
	public:
	int GetX(){return Location.GetX();}
	int GetY(){return Location.GetY();}
	int GetpieceNum(){return Location.GetPiece();}
	void SetLocation(int x,int y,int num);//used for initialization of the board
	piece(int x,int y,int num,unsigned tnum);
	virtual ~piece();
	virtual int move(int x,int y){cout<<"Piece has moved";};
	bool operator==(piece& compPiece) 
	{
		return (this->GetpieceNum())==(compPiece.GetpieceNum());
	}
};

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

//start of checker class

class checker: public piece
{

public:
int move(int x,int y);	
checker(int x,int y,int num,unsigned tnum):piece(x,y,num,tnum){queen=0;}
~checker(){cout<<"this piece has been killed"<<endl;}

private:

unsigned queen :1; 

	
	
};

int checker::move(int x,int y)
{
	
	//0 top most player
	//1 bottom most player
	
	int posX=Location.GetX();//gets current position of x and y
	int posY=Location.GetY();
	int occup=boardArray[x][y];//find current value
	
	int midx=posX+(x-posX)/2;//calculate middle position if applicable
	int midy=posY+(y-posY)/2;
	int midoccup;
	
	int num;
	
	int sum=0;
	
	int diffx;
	int diffy1;
	int diffy2;
	
	midoccup=boardArray[midx][midy];//determines if middle place occupied
	
	if(x<0||x>7||y<0||y>7)
	{
		cout<<"Invalid Coordinates"<<endl;
		return 1;
	}
	
	if(team==0)
	{
		if(queen==0)
		{
		diffx=x-posX;//checks to see if difference if the difference between the position currently for the piece and requested
		//differ by one or two
		diffy1=y-posY;//sames as above but for both variations of y
		diffy2=posY-y;

		
	
		
		
		
		if((diffx==1)&&((diffy1==1)||(diffy2==1))&&(occup==0))
		{
			Location.SetPos(x,y);
			
			
			if(x==7)
			{
				queen=1;
				num=Location.GetPiece()+200;
				Location.SetPiece(num);
				boardArray[x][y]=num;
				
			}
			
			return 0;
			
		}
		
		else if ((diffx==2)&&((diffy1==2)||(diffy2==2))&&((midoccup>200)&&(midoccup<300)||(midoccup>400)))
		{
			Location.SetPos(x,y);
			
			
			if(x==7)
			{
				queen=1;
				num=Location.GetPiece()+200;
				Location.SetPiece(num);
				boardArray[x][y]=num;
				
			}
			
			return midoccup;
		}
		

		else
		{
			cout<<"Invalid Coordinates"<<endl;
			return 1;
			
		}
		}
		
		else
		{
			diffx= abs(posX-x);
			diffy1=abs(posY-y);
			
			if((diffx==1)&&(diffy1==1)&&(occup==0))
			{
				Location.SetPos(x,y);
				return 0;
			}
			
			else if((diffx==2)&&(diffy1==2)&&((midoccup>200)&&(midoccup<300)||(midoccup>400)))
			{
				Location.SetPos(x,y);
				return midoccup;
				
			}
			
			else
			{
				cout<<"Invalid Coordinates"<<endl;
				return 1;
			}
			
		}
	}
	
	else
	{
		if(queen==0)
		{
		
		diffx=posX-x;
		diffy1=y-posY;
		diffy2=posY-y;
	
		
	
		
		
		
		midoccup=boardArray[midx][midy];//determines if middle place occupied
		
		if((diffx==1)&&((diffy1==1)||(diffy2==1))&&(occup==0))
		{
			Location.SetPos(x,y);
			
	
			
			if(x==0)
			{
				queen=1;
				num=Location.GetPiece()+200;
				Location.SetPiece(num);
				boardArray[x][y]=num;
				
			}
			return 0;
			
		}
		
		else if ((diffx==2)&&((diffy1==2)||(diffy2==2))&&(((midoccup>100)&&(midoccup<200))||((midoccup<400)&&(midoccup>300))))
		{
			Location.SetPos(x,y);
			
			
			if(x==0)
			{
				queen=1;
				num=Location.GetPiece()+200;
				Location.SetPiece(num);
				boardArray[x][y]=num;
				
			}
			
			return midoccup;
		}
		
		else
		{
			cout<<"Invalid"<<endl;
			return 1;
		}
		}
		else
		{
			diffx= abs(posX-x);
			diffy1=abs(posY-y);
			
			if((diffx==1)&&(diffy1==1)&&(occup==0))
			{
				Location.SetPos(x,y);
				return 0;
			}
			
			else if((diffx==2)&&(diffy1==2)&&(((midoccup>100)&&(midoccup<200))||((midoccup<400)&&(midoccup>300))))
			{
				Location.SetPos(x,y);
				return midoccup;
				
			}
			
			else
			{
				cout<<"Invalid Coordinates"<<endl;
				return 1;
			}
			
		}
		
	}
	
}

//end of checker class

//start of player class


class player
{
	private:
	char name[255];
	checker* arraypieces[12];
	unsigned team :1; 
	int pieces;

	
	public:
	int GetPieces(void){return pieces;}
	
	char* GetString(){return name;}
	player(){;}
	player(char string[],unsigned int tnum);
	~player(){;}
	int movepiece(int num,int x,int y);
	int kill(int num);
	
};

int player::kill(int num)//Returns -1 of not found
{
	int x,y,i;
	checker* ptr;
	for(i=0;i<12;i++)
	{
		ptr=arraypieces[i];
		
		if(ptr==NULL)
		{
			continue;
			
		}
		
		if(ptr->GetpieceNum()==num)
		{
			break;
		}
	}
	
	if(ptr->GetpieceNum()!=num)
	{
		cout<<"number not found"<<endl;
		return -1;
	}
	
	x=ptr->GetX();
	y=ptr->GetY();
	
	boardArray[x][y]=0;
	delete ptr;
	arraypieces[i]=NULL;
	pieces--;
	
	return 0;
}


int player::movepiece(int num,int x,int y)//returns -1 if not found
{
	checker* ptr;
	int flag=0;
	
	for(int i=0;i<12;i++)
	{
		ptr=arraypieces[i];
		
		if(ptr==NULL)
		{
			continue;
		}
		
		
		if(ptr->GetpieceNum()==num)
		{
			
			return ptr->move(x,y);

		}
	}
	
	return -1;

}

player::player(char string[],unsigned int tnum)
{
	strcpy(name,string);
	team=tnum;
	pieces=12;
	
	int num;
	int counter=0;
	
	
	if (tnum==0)
	{
	
	
	num=101;//sets the checker board for a player of 0 team
	for(int x=0;x<3;x++)
	{
		for(int y=0;y<8;y++)
		{
			
	        if((((x%2+y%2)==1)))
			{
				arraypieces[counter++]=new checker (x,y,num++,0);
			
			}

		}
	}

	
	
	}
	
	else
	{
	num=201;//sets the checker board for a player of 1 team
	for(int x=5;x<8;x++)
	{
		for(int y=0;y<8;y++)
		{
			if((((x%2+y%2)==1)))
			{
				arraypieces[counter++]=new checker (x,y,num++,1);
			
			}
		}
	}
	}
	

}

//end of player class

//start of board class






int main()
{
	
	
	
	
	
	int turns=0;
	int x,y,num;
	int test;
	char str1[255];
	char str2[255];
	
	cout<<"What is player ones name"<<endl;
	cin.getline(str1,255);
	cout<<"What is player twos name"<<endl;
	cin.getline(str2,255);
	
	
	
	char choice;
	
	player Player0 (str1,0);
	player Player1 (str2,1);
	

	
	while(1)
	{
	
	if((Player0.GetPieces()==0)||(Player1.GetPieces()==0))
		{
			
			cout<<"Game over"<<endl;
			return 1;
		
		}
	
	
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{

			cout.width(4);
			cout<<boardArray[i][j];
			
		}
			
		cout<<endl<<endl;
	}
	
	if(turns%2==0)
	{
		
		cout<<Player0.GetString()<<"'s turn"<<endl;
		
		cout<<"Choose a piece: ";
		cin>>num;
		
		while(1)
		{
		
		cout<<"Choose x-coordinate: ";
		cin>>x;
		
		cout<<"Choose y-coordinate: ";
		cin>>y;
		
	
		test=Player0.movepiece(num,x,y);
		
		cout<<test<<endl;
		if(test==1||test==-1)
		{
			cout<<"Invalid num or coordinates"<<endl;
			break;
		}
		
		//turns++;
		
		if(test>1)
		{
			
			cout<<"yes"<<endl;
			Player1.kill(test);
			
			/*if((Player0.GetPieces()==0)&&(Player1.GetPieces()==0))
			{
			
			cout<<"Game over"<<endl;
			return 0;
		
			}
			*/
			
			
			if(check(x,y))
			{
				cout<<check(x,y)<<endl;
				
				for(int i=0;i<8;i++)
				{
					for(int j=0;j<8;j++)
					{

						cout.width(4);
						cout<<boardArray[i][j];
			
					}
			
		            cout<<endl<<endl;
	            }
				
				cout<<"Would you like to go again"<<endl;
				
				cin>>choice;
				
				if(choice=='n')
				{
					break;
				}
				
				continue;
			}
			
		turns++;
		break;
			
			
		}
		
		else
		{
			turns++;
			break;
		}
		
		}
		
	}
	
	else
	{
		cout<<Player1.GetString()<<"'s turn"<<endl;
		
		cout<<"Choose a piece: ";
		cin>>num;
		
		while(1)
		{
		cout<<"Choose x-coordinate: ";
		cin>>x;
		
		cout<<"Choose y-coordinate: ";
		cin>>y;
		
		test=Player1.movepiece(num,x,y);
		
		cout<<test<<endl;
		
		if(test==1||test==-1)
		{
			cout<<"Invalid num or coordinates"<<endl;
			break;
		}
		
		
		if(test>1)
		{
			
			cout<<"yes"<<endl;
			Player0.kill(test);
			
			
			
			if(check(x,y))//conitues to net teration
			{
				cout<<"why"<<endl;
				
				for(int i=0;i<8;i++)
				{
					for(int j=0;j<8;j++)
					{

						cout.width(4);
						cout<<boardArray[i][j];
			
					}
			
		            cout<<endl<<endl;
	            }
				
				cout<<"Would you like to go again"<<endl;
				
				cin>>choice;
				
				if(choice=='n')
				{
					break;
				}
				
				
				
				
				continue;
			}
			turns++;
			break;
		}			
		else
		{
			turns++;
			break;
		}	
		}
		
		if((Player0.GetPieces()==0)&&(Player1.GetPieces()==0))
		{
			
			cout<<"Game over"<<endl;
			return 1;
		
		}
	
	}
	}
	
}

bool check(int x, int y)//checks to see if another jump can be made
{

	
	if(boardArray[x][y]<113)
	{
		
	if(x>6)
	{
		cout<<__LINE__<<endl;
		return 0;
	}
		
	if((x<6)&&(y<6)&&(y>1))
	{
		/*if((boardArray[x+1][y-1]>200)||(boardArray[x+1][y+1]>200))
		{
			if(	((boardArray[x+2][y-2])==0)||((boardArray[x+2][y+2])==0))
			{
				cout<<__LINE__<<endl;
				return 1;
			}
		}*/
		
		if(((((boardArray[x+1][y-1]>200)&&(boardArray[x+1][y-1]<300))||(boardArray[x+1][y-1]>400)))&&((boardArray[x+2][y-2])==0))
		{
			return 1;
		}
		
		if(((((boardArray[x+1][y+1]>200)&&(boardArray[x+1][y+1]<300))||(boardArray[x+1][y+1]>400)))&&(boardArray[x+2][y+2])==0)
		{
		return 1;
		}
		else
		{
		return 0;
		}
	}
	
	else if((y<2)&&(x<6))
	{
		cout<<__LINE__<<endl;
		if((((boardArray[x+1][y+1])>200)&&(boardArray[x+1][y+1]<300))||(boardArray[x+1][y+1]>400))
		{
			if(	(boardArray[x+2][y+2])==0)
			{
				return 1;
			}
		}
		return 0;
	}

	
	else if((y>5)&&(x<6))
	{
		cout<<__LINE__<<endl;
		if((((boardArray[x+1][y-1])>200)&&(boardArray[x+1][y-1]<300))||(boardArray[x+1][y-1]>400))
		{
			if(	(boardArray[x+2][y-2])==0)
			{
				return 1;
			}
		}
		return 0;
	}
	
	else
	{
		cout<<__LINE__<<endl;
		return 0;
	}
	}
	
	else if((boardArray[x][y]>300)&&(boardArray[x][y]<400))
	{
			
			
		if((x<6)&&(y<6)&&(y>1)&&(x>2))
		{
		/*if((boardArray[x+1][y-1]>200)||(boardArray[x+1][y+1]>200))
		{
			if(	((boardArray[x+2][y-2])==0)||((boardArray[x+2][y+2])==0))
			{
				cout<<__LINE__<<endl;
				return 1;
			}
		}*/
		
		if(((((boardArray[x+1][y-1]>200)&&(boardArray[x+1][y-1]<300))||(boardArray[x+1][y-1]>400)))&&((boardArray[x+2][y-2])==0))
		{
			return 1;
		}
		
		else if(((((boardArray[x+1][y+1]>200)&&(boardArray[x+1][y+1]<300))||(boardArray[x+1][y+1]>400)))&&(boardArray[x+2][y+2])==0)
		{
		return 1;
		}
		else if(((((boardArray[x-1][y+1]>200)&&(boardArray[x-1][y+1]<300))||(boardArray[x-1][y+1]>400)))&&(boardArray[x-2][y+2])==0)
		{
		return 1;
		}
		else if(((((boardArray[x-1][y-1]>200)&&(boardArray[x-1][y-1]<300))||(boardArray[x-1][y-1]>400)))&&(boardArray[x-2][y-2])==0)
		{
		return 1;
		}
		else
		{
		return 0;
		}
		}
			
		else if((y<2)&&(x<6)&&(x>2))
		{
			cout<<__LINE__<<endl;
			if((((boardArray[x+1][y+1])>200)&&(boardArray[x+1][y+1]<300))||(boardArray[x+1][y+1]>400))
			{
				if(	(boardArray[x+2][y+2])==0)
				{
					return 1;
				}
			}
			
			else if((((boardArray[x-1][y+1])>200)&&(boardArray[x-1][y+1]<300))||(boardArray[x-1][y+1]>400))
			{
				if(	(boardArray[x-2][y+2])==0)
				{
					return 1;
				}
				
			}
			else
			{
			return 0;
			}
		}
		
		else if((y>5)&&(x<6)&&(x>2))
		{ 
			cout<<__LINE__<<endl;
			if((((boardArray[x+1][y-1])>200)&&(boardArray[x+1][y-1]<300))||(boardArray[x+1][y-1]>400))
			{
				if(	(boardArray[x+2][y-2])==0)
				{
					return 1;
				}
			}
			
			else if((((boardArray[x-1][y-1])>200)&&(boardArray[x-1][y-1]<300))||(boardArray[x-1][y-1]>400))
			{
				if(	(boardArray[x-2][y-2])==0)
				{
					return 1;
				}
			}
			else
			{
				return 0;
			}
		}
		
		else if(x<2)//change here
		{
			if(((((boardArray[x+1][y-1]>200)&&(boardArray[x+1][y-1]<300))||(boardArray[x+1][y-1]>400)))&&((boardArray[x+2][y-2])==0))
			{
				return 1;
			}
		
			if(((((boardArray[x+1][y+1]>200)&&(boardArray[x+1][y+1]<300))||(boardArray[x+1][y+1]>400)))&&(boardArray[x+2][y+2])==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
		}
		
		else if(x>5)//change here
		{
			if(((((boardArray[x-1][y-1]>200)&&(boardArray[x-1][y-1]<300))||(boardArray[x-1][y-1]>400)))&&((boardArray[x-2][y-2])==0))
			{
				return 1;
			}
		
			if(((((boardArray[x-1][y+1]>200)&&(boardArray[x-1][y+1]<300))||(boardArray[x-1][y+1]>400)))&&(boardArray[x-2][y+2])==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
		}
		
		else
		{
			return 0;
		}	
		
	}
	
	else if(boardArray[x][y]>400)
	{
		
		
		if((x<6)&&(y<6)&&(y>1))
		{	
			cout<<__LINE__<<endl;
		/*
		if((boardArray[x-1][y-1]>100)&&(boardArray[x-1][y-1]<200)||(boardArray[x-2][y-2])==0))
		{
			if(	((boardArray[x-2][y-2])==0)||((boardArray[x-2][y+2])==0))
			{
				return 1;
			}
		}
		*/
			if((((boardArray[x+1][y+1]>100)&&(boardArray[x+1][y+1]<200))||((boardArray[x+1][y+1]>300)&&(boardArray[x+1][y+1]<400)))&&(boardArray[x+2][y+2])==0)
			{
				return 1;
			}
			
			else if((((boardArray[x+1][y-1]>100)&&(boardArray[x+1][y-1]<200))||((boardArray[x+1][y-1]>300)&&(boardArray[x+1][y-1]<400)))&&(boardArray[x+2][y-2])==0)
			{
				return 1;
			}
		
			else if((((boardArray[x-1][y+1]<200)&&((boardArray[x-1][y+1])>100))||((boardArray[x-1][y+1]>300)&&(boardArray[x-1][y+1]<400)))&&(boardArray[x-2][y+2])==0)
			{
				return 1;
			}
			
			else if((((boardArray[x-1][y-1]<200)&&((boardArray[x-1][y-1])>100))||((boardArray[x-1][y-1]>300)&&(boardArray[x-1][y-1]<400)))&&(boardArray[x-2][y-2])==0)
			{
				return 1;
			}
		
			else
			{
				return 0;
			}
		}
		
		else if((y<2)&&(x<6))
		{
			cout<<__LINE__<<endl;
			if(((boardArray[x-1][y+1]<200)&&((boardArray[x-1][y+1])>100))||((boardArray[x-1][y+1]>300)&&(boardArray[x-1][y+1]<400)))
			{
				if(	(boardArray[x-2][y+2])==0)
				{
					return 1;
				}
			}
			
			else if(((boardArray[x+1][y+1]<200)&&((boardArray[x+1][y+1])>100))||((boardArray[x+1][y+1]>300)&&(boardArray[x+1][y+1]<400)))
			{
				if(	(boardArray[x+2][y+2])==0)
				{
					return 1;
				}
			}
			
			else
			{
			return 0;
			}
		}
		
		else if((y>5)&&(x<6))
		{
			cout<<__LINE__<<endl;
			if(((boardArray[x-1][y-1]>100)&&(boardArray[x-1][y-1]<200)||((boardArray[x-1][y-1]>300)&&(boardArray[x-1][y-1]<400))))
			{
				if(	(boardArray[x-2][y-2])==0)
				{
					cout<<__LINE__<<endl;
					return 1;
				}
			}
			
			else if(((boardArray[x+1][y-1]>100)&&(boardArray[x+1][y-1]<200)||((boardArray[x+1][y-1]>300)&&(boardArray[x+1][y-1]<400))))
			{
				if(	(boardArray[x+2][y-2])==0)
				{
					cout<<__LINE__<<endl;
					return 1;
				}
				
			}
			
			else
			{
			return 0;
			}
		}
		
	}

	else
	{
	

	
	if(x<2)
	{
		cout<<__LINE__<<endl;
		return 0;
			
	}
		

		
	if((x<6)&&(y<6)&&(y>1))
	{
		cout<<__LINE__<<endl;
		/*
		if((boardArray[x-1][y-1]>100)&&(boardArray[x-1][y-1]<200)||(boardArray[x-2][y-2])==0))
		{
			if(	((boardArray[x-2][y-2])==0)||((boardArray[x-2][y+2])==0))
			{
				return 1;
			}
		}
		*/
		if((((boardArray[x-1][y-1]>100)&&(boardArray[x-1][y-1]<200))||((boardArray[x-1][y-1]>300)&&(boardArray[x-1][y-1]<400)))&&(boardArray[x-2][y-2])==0)
		{
			return 1;
		}
		
		if((((boardArray[x-1][y+1]<200)&&((boardArray[x-1][y+1])>100))||((boardArray[x-1][y+1]>300)&&(boardArray[x-1][y+1]<400)))&&(boardArray[x-2][y+2])==0)
		{
		return 1;
		}
		
		else
		{
			return 0;
		}
	}
	
	else if(x<2)//change here
		{
			if(((((boardArray[x+1][y-1]>200)&&(boardArray[x+1][y-1]<300))||(boardArray[x+1][y-1]>400)))&&((boardArray[x+2][y-2])==0))
			{
				return 1;
			}
		
			if(((((boardArray[x+1][y+1]>200)&&(boardArray[x+1][y+1]<300))||(boardArray[x+1][y+1]>400)))&&(boardArray[x+2][y+2])==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
		}
		
	else if(x>5)//change here
	{
			if(((((boardArray[x-1][y-1]>200)&&(boardArray[x-1][y-1]<300))||(boardArray[x-1][y-1]>400)))&&((boardArray[x-2][y-2])==0))
			{
				return 1;
			}
		
			if(((((boardArray[x-1][y+1]>200)&&(boardArray[x-1][y+1]<300))||(boardArray[x-1][y+1]>400)))&&(boardArray[x-2][y+2])==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
	}
	else if((y<2)&&(x<6))
	{
		cout<<__LINE__<<endl;
		if(((boardArray[x-1][y+1]<200)&&((boardArray[x-1][y+1])>100))||((boardArray[x-1][y+1]>300)&&(boardArray[x-1][y+1]<400)))
		{
			if(	(boardArray[x-2][y+2])==0)
			{
				return 1;
			}
		}
		return 0;
	}

	
	else if((y>5)&&(x<6))
	{
		cout<<__LINE__<<endl;
		if(((boardArray[x-1][y-1]>100)&&(boardArray[x-1][y-1]<200)||((boardArray[x-1][y-1]>300)&&(boardArray[x-1][y-1]<400))))
		{
			if(	(boardArray[x-2][y-2])==0)
			{
				cout<<__LINE__<<endl;
				return 1;
			}
		}
		return 0;
	}
	
	else
	{
		return 0;
	}
	}
		
	
}
	
	


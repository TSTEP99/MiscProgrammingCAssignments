#include <iostream>
#include <string.h>
#include <list>
#include "position.h"
#include "piece.h"

using namespace std;

extern int boardArray[8][8];

class checker: public piece
{

public:
int move(int x,int y);	
checker(int x,int y,int num,unsigned tnum):piece(x,y,num,tnum){;}
~checker(){cout<<"this piece has been killed"<<endl;}

	
	
};

int checker::move(int x,int y)
{
	//0 top most player
	//1 bottom most player
	
	int posX=Location.GetX();//gets current position of x and y
	int posY=Location.GetY();
	int occup=boardArray[x][y];//find current value
	
	int midx;//calculate middle position if applicable
	int midy;
	int midoccup;
	
	
	int diffx;
	int diffy1;
	int diffy2;
	
	if(x<0||x>7||y<0||y>7)
	{
		cout<<"Invalid Coordinates"<<endl;
		return 1;
	}
	
	if(team==0)
	{
		diffx=x-posX;//checks to see if difference if the difference between the position currently for the piece and requested
		//differ by one or two
		diffy1=y-posY;//sames as above but for both variations of y
		diffy2=posY-y;
		
		midx=posX+(x-posX)/2;//calculate middle position if applicable
		midy=posY+(y-posY)/2;
		
		midoccup=boardArray[midx][midy];//determines if middle place occupied
		
		
		if((diffx==1)&&((diffy1==1)||(diffy2==1))&&(occup==0))
		{
			Location.SetPos(x,y);
			return 0;
			
		}
		
		else if ((diffx==2)&&((diffy1==2)||(diffy2==1))&&(midoccup>0))
		{
			Location.SetPos(x,y);
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
		diffx=posX-x;
		diffy1=y-posY;
		diffy2=posY-y;
		
	
		midx=posX+(x-posX)/2;//calculate middle position if applicable
		midy=posY+(y-posY)/2;
		
		
		midoccup=boardArray[midx][midy];//determines if middle place occupied
		
		if((diffx==1)&&((diffy1==1)||(diffy2==1))&&(occup==0))
		{
			Location.SetPos(x,y);
			
			return 0;
			
		}
		
		else if ((diffx==2)&&((diffy1==2)||(diffy2==2))&&(midoccup>0))
		{
			Location.SetPos(x,y);
			return midoccup;
		}
		
		else
		{
			cout<<"Invalid"<<endl;
			return 1;
		}
		
	}
	
}

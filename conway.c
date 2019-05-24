
#include "conway.h"
#include <stdio.h>

void choice(void)
{
	int x;
	int y;
	extern char board[16][16];
	
	
	
	puts("choose a cell to make alive (x,y):");
	scanf("%d ,%d",&x,&y);
		
	if(board[x][y]=='#')
	{
		puts("That cell has already been chosen. Try again");
			
	}
	else
	{
			board[x][y]='#';
	}	
}

void corner(void)
{
	int corner1=0;
	int corner2=0;
	int corner3=0;
	int corner4=0;
	int x,y;
	
	extern char board[16][16];
	extern int nextboard[16][16];
	
	for(x=0;x<=1;x++)
	{
		for(y=0;y<=1;y++)
		{
			if((x!=0 || y!=0)&& board[x][y]=='#')
			{
				corner1+=1;	
			}

		}
	}
	
	nextboard[0][0]=corner1;
	
	for(x=0;x<=1;x++)
	{
		for(y=14;y<=15;y++)
		{
			if((x!=0 || y!=15)&& board[x][y]=='#')
			{
				corner2+=1;	
			}

		}
	}
	
	nextboard[0][15]=corner2;
	
	for(x=14;x<=15;x++)
	{
		for(y=0;y<=1;y++)
		{
			if((x!=15 || y!=0)&& board[x][y]=='#')
			{
				corner3+=1;	
			}

		}
	}
	
	nextboard[15][0]=corner3;
	
	for(x=14;x<=15;x++)
	{
		for(y=14;y<=15;y++)
		{
			if((x!=15 || y!=15)&& board[x][y]=='#')
			{
				corner4+=1;	
			}

		}
	}
	
	nextboard[15][15]=corner4;
	
}

void edge(void)
{
	int x;
	int y;
	int i,j;
	int edge;
	
	extern char board[16][16];
	extern int nextboard[16][16];
	
	
	for (x=1;x<15;x++)
	{
		edge=0;
		for (i=x-1;i<=x+1;i++)
		{
			for(j=0;j<=1;j++)
			{
				if((i!=x||j!=0)&& board[i][j]=='#')
				{
						edge+=1;
				}
			}				
		}
		nextboard[x][0]=edge;
	
		
	}
	
	for (x=1;x<15;x++)
	{
		edge=0;
		for (i=x-1;i<=x+1;i++)
		{
			for(j=14;j<=15;j++)
			{
				if((i!=x||j!=15)&& board[i][j]=='#')
				{
						edge+=1;
				}
			}				
		}
		nextboard[x][15]=edge;
		
	
		
	}
	
	for (y=1;y<15;y++)
	{
		edge=0;
		for (j=y-1;j<=y+1;j++)
		{
			for(i=14;i<=15;i++)
			{
				if((i!=15||j!=y)&& board[i][j]=='#')
				{
						edge+=1;
				}
			}				
		}
		nextboard[15][y]=edge;
		
		
	
		
	}
	
	
	for (y=1;y<15;y++)
	{
		edge=0;
		for (j=y-1;j<=y+1;j++)
		{
			for(i=0;i<=1;i++)
			{
				if((i!=0||j!=y)&& board[i][j]=='#')
				{
						edge+=1;
				}
			}				
		}
		nextboard[0][y]=edge;
		
		
	
		
	}
	
}

void middle(void)
{
	int x,y;
	int i,j;
	int middle=0;
	char test1;
	
	extern char board[16][16];
	extern int nextboard[16][16];
	
	for (x=1;x<15;x++)
	{
		for(y=1;y<15;y++)
		{
				middle=0;
				for(i=x-1; i<=(x+1);i++)
				{
					for(j=y-1; j<=(y+1);j++)
					{
						test1=board[i][j];
						
						if(((i!=x)||(j!=y))&&(test1=='#'))
						{
							middle+=1;
						}
					}	
				}
				nextboard[x][y]=middle;
				
		}
	
	}
}
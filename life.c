#include<stdio.h>
#include<unistd.h>
#include "conway.h"
char board[16][16];
int nextboard[16][16];

void choice(void);
void corner(void);
void edge(void);
void middle(void);

int main()
{
	int x;
	int y;
	int z;
	char test1;
	int test2;
	
	for(x=0;x<16;x++)
	{
		for(y=0;y<16;y++)
		{
			board[x][y]='.';
		}
	}
	
	for(x=0;x<16;x++)
	{
		for(y=0;y<16;y++)
		{
			nextboard[x][y]=0;
		}
	}
	
	
	
	
	
	z=257;
	while((z>256)||(z<=0))
	{
		puts("How many live cells do you want (256 or under)");
		scanf("%d",&z);	
		
	}
	
	for(;z>0;z--)
	{
	choice();
	}

	for(x=0;x<16;x++)
	{
		for(y=0;y<16;y++)
		{
			printf("%c",board[x][y]);
		}
		printf("\n");
	}
	printf("\n");
	
	
	
	while(1)
	{
	printf("\nPress CTRL-C to exit anytime.\n");
	corner();
	edge();
	middle();
	
	sleep(1);
	for(x=0;x<16;x++)
	{
		for(y=0;y<16;y++)
		{
			test1=board[x][y];
			test2=nextboard[x][y];
			if(test1=='#'&& test2<2)
			{
				board[x][y]='.';	
			}
			else if(test1=='#'&&(test2==2||test2==3))
			{
				board[x][y]='#';	
			}
			else if(test1=='#'&&(test2>3))
			{
				board[x][y]='.';
			}
			else if(test1=='.'&& test2==3)
			{
				board[x][y]='#';	
			}	
			else
			{
				board[x][y]=test1;
			}
		}
	}
	for(x=0;x<16;x++)
	{
		for(y=0;y<16;y++)
		{
			printf("%c",board[x][y]);
		}
		printf("\n");
	}

	
	}
}




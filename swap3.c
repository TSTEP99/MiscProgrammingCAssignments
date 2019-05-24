#include <stdio.h>

void swap3(int *a,int *b, int *c);

int main()
{
	int a=1;
	int b=2;
	int c=3;
	
	swap3(&a,&b,&c);
	
	printf("%d %d %d",a,b,c);
}

void swap3(int *a,int *b,int *c)
{
		int tempval;
		
		tempval=*c;
		
		*c=*b;
		
		*b=*a;
		
		*a=tempval;
}
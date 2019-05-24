#include <stdio.h>

void batman(int n);

int main()
{
		int n;
		printf("How many nas do you want?: ");
		scanf("%d",&n);
		batman(n);
}

void batman(int n)
{
	if(n==0)
	{
			printf("batman\n");
	}
	else if(n<0)
	{
		printf("Invalid Input");	
	}
	else
	{
			printf("na ");
			batman(n-1);
	}
}
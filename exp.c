#include<stdio.h>

int power(int n, int x);
int factorial(int a );
int main()
{
	int term;
	int value;
	int i;
	int sum=0;
	
	printf("How many terms do you want: \n");
	scanf("%d",&term);
	printf("For what value?: \n");
	scanf("%d",&value);
	
	for(i=0; i<=term;++i)
	{
		sum+=power(i,value)/factorial(i);
	}
	printf("The sum is %d",sum);
	
}

// generates exponent part of the series term
int power(int n, int x)
{
	// returns 0 if exponent =1
	if(n==0)
	{
		return 0;
	}
	
	int power=1;
	int i;
	for(i=1;i<=n;++i)
	{
		power*=x;
	}
	return power;
	
}
// find the factorial
int factorial(int a)
{
	int factor;
	if(a==0||a==1)
	{
		return 1;
	}
	else if (a>1)
	{
		//uses recursion to factorial
		factor=a*factorial(a-1);
	}
	
	return factor;
}
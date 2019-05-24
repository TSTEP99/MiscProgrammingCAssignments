#include <stdio.h>

int fibonacci(int n);

int main()
{
	int n;
	printf("which number of the fibonacci sequence do you want?: ");
	scanf("%d",&n);
	printf("%d",fibonacci(n));
}

int fibonacci(int n)
{
		if((n==0)||(n==1))
		{
				return 1;
		}
		
		else
		{
			return (fibonacci(n-1)+fibonacci(n-2));	
		}
}
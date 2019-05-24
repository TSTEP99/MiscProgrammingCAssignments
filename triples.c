#include <stdio.h>

int square(int x);

int main()
{
	int limit;
	printf("What is the max value you want for the triples: ");
	scanf("%d",&limit);
	
	int a,b,c;
	
	for(c=1;c<=limit;++c)
	{
			for(b=1;b<=limit;++b)
			{
					for(a=1;a<=limit;++a)
					{
							if(square(c)==square(a)+square(b))
							{
								printf("%d^2=%d^2+%d^2\n",c,a,b);
							}
					}
			}
	
	}
	
	
}

int square(int x)
{
		return x*x;
}
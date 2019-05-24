#include<stdio.h>

int main()
{
	int num;
	int i;
	int divisor;
	int divisors;
	
	for(i=2;i<=100;i++)
	{
			
			divisors=0;
			for(divisor=2;divisor<=10;++divisor)
			{
					if( i%divisor==0)
					{
							divisors=divisors+1;
							
					}
			}
			
			if((divisors==0)||((divisors==1)&&(i<10)))
			{
					printf("%d\n",i);
			}
			
		
	}
}
#include <stdio.h>

int main()
{
	int iteration;
	
	printf("How many terms do you want: ");
	scanf("%d",&iteration);
	
	float sign=-1;
	int i;
	float sum=0;
	
	for(i=0;i<iteration;i++)
	{
		sign=-1*sign;
		sum+=sign*4/(2*i+1);
	}
	
	printf("Your approximation is %f",sum);
	
}
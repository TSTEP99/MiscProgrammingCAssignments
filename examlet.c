#include <stdio.h>

int main()
{
	int exam1[10];
	int exam2[10];
	int total[10];
	
	int i;
	
	for(i=0;i<=9;i++)
	{
			printf("What do you want for value #%d: ",i+1);
			scanf("%d",&exam1[i]);
			
	}
	
	for(i=0;i<=9;i++)
	{
			printf("What do you want for value #%d: ",i+1);
			scanf("%d",&exam2[i]);
			
	}
	
	for(i=0;i<=9;i++)
	{
			total[i]=exam1[i]+exam2[i];
			printf("%d\n",total[i]);
	}
}
#include<stdio.h>

#define MAX_NUMS 10

int main()
{
	int numbers[MAX_NUMS];
	int repeats[MAX_NUMS];
	int i;
	int j;
	
	for(i=0;i<MAX_NUMS;i++)
	{
		printf("Input a value: ");
		scanf("%d",&numbers[i]);
	}
	
	for(i=0;i<MAX_NUMS;i++)
	{
		repeats[i]=0;
		for(j=0;j<MAX_NUMS;j++)
		{
				if(numbers[i]==numbers[j])
				{
						repeats[i]+=1;
				}
		}
	}
	
	for(i=0;i<MAX_NUMS;i++)
	{
			printf("%d\n",repeats[i]);
	}
}
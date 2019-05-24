#include <stdio.h>
#define MAX_NUMS 10


void insertionsort(int numbers[]);


int main()
{
	int numbers[10];
	int i;
	
	for(i=0;i<10;i++)
	{
			printf("Input a number: ");
			scanf("%d",&numbers[i]);
	}
	
	insertionsort(numbers);

}

void insertionsort(int numbers[])
{
	int unsorted;
	int check;
	int sorted;
	
	for(unsorted=0;unsorted<MAX_NUMS;++unsorted)
	{
		check=numbers[unsorted];
		
		for(sorted=unsorted-1;(sorted>=0) && (numbers[sorted]>check);--sorted)
		{
			numbers[sorted+1]=numbers[sorted];
			numbers[sorted]=check;
		}
		
	}
	
	int i;
	
	for(i=0;i<10;++i)
	{
		printf("%d\n",numbers[i]);
	}
}
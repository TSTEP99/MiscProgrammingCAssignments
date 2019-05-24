#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"


int main()
{
	int numbers[10];
	int i;
	int *test;
	
	double start,finish;
	
	for(i=0;i<10;i++)
	{
			printf("Input a number: ");
			scanf("%d",&numbers[i]);
	}
	
	start=clock();
	insertionsort(numbers);
	finish=clock();
	printf("%f\n",difftime(finish,start));
	start=clock();
	bubblesort(numbers);
	finish=clock();
	printf("%f\n",difftime(finish,start));
	start=clock();
	selectionsort(numbers);
	finish=cloc();
	printf("%f\n",difftime(finish,start));
	
	start=time(0);
	test=mergesort(numbers,10);
	
	for(i=0;i<10;i++)
	{
		printf("\n%d",test[i]);
	}
	finish=time(0);
	printf("%f\n",difftime(finish,start));
}


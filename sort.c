#include <stdio.h>
#include "sort.h"
#include <stdlib.h>

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

void bubblesort(int numbers[])
{
	int i, flag,arr1,arr2;

	do
	{
	flag=0;
	for(i=0;i<9;i++)
	{
		arr1=numbers[i];
		arr2=numbers[i+1];
		if(arr1>arr2)
		{
			numbers[i]=arr2;
			numbers[i+1]=arr1;
			flag=1;
		}
	}
	}
	while(flag==1);
		
	for(i=0;i<MAX_NUMS;i++)
	{
		printf("%d\n",numbers[i]);
	}
}

void selectionsort(int numbers[])
{
	int start=0, min,loc,i,tmp;
	
	do
	{
	
	min=numbers[start];
	loc=start;
	for(i=start;i<MAX_NUMS;i++)
	{
		tmp=numbers[i];
		if(tmp<min)
		{
			min=tmp;
			loc=i;
		}
	}
	
	numbers[loc]=numbers[start];
	numbers[start]=min;
	start++;
	}
	while(start<=MAX_NUMS);
	
	for(i=0;i<MAX_NUMS;i++)
	{
		printf("%d\n",numbers[i]);
	}
}

int *mergesort(int numbers[],int length)
{
	//int length=sizeof(numbers)/sizeof(numbers[0]);
	
	int tmp1,tmp2;
	int i=0, j=0,k;
	int *half1;
	int *half2;
	int *half3;
	int *half4;
	
	if(length==2)
	{
	//printf("\n%d %d\n at 37",numbers[1],numbers[0]);
	if(numbers[1]<numbers[0])
	{
		tmp1=numbers[1];
		tmp2=numbers[0];
		numbers[1]=tmp2;
		numbers[0]=tmp1;
		return numbers;
	}
	return numbers;
	}
	else if(length==1)
	{
		//printf("%d at 50",numbers[0]);
		return numbers;
	}
	
	else
	{
		int length1=length/2;
		int length2=length-length1;
		
		//printf("\n%d %d\n",length1,length2);
		
		half1= (int *) malloc(sizeof(int)*length1);
		half2= (int *) malloc(sizeof(int)*(length2));
		half3= (int *) malloc(sizeof(int)*length1);
		half4= (int *) malloc(sizeof(int)*(length2));
		
		//printf("\n%p %p at 59\n",half1,half2);
		if((half1==NULL)||(half2==NULL))
		{
			fprintf(stderr,"Error Allocating memory");
			exit(1);
		}
		
		for(i=0;i<length1;i++)
		{
			half1[i]=numbers[i];
			//printf("\n%d at 81\n",half1[i]);
			
		}
		
		
		for(j=0;i<(length);j++,i++)
		{
			half2[j]=numbers[i];
			//printf("\n%d at 88\n",half2[j]);
			
		}
		
		for(j=0;j<(length2);j++)
		{
			//printf("%d",half2[j]);
			//printf("\n%d at 88\n",half2[i]);
			
		}
			
		half3=mergesort(half1,length1);
		
		half4=mergesort(half2,length2);
		
		//printf("\n%p %p\n at 80\n",half3,half4);
		
		for(j=0;j<(length1);j++)
		{
			//printf("%d %d ",half3[j],half4[j]);
			//printf("\n%d at 88\n",half2[i]);
			
		}
		
		i=0;
		j=0;
		for(k=0;k<length;k++)
		{
			
			//printf("\n%d %d\n",i,j);
			tmp1=half3[i];
			tmp2=half4[j];
			
			//printf("\n%d %d\n",tmp1,tmp2);
			if(tmp1<=tmp2)
			{
				if(i==length1)
				{
				numbers[k]=tmp2;
				j++;
				continue;
				}
				numbers[k]=tmp1;
				//printf("%d",tmp1);
				
				i++;
			}
			else
			{
				if(j==length2)
				{
				numbers[k]=tmp1;
				i++;
				continue;
				}
				numbers[k]=tmp2;
				//printf("%d",tmp2);
				
				j++;
			}	
		}
			
	/*free(half1);
	free(half2);
	free(half3);
	free(half4);*/
	
	return numbers;
	}
}















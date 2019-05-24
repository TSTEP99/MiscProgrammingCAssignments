#include <stdio.h>


int main(){
	
	int row;
	
	printf("Enter the row column : ");
	scanf("%d",&row);
	
	unsigned long product=1;

	printf("%lu ",product);
	
	int i;
	
	for(i=1;i<=row;i++){
			product*=(row+1-i);
			product/=i;
			
			printf("%lu ",product);
	}
	
}

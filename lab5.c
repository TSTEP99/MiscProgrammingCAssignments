#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void roll_three(int* one,int* two,int* three);

int main(){
		int n;
		printf("Please input a number: ");
		scanf("%d",&n);
		
		int count[6]={0,0,0,0,0,0};
		
		srand(n);

		int one,two,three;
		
		roll_three(&one,&two,&three);
		
		printf("%d %d %d",one,two,three);
		
		count[one-1]+=1;
		count[two-1]+=1;
		count[three-1]+=1;
		
		int i;
		int max=0;
		for( i=0;i<6;i++){
			if(max<count[i]){
				max=count[i];
			}
		}
		
		switch(max){
			
			case 2:
				printf("\nYou have a double");
				break;
			case 3:
				printf("\nYou have a triple");
				break;
		}
		
}

void roll_three(int* one,int* two,int* three){
		*one= rand()%6+1;
		*two=rand()%6+1;
		*three=rand()%6+1;
}
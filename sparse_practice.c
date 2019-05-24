#include<stdio.h>
#include <stdlib.h>
# define SIZE 5
int main(){
	struct element {
		int row;
		int col;
		int value;
		struct element* previous;
		struct element* next;
	};
	
	typedef struct element Element;
	
	int matrix[SIZE][SIZE]={{1,0,0,0,0},{0,1,0,0,0},{0,0,0,1,0},{0,0,0,1,0},{1,0,0,0,1}};
	
	int num_not=0;
	int i,j;
	for(i=0;i<SIZE;i++){
			for(j=0;j<SIZE;j++){
					if(matrix[i][j]!=0){
						num_not++;	
					}
			}	
	}
	
	//printf("%d",num_not);
	
	Element *element_array= (Element*) malloc(sizeof(Element)*num_not);
	int length=num_not;
	
	int k=0;
	for(i=0;i<SIZE;i++){
			for(j=0;j<SIZE;j++){
					if(matrix[i][j]!=0){
						element_array[k].row=i;
						element_array[k].col=j;
						element_array[k].value=matrix[i][j];
						k++;
					}
			}
	}
	
	element_array[0].previous=NULL;
	element_array[length-1].next=NULL;
	
	for(i=0;i<length-1;i++){
			element_array[i].next=&element_array[i+1];
			element_array[i+1].previous=&element_array[i];
	}
	
	Element* head_ptr=&element_array[0];
	
	while(head_ptr!= NULL){
			printf("%d %d %d\n",head_ptr->row,head_ptr->col,head_ptr->value);
			head_ptr=head_ptr->next;
	
	}
	
}
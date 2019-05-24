#include <stdio.h>
#include <stdlib.h>
#include "farey_seq.h"

int main()
{
	int n;
	printf("Please enter n: ");
	scanf("%d", &n);
	node * head;
	head = farey_seq(n);
	if(head == NULL)
		printf("The linked list is empty");
	delete_list(head);
}

node * farey_seq(int n)
{
	/*You code goes here*/
	if(n<1){
			return NULL;
	}
	
	node* head= (node*) malloc(sizeof(node));
	head->numerator=0;
	head->denominator=1;
	head->next= (node*) malloc(sizeof(node));
	head->next->numerator=1;
	head->next->denominator=1;
	head->next->next=NULL;
	
	print_list(head,1);
	
	int i;
	
	for(i=2;i<=n;i++){
		node* previous= head;
		node* current=head->next;
		while(current!=NULL){
			int a=previous->numerator;
			int c=previous->denominator;
			int b=current->numerator;
			int d=current->denominator;
			
			if(c+d<=i){
				node* new_node= (node*) malloc(sizeof(node));
				new_node->numerator=a+b;
				new_node->denominator=c+d;
				new_node->next=current;
				previous->next=new_node;
				previous=current;
				current=current->next;
			} else{
				previous=current;
				current=current->next;
			}
		}
		print_list(head,i);
	}
	
	return head;
	
}
void print_list(node * head, int n)
{
	if(head == NULL)
		return;	
	printf("level %d: ", n);
	while(head != NULL)
	{
		printf("%d/%d ", head->numerator, head->denominator);
		head = head->next;
	}
	printf("\n");
}

void delete_list(node * head)
{
	node * temp;	
	while(head != NULL){
		temp = head->next;
		free(head);
		head = temp;
	}
}

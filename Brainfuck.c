#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int index;
	struct node * next;
	
}Node;

int stack_length=0;

int is_empty(Node** head){
		if((*head)==NULL){
				return 1;
		} else{
			return 0;	
		}
}

void push(Node** head,int index){
		Node* new_node= (Node*) malloc(sizeof(Node));
		new_node->index=index;
		new_node->next=*head;
		(*head)=new_node;
		stack_length++;
}

void pop(Node** head){
		if(is_empty(head)){
				//printf("Stack is empty");
				return;
		}
	
		Node *tmp= *head;
		*head=(*head)->next;
		
		free(tmp);
		
		stack_length--;
}

int peek(Node** head){
	if(is_empty(head)==1){
		return -1;
	}	else{
		return (*head)->index;	
	}
}

int main(){
	
	Node* stack=NULL;
	
	char string[]="random.txt";
	
	FILE *fptr= fopen(string,"r");
	
	if(fptr==NULL){
			return 1;
	}
	char* text=NULL;
	
	size_t size=0;
	
	char character=fgetc(fptr);
	
	while(character!=EOF){
		++size;
		char* tmp=realloc(text,size*sizeof(char));
		if(tmp==NULL){
				return 1;
		}
		
		text=tmp;
		text[size-1]=character;
		character=fgetc(fptr);
	}
	
	++size;
	char* tmp=realloc(text,size*sizeof(char));
	
	if(tmp==NULL){
			return 1;
	}
	
	text=tmp;
	//puts(text);
	
	fclose(fptr);
	
	char tape[30000]={0};
	
	int index=0;
	
	int length= strlen(text);
	
	//printf("%s\n",text);
	
	int i;
	
	Node* check_head=NULL;
	
	for(i=0;i<length;i++){
			if(text[i]=='['){
			push(&check_head,i);				
			} else if(text[i]==']'){
					if(is_empty(&check_head)==1){
							fprintf(stderr,"Error: Unbalanced Loop");
					}
					
					pop(&check_head);
					
			}
		
	}
	
	if(check_head!=NULL){
		fprintf(stderr,"Error: Unbalanced Loop");	
	}
	
	
	for(i=0;i<length;i++){
			int j;
			
						
			//printf("%d\n",tape[index]);
			switch(text[i]){
				int count;		
				int flag;
				int j;
				case '>':
					++index;
					break;
				case '<':
					--index;
					break;
				case '+':
					//printf("%d\n",__LINE__);
					tape[index]+=1;
					break;
				case '-':
					tape[index]-=1;
					break;
				case '.':
					//printf("%d",tape[index]);
					putchar(tape[index]);
					break;
				case ',':
					tape[index]=getchar();
					break;
				case '[':
						
						count=0;
						
						if(tape[index]==0){
						
						for(j=i;j<length;j++){
								if(text[j]=='['){
										count--;
								} else if(text[j]==']'){
										count++;
								}
								if(count==0 && text[j]==']'){
									//printf("%d",j+1);
									i=j+1;
									break;
								}
						}
						
						}
						
						
						break;
				
				case ']':
						
					count=0;
					if(tape[index]!=0){
						for(j=i;j>=0;j--){
							if(text[j]==']'){
									count--;
							} else if(text[j]=='['){
									count++;
							}
							
							if(count==0 &&text[j]=='['){
								i=j;
								break;
							}
						}	
								
					}
					
						
					
					break;
					
				case ' ':
				case '\t':
				case '\r':
				case '\n':
				case '\v':
				case '\f':
				break;
				
			}
				
	}
}
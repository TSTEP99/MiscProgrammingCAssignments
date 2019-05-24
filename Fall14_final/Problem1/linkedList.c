#include "linkedList.h"


int DetectLoop(node *head)
{
  //Write code here.
  
  node* slow= head;
  node* fast= head;
  
  while(fast!=NULL){
	 fast=fast->next;
	 if(fast==NULL){
		return 0; 
     }
	 
	 fast=fast->next;
	 
	 slow=slow->next;
	 
	 if(slow==fast){
		 return 1; 
     }
	 
  }
  
  return 0;
  
    
}

node *CopyList(node *head)
{
   //Insert Code here. You can change the return statement given.
   
   node dummy={0,NULL,NULL};
   node* current=&dummy;
   
   node* current_head=head;
   
   while(current_head!=NULL){
		node* new_ptr= (node*) malloc(sizeof(node));
		new_ptr->arbit=current_head->arbit;
		new_ptr->next=current_head->next;
		new_ptr->value=current_head->value;
		
		current->next=new_ptr;
		current_head=current_head->next;
		current=current->next;
	   
   }
   
   
   
   
   return dummy.next;
}

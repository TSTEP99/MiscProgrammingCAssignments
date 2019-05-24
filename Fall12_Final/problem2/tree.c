#include <stdlib.h>
#include "tree.h"

/* Counte the number of negative values stored in a tree */
int countNegatives(struct node* root)
{
   /* Implement Me */
   
   if(node==NULL){
	 return 0;  
   }
   
   if(node->right==NULL && node->left==NULL){
	  if(node->value<0){
		return 1;
	  } else{
		return 0;  
	  }
	   
   } 
   
   if(node->value<0){
	   return  1+ countNegatives(node->right)+countNegatives(node->left);
   } else{
	   return contNegatives(node->right)+countNegatives(node->left);
   }
   
   
 
}

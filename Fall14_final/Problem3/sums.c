#include <stdio.h>
#include "vector.h"
#include "tree.h"

// FUNCTION DEFINITIONS
void findPathRecursive(node * root, int expectedSum, int currentSum, vector * path);
void findPath(node * root, int expectedSum);


// Don't change the main function
int main(int argc, char * argv[])
{
    if (argc < 1)
    {
        printf("Not enough arguments\n");
        return -1;
    }

    node * root = create_tree(argv[1]);
    int sum;
    printf("Please enter a sum: ");
    scanf("%d", &sum);

    findPath(root, sum);
    delete_tree(root);
}

// Recursive helper function for printing paths within a tree
// that add up to an expected sum
void findPathRecursive(node * root, int expectedSum, int currentSum, vector * path)
{
    // YOUR CODE HERE
	
	pushBack(path,root->value);
	
	if(root==NULL){
			return;
	}
	
	if(expectedSum==currentSum+root->value){
	
			
			int i;
			for(i=0;i<=path->back;i++){
					printf("%d ",path->contents[i]);
			}
			printf("\n");
	} else{
		findPathRecursive(root->left,expectedSum,currentSum+root->value,path);
		findPathRecursive(root->right,expectedSum,currentSum+root->value,path);
	}
	
	popBack(path);
	
}

// Finds and prints all paths within a tree that add to an expected sum
void findPath(node * root, int expectedSum)
{
    // YOUR CODE HERE
	
	if(root==NULL){
			return;
	}
	
	vector path;
	
	vectorInit(&path);
	
	pushBack(&path,root->value);
	
	findPathRecursive(root->left,expectedSum,root->value,&path);
	findPathRecursive(root->right,expectedSum,root->value,&path);
	
	
}

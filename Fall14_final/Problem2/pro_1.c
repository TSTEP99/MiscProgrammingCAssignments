// Program to find maximum sum subarray in a given 2D array
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

 
// Implementation of Kadane's algorithm for 1D array. The function returns the
// maximum sum and stores starting and ending indexes of the maximum sum subarray
// at addresses pointed by start and finish pointers respectively.
int find_maxSum(int* arr, int* start, int* finish, int n)
{
      // initialize sum, maxSum

	int max_subarray=0;
	int current_subarray=0;
	int max_start=0;
	int max_end=n-1;
	int f=0;
	
	
	int i;
	
	for(i=0;i<n;i++){
		current_subarray=current_subarray+arr[i];
		
		if(current_subarray<0){
				current_subarray=0;
				f=i;
		}
		
		if(max_subarray<current_subarray){
			max_subarray=current_subarray;
			max_start=f;
			max_end=i;
		}
	}
	
	*start=max_start;
	*finish=max_end;
	
	return max_subarray;
	
}
 

 
int main(int argc, char **argv)
{   int i, n, start, finish, maxSum;
//check for input file   
    FILE * in;
    if(argv[1]== NULL) {
        printf("You need a input file.\n");
        return -1;
    }
    in = fopen(argv[1], "r");
    if(in == NULL) {
        return -1;
    }
//read in the size of the array	
    fscanf(in, "%d", &n);

//read the array 
    int * arr=(int *)malloc(n*sizeof(int));
    for(i=0; i<n ;i++)
        fscanf(in, "%d", &arr[i]);
    
    maxSum=find_maxSum(arr, &start, &finish, n);

    printf("the subarry with max summation starts at %d, and ends at %d; the max summation is %d.\n", start, finish, maxSum);

    return 0;}

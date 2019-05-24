#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int is_val_in_row(const int val, const int i, const int sudoku[9][9]) {

  assert(i>=0 && i<9);

  // BEG TODO
  int j;
  for(j=0;j<9;j++){
	if(sudoku[i][j]==val){
		return 1;
        }
  }
  return 0;
  // END TODO
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) {

  assert(j>=0 && j<9);

  int i;
  
  for(i=0;i<9;i++){
  	if(sudoku[i][j]==val){
		return 1;
	}

  }

  // BEG TODO
  
  return 0;
  // END TODO
}

// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) {
   
  assert(i>=0 && i<9);

  int k,l;
  int lower_row,lower_col;

  lower_row=i-i%3;
  lower_col=j-j%3;
  int upper_row=lower_row+2;
  int upper_col=upper_col+2;
  for(k=lower_row;k<=upper_row;k++){
  	for(l=lower_col;l<=upper_col;l++){
        	if(sudoku[k][l]==val){
			return 1;
		}
	}
  }
  
  // BEG TODO
  
  return 0;
  // END TODO
}

// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9 && j>=0 && j<9);

  // BEG TODO
  if(is_val_in_row(val,i,sudoku)==1){
 	return 0;
  } 

  if(is_val_in_col(val,j,sudoku)==1){

	return 0;
  } if(is_val_in_3x3_zone(val,i,j,sudoku)==1){

	return 0;
 }
  return 1;
  // END TODO
}

// Procedure: solve_sudoku
// Solve the given sudoku instance.
int all_assigned(const int sudoku[9][9]){

   int i,j;
   for(i=0;i<9;i++){
	for(j=0;j<9;j++){
		if(sudoku[i][j]==0){
			return 0;

		}
		
	}


   }


}

void find_empty(int* array,int sudoku[9][9]){

	int i,j;

	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(sudoku[i][j]==0){
				array[0]=i;
				array[1]=j;
				return; 
			}
		}
	}

}
int solve_sudoku(int sudoku[9][9]) {

  // BEG TODO.
  int i,j;
  if(all_assigned(sudoku)){

	return 1;

  }


  int* array= (int *)malloc(sizeof(int)*2);

  find_empty(array,sudoku);
  i=array[0];
  j=array[1];  

  int num;

  for(num=0;num<=9;num++){
	if(is_val_valid(num,i,j,sudoku)==1){
		sudoku[i][j]=num;
		if(solve_sudoku(sudoku)){
			return 1;

		}
		
		sudoku[i][j]=0;
	} 


  }

  return 0;
  // END TODO.
}
// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%2d", sudoku[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      fscanf(reader, "%d", &sudoku[i][j]);
    }
  }
  fclose(reader);
}

int main(){
	
	
}
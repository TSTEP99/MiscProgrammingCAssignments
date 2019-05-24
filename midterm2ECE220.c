#include <stdio.h>
#define INT_MAX 32767
int min(int a,int b){
    return a<b?a:b;
}

int min_path_sum(int **grid, int m, int n, int i, int j){
/* int** grid: an mxn grid
int m, n: the dimension of the 2d grid
int i, j: current cell index
return: minimum path sum from (0, 0) to (i, j) */
/* Your Code Starts Here */
    int grid_value;
    if((i==0) && (j==0)){
        grid_value=grid[0][0];
        return grid[i][j];
    }
    
    if((i<0)||(j<0)||(i>=m)||(j>=n)){
        return INT_MAX;
    }
    
    grid_value=grid[i][j];
    int mps_l=min_path_sum(grid,m,n,i,j-1);
    int mps_u=min_path_sum(grid,m,n,i-1,j);
    
    return grid[i][j]+min(mps_l,mps_u);
}

int main() {
/* First test */
int grid1[3][3]={1, 2, 3, 3, 4, 1, 2, 5, 1};
//printf("%d",grid1[0][0]);
int m = 3;
int n = 3;
int sum = min_path_sum(grid1, m, n, m-1, n-1);
printf("min path sum of grid1 is %d \n", sum);*/
/* Second test */
int grid2[3][4]={1, 3, 2, 1, 1, 2, 1, 2, 3, 2, 1, 1};
m = 3;
n = 4;
sum = min_path_sum(grid2, m, n, m-1, n-1);
printf("min path sum of grid2 is %d \n", sum);
return 0;
}
#include <stdio.h>
#include <stdlib.h>

char * findNumber(int arr_count,int* arr,int k);

int main(){
    int arr[]={1,2,3,4,5};
	char* string;
	puts(string=findNumber(5,arr,6));
}

char* findNumber(int arr_count,int* arr, int k){
    
    char* yes="Yes";
    char* no="No";
    
    for(int i=0;i<arr_count;i++){
        if(arr[i]==k){
            return yes;
        }
    }
    
    return no;
}
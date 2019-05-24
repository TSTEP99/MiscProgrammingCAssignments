#include <stdio.h>

int partition(int* array,int start,int end);
void quickSort(int* array,int start,int end);

int main(){
	int array[]={10,9,8,7,6,5,4,3,2,1};
	
	quickSort(array,0,9);
	for(int i=0;i<10;i++){
		printf("%d",array[i]);
	}
}

int partition(int* array,int start,int end){
		
		if(start>=end){
			return -1;
		}
		
		int pivot=array[end];
		int i=start-1;
		
		for(int j=start;j<end;j++){
				if(array[j]<pivot){
					i++;
					int tmp=array[i];
					array[i]=array[j];
					array[j]=tmp;
				}
		}
		
		int tmp=array[i+1];
		array[i+1]=array[end];
		array[end]=tmp;
		
		return i+1;
}

void quickSort(int* array,int start,int end){
		int i=partition(array,start,end);
		
		if(i==-1){
			return;
		}
		
		quickSort(array,start,i-1);
		quickSort(array,i+1,end);
}
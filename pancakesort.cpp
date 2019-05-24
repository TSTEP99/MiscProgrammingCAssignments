#include <iostream>
#include <vector>
#define LENGTH 10

using namespace std;

int numOfFlips=0;

void flip(vector<int>& vectorToSort, int j); //takes the array and flips the array between the specified 
//indices i and j(where j is the indice after

void pancakeSort1(vector<int>& vectorToSort); 
void pancakeSort2(vector<int>& vectorToSort); 

int main(){
	
	vector<int> vectorToSort;
	
	vectorToSort.push_back(4);
	vectorToSort.push_back(6);
	vectorToSort.push_back(2);
	vectorToSort.push_back(5);
	vectorToSort.push_back(1);
	vectorToSort.push_back(3);
	
	for(int i=0;i<vectorToSort.size();i++){
		cout<<vectorToSort[i]<<endl;
	}
	
	cout<<endl;
	pancakeSort1(vectorToSort);
	
	for(int i=0;i<vectorToSort.size();i++){
		cout<<vectorToSort[i]<<endl;
	}
	

}

void flip(vector<int>& vectorToSort , int j){
	
		numOfFlips++;
		
		if(j<2){
			return;
		}
		vector<int> tmp;
		for(int k=0;k<j;k++){
			tmp.push_back(vectorToSort[k]);
		}
		
		for(int k=0,l=j-1;k<j;k++,l--){
			vectorToSort[k]=tmp[l];
		}
}
void pancakeSort1(vector<int> & vectorToSort){
	
	//int i=vectorToSort.size()-1;
	int i=vectorToSort.size()-1;
	int prev;
	int current;
	int flag;
	
	do{
		flag=0;
		
		for(;i>0;i--){
			
			prev=vectorToSort[i];
			current=vectorToSort[i-1];
			if(prev<current){
				flag=1;
				//cout<<prev<<" "<<current<<" "<<i<<endl;
				break;
			}
		}
		
		if(flag==0){
			break;
		}
		
		//cout<<i<<endl;
		
		/*
		if(current-1== i){
			i--;
			continue;
		}
		*/
		
		if(current==i){
			i--;
			continue;
		}

		flip(vectorToSort,i);
		
		flip(vectorToSort,current);
		//i--;
	
		//flip(vectorToSort,i);
		/*
		for(int i=0;i<vectorToSort.size();i++){
		cout<<vectorToSort[i]<<endl;
		}
		*/
		//cout<<endl;

		//break;
		
		i=vectorToSort.size()-1;
		
	} while(flag==1);
	
	
}

void pancakeSort2(vector<int>& vectorToSort){
	
	//int i=vectorToSort.size()-1;
	int i=vectorToSort.size()-1;
	int prev;
	int current;
	int flag;
	
	do{
		flag=0;
		
		for(;i>0;i--){
			
			prev=vectorToSort[i];
			current=vectorToSort[i-1];
			if(prev<current){
				flag=1;
				//cout<<prev<<" "<<current<<" "<<i<<endl;
				break;
			}
		}
		
		if(flag==0){
			break;
		}
		
		//cout<<i<<endl;
		
		/*
		if(current-1== i){
			i--;
			continue;
		}
		*/

		
		flip(vectorToSort,i);
		
		flip(vectorToSort,current);
		//i--;
	
		//flip(vectorToSort,i);
		/*
		for(int i=0;i<vectorToSort.size();i++){
		cout<<vectorToSort[i]<<endl;
		}
		*/
		//cout<<endl;

		//break;
		
	} while(flag==1);
}

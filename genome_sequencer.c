//This program is used to sequence the genomes of a variety of viruses
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* substring_finder(char string1[], char string2[],int length1,int length2);
int max(int num1,int num2);
char* subsequence_finder( char string1[], char string2[], int length1,int length2);

int main(){
	
	
	char character=0;
	
	FILE* fptr= fopen("Human endogenous retrovirus K113.txt","r");
	
	if(fptr==NULL){
		puts("Error Opening File");
		return 1;
	}
	
	int a_num=0;
	int t_num=0;
	int c_num=0;
	int g_num=0;
	
	
	while(!feof(fptr))
	{
	fscanf(fptr,"%c",&character);
	
	switch(character){
		case 'a':
			a_num++;
			break;
		case 't':
			t_num++;
			break;
		case 'c':
			c_num++;
			break;
		case 'g':
			g_num++;
			break;
		
		
	}
	
	}
	
	int length1=a_num+t_num+c_num+g_num;
	char* virus1= (char *) malloc( sizeof(char)*length1);
	if(virus1==NULL){
		puts("Memory Allocation Error has occured");
		exit(1);
	}
	
	rewind(fptr);
	int i=0;
	
	while(!feof(fptr))
	{
	fscanf(fptr,"%c",&character);
	
	switch(character){
		case 'a':
			virus1[i++]='a';
			break;
		case 't':
			virus1[i++]='t';
			break;
		case 'c':
			virus1[i++]='c';
			break;
		case 'g':
			virus1[i++]='g';
			break;
		
		
	}
	
	}
	
	fclose(fptr);
	
	fptr= fopen("Human papillomoavirus type 5.txt","r");
	
	if(fptr==NULL){
		puts("Error Opening File");
		return 1;
	}
	
	a_num=0;
	t_num=0;
	c_num=0;
	g_num=0;
	
	while(!feof(fptr))
	{
	fscanf(fptr,"%c",&character);
	
	switch(character){
		case 'a':
			a_num++;
			break;
		case 't':
			t_num++;
			break;
		case 'c':
			c_num++;
			break;
		case 'g':
			g_num++;
			break;
		
		
	}
	
	}
	
	int length2=a_num+t_num+c_num+g_num;
	char* virus2= (char *) malloc( sizeof(char)*length2);
	if(virus2==NULL){
		puts("Memory Allocation Error has occured");
		exit(1);
	}
	
	rewind(fptr);
	i=0;
	
	while(!feof(fptr))
	{
	fscanf(fptr,"%c",&character);
	
	switch(character){
		case 'a':
			virus2[i++]='a';
			break;
		case 't':
			virus2[i++]='t';
			break;
		case 'c':
			virus2[i++]='c';
			break;
		case 'g':
			virus2[i++]='g';
			break;
		
		
	}
	
	}
	
	fclose(fptr);
	
	/*
	printf("Number of Adenine: %d\nNumber of Thymine: %d\nNumber of Cytosine: %d\nNumber of Guanine: %d",a_num,t_num,c_num,g_num);
	puts(virus);
	*/
	char *string3=subsequence_finder(virus1,virus2,length1,length2);
	
	printf("The longest common DNA subsequence is %s\n",string3);
	printf("The length is %d",strlen(string3));
	
	
	free(string3);
	free(virus1);
	

	
}

char* substring_finder(char string1[],char string2[],int length1,int length2){
		
		int ** substring_matrix;
		
		substring_matrix= (int **) malloc((length1+1)*sizeof(int *));
		
		if(substring_matrix==NULL){
			puts("Memory Allocation Error");
			exit(1);
			
		}
		
		int i;
		int j;
		
		for(i=0;i<(length1+1);i++){
			substring_matrix[i]= (int *) malloc((length2+1)*sizeof(int *));
			if(substring_matrix[i]==NULL){
			puts("Memory Allocation Error");
			exit(1);
			
		}
		}
		
		for(i=0;i<length2+1;i++){
			substring_matrix[0][i]=0;
		}
		
		for(i=0;i<length1+1;i++){
			substring_matrix[i][0]=0;
		}
		
		char character1;
		char character2;
		
		for( i=0;i<length1;i++){
				character1=string1[i];
				for(j=0;j<length2;j++){
					character2=string2[j];
					
					if(character1==character2){
						substring_matrix[i+1][j+1]= substring_matrix[i][j]+1;
						
					} else {
						substring_matrix[i+1][j+1]=0;
					}
				}
		}
		
		int max=0;
		int max_j;
		
		for(i=0;i<length1+1;i++){
			for(j=0;j<length2+1;j++){
				if(substring_matrix[i][j]>max){
					max_j=j;
					max=substring_matrix[i][j];
				}
		}
		}
		if(max==0){
			return "";
		}
		
		char* string3= (char*) malloc((max+1)*sizeof(char));
		
		j=max_j-max;
		string3[max]='\0';
		
		for(i=0;i<max;i++,j++){
			string3[i]= string2[j];	
		}
		
		return string3;
		
		//free(substring_matrix);
}

int max(int num1,int num2){
		if(num1>= num2){
			return num1;
		} else{
			return num2;
		}
}

char* subsequence_finder( char string1[], char string2[], int length1,int length2){
		int ** substring_matrix;
		
		substring_matrix= (int **) malloc((length1+1)*sizeof(int *));
		
		if(substring_matrix==NULL){
			puts("Memory Allocation Error");
			exit(1);
			
		}
		
		int i;
		int j;
		
		for(i=0;i<(length1+1);i++){
			substring_matrix[i]= (int *) malloc((length2+1)*sizeof(int *));
			if(substring_matrix[i]==NULL){
			puts("Memory Allocation Error");
			exit(1);
			
		}
		}

		for(i=0;i<length2+1;i++){
			substring_matrix[0][i]=0;
		}
		
		for(i=0;i<length1+1;i++){
			substring_matrix[i][0]=0;
		}
		
		char character1;
		char character2;
		
		for( i=0;i<length1;i++){
				character1=string1[i];
				for(j=0;j<length2;j++){
					character2=string2[j];
					
					if(character1==character2){
						substring_matrix[i+1][j+1]= substring_matrix[i][j]+1;
						
					} else {
						substring_matrix[i+1][j+1]=max(substring_matrix[i][j+1],substring_matrix[i+1][j]);
					}
				}
		}
		
		int max=0;
		int max_j;
		int max_i;
		
		for(i=0;i<length1+1;i++){
			for(j=0;j<length2+1;j++){
				if(substring_matrix[i][j]>max){
					max_i=i;
					max_j=j;
					max=substring_matrix[i][j];
				}
		}
		}
		
		//printf("This length of the DNA subsequence is %d\n",max);
		
		if(max==0){
			return "";
		}
		
		char* string3= (char*) malloc((max+1)*sizeof(char));
		string3[max]='\0';
		
		i=max_i;
		j=max_j;
		int k=max-1;
		
		while(substring_matrix[i][j]!=0){
			character1=string1[i-1];
			character2=string2[j-1];
			
			if(character1 == character2){
				string3[k]=character1;
				i--,j--,k--;
				
			} else{
				if(substring_matrix[i-1][j]==substring_matrix[i][j]){
					i=i-1;
				} else if(substring_matrix[i][j-1]== substring_matrix[i][j]){
					j=j-1;
				}
			}
			
			
		}
		
		return string3;
}
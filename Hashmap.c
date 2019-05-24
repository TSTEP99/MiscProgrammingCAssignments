#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hash_code(char* string){
	int hash=7;
	int length=strlen(string);
	int i;
	for(i=0;i<length;i++){
		hash=31*hash+string[i];
	}
	
	return hash;
}

typedef struct hashelement{
	char* key;
	int value;


} HashElement;

typedef struct hashmap{
	int length;
	int full;
	HashElement** array;


	
} HashMap;

HashMap* initialize(void){
	HashMap* new_map= (HashMap*) malloc(sizeof(HashMap));
	new_map->length=101;
	new_map->full=0;
	new_map->array= (HashElement**) malloc((new_map->length)*sizeof(HashElement*));
	int i;
	for(i=0;i<(new_map->length);i++){
		new_map->array[i]=NULL;
	}	

	return new_map;
}

int linear_prob(HashElement** array,int index,int length){
	int i=index+1;

	for(;i<length;i++){
		if(array[i]==NULL){
			return i;
		}
	}

	for(i=0;i<index;i++){
		if(array[i]==NULL){
			return i;
		}
	}

	return -1;
	
}

int resize(HashElement*** array,int length){
	HashElement** tmp= (HashElement**) realloc(*array,sizeof(HashMap*)*2*length);
	if(tmp==NULL){
		return 1;
	}

	*array=tmp;



	return 0;

}

int insert(HashMap* map,char* key,int value){
	if((float)(map->full)/(map->length)>=.75){
		if(resize(&(map->array),map->length)==1){
			return 1;
		}
	}

	int index= abs(hash_code(key)%(map->length));

	if(map->array[index]!=NULL){
		int index=linear_prob(map->array,index,map->length);
		if(index==-1){
			return 1;
		}else{
		HashElement* new_element= malloc(sizeof(HashElement));
		new_element->key=key;
		new_element->value=value;
		map->array[index]=new_element;
		 }
	} else{
		HashElement* new_element= malloc(sizeof(HashElement));
		new_element->key=key;
		new_element->value=value;
		map->array[index]=new_element;
	}	

}

int delete(HashMap* map,char* key){
	int index= abs(hash_code(key))%(map->length);
	if(strcmp(map->array[index]->key,key)==0){
		free(map->array[index]);
		map->array[index]=NULL;
		return 0;
	}

	int i;

	for(i=index+1;i<(map->length);i++){
		if(strcmp(map->array[i]->key,key)==0){
			free(map->array[i]);
			map->array[i]=NULL;
			return 0;
		}
	}

	for(i=0;i<index;i++){
		if(strcmp(map->array[i]->key,key)==0){
			free(map->array[i]);
			map->array[i]=NULL;
			return 0;
		}
	}

	return 1;

}


int main(){
	HashMap* new_map= initialize();

	char key[]="Aunty Ravat";
	int value=8;

	insert(new_map,key,value);
	delete(new_map,key);

}








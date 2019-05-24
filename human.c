#include<stdio.h>
#include<stdlib.h>

typedef struct person Human;
struct person{
	int height;
	int weight;
	char gender;
	Human *next;
	};

Human *search(Human *headptr, int height);
void add(Human *headptr);
void del(Human *headptr);

int main()
{
	Human basehuman;
	basehuman.height=0;
	Human *headptr;
	headptr=&basehuman;
	
	
	
	Human gianni;
	
	gianni.height=65;
	gianni.weight=110;
	gianni.gender='m';
	gianni.next=NULL;
	
	Human teja;
	
	teja.height=68;
	teja.weight=138;
	teja.gender='m';
	
	Human george;
	george.height=72;
	george.weight=200;
	george.gender='m';
	
	Human nooman;
	nooman.height=66;
	nooman.weight;
	nooman.gender='m';
	
	Human persons[4];
	
	persons[0]=teja;
	persons[1]=george;
	persons[2]=nooman;
	persons[3]=gianni;
	
	Human *ptr=persons;
	int i;
	
	for(i=0;i<=4;i++,ptr++)
	{
		printf("%d",ptr->height);	
	}
	
	
	basehuman.next=&gianni;
	
	//add(headptr);
	//del(headptr);
	
	struct society{
	char *name;	
	Human person1;
	Human person2;
	Human person3;
	Human person4;	
	}hendrick;
		
	hendrick.name="Shixuan";
	puts(hendrick.name);
}


Human *search(Human *headptr, int tall)
{
		Human *previous;
		Human *current;
		
		previous=headptr;
		current=headptr->next;
		
		while((current!= NULL)&&(current->height<tall) )
		{
			previous=current;
			current=current->next;
		}
		
		return previous;
}

void add(Human *headptr)
{
		Human *person= (Human *) malloc(sizeof(Human));
		
		if( person==NULL)
		{
			printf("Error allocating memory");
				exit(1);
		}
		
		int tall,fat;
		char organs;
		printf("Type in height,weight,gender(m/f/o)\n");
		scanf("%d %d %c",&tall,&fat,&organs);
		person->height=tall;
		person->weight=fat;
		person->gender=organs;
		
		Human *previous=search(headptr,tall);
		Human *current=previous->next;
		
		previous->next=person;
		person->next=current;
		
		
		
}

void del(Human *headptr)
{
	int tall;
	printf("Enter the height of the person: ");
	scanf("%d",&tall);
	Human *previousnode=search(headptr,tall);
	Human *delnode= previousnode->next;
	
	if (((delnode->height)==tall)&&(delnode!=NULL))
	{
			previousnode->next=delnode->next;
			free(delnode);
			exit(0);
	}
	
		printf("Node not detected");	
			
	
	
	

}

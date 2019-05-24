#include<stdio.h>

int strlength(char string[]);

int main()
{
	char string[20];
	printf("Enter a string less than 20 characters: ");
	gets(string);
	int length=strlength(string);
	length--;
	while(length>=0)
	{
		printf("%c",string[length]);
		length--;
	}
	
	
}

int strlength(char string[])
{
	int i=0;
	int length=0;
	
	while(string[i] !='\0')
	{
		length++;
		i++;
	}
	
	return length;
}
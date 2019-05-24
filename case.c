#include<stdio.h>

int main()
{
	char letter;
	
	printf("Type in a letter: ");
	scanf("%c",&letter);
	
	if(letter>=97&&letter<=122)
	{
		letter=letter-32;
	}
	
	printf("%c",letter);
}
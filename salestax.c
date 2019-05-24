#include <stdio.h>

int main()
{
	float amount;
	float rate;
	
	printf("Enter amount purchased: ");
	scanf("%f",&amount);
		
	printf("\nEnter the rate:");
	scanf("%f",&rate);
		
	float tax=amount*rate;
	amount+=tax;
		
	printf("%f is the tax. Your total is %f",tax,amount);
}
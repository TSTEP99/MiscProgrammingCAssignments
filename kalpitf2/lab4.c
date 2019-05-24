#include <stdio.h>
#include "prime.h"

int main()
{
  // Write the code to take a number n from user and print all the prime numbers between 1 and n
	
	int n;
	
	printf("Enter the value of n: ");

	scanf("%d", &n);
	
	printf("Printing primes less than or equal to %d: \n", n);

	int i;
	
	for (i=2 ; i <= n ; i++)
	{
		
		printf("%d",i);
		
		
		//printf("%d",i);
		if (is_prime(i))
		{
			printf("%d ", i);
			
			break;
		}
	}
	
	printf("\n");

  return 0;
}


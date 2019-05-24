#include <stdio.h>
#include "prime.h"

int main()
{
  // Write the code to take a number n from user and print all the prime numbers between 1 and n
	printf("Enter the value of n: ");

	scanf("%i", &n);
	
	printf("Printing primes less than or equal to %i: \n", n);

	for (i=2 ; i <= n ; i++)
	{
		primeonscreen = is_prime(i);
		if (primeonscreen == 1)
		{
			printf("%i ", i);
		}
	}
	
	printf("\n");

  return 0;
}


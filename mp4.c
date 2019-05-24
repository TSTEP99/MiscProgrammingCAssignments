# include <stdio.h>
#include <math.h>

int is_prime(int n);

int print_semiprime(int a, int b);


/*
	I first started with the is_prime function. For the function I checked to see if is was divisible from any number from 2 to the sqrt(n).
	If it was I said it was not prime, otherwise it was. I then implemented the algortihm from the 220 webpage in the print_semiprime function 
	where I used the exists variable to indicate whether or not it actually had semi primes.

*/

int main(){
	
	int a,b; //gives two variables for inputing numbers
	
	printf("Input two numbers: ");
	scanf("%d %d",&a,&b); //Uses scanf and printf to print numbers
	
	
	print_semiprime(a, b); //prints out semi_primes
    
	
    

}

int is_prime(int n){
	
		if(n<2){
			return 0;	//returns not prime if 0 or 1
		}
		
		int k=2; // starts the division at 2
		
		for(;(k<n);k++){
			
			if((n%k)==0){
				return 0;
			}
			
			//If the division yields a factor it returns not a prime
			
		}
		
		return 1; //returns prime if no division happened
}


int print_semiprime(int a,int b){
	
	int n;
	int exists=0;
	
	
	for(n=a;n<=b;n++){ //loops through entire range
		int k;
		//loops range of number
		for(k=2;k<n;k++){
			if( is_prime(k) && is_prime(n/k)&& n%k==0){ //if the k and its factor are both prime prints the number and sets exists
				printf("%d ",n);
				exists=1;
				break;
			}
		}
	}
	
	return exists; //returns whether or not it exists
}
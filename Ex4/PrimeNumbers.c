#include <stdio.h>
#include <math.h>

struct prime {
	int p;
	struct prime *next;
};

int main(){
	int limit=0;
	int candidate;
	struct prime smalestPrime;
	struct prime *currentPrime, *biggestPrime;

	// Get upper limit from user
	while(1>=limit){
		printf("Up to which number would you like to know all the prime numbers? ");
		scanf("%d", &limit);
		if(1>=limit){
			printf("Don't be silly...");
		}
	}

	// Set up variables
	smalestPrime.p=2;
	currentPrime=&smalestPrime;
	biggestPrime=&smalestPrime;
	candidate=3;

	// Search for primes below limit
	printf("%d\n", smalestPrime.p);
	while(limit>=candidate){
		if(0==candidate%currentPrime->p){
			candidate+=2;
			currentPrime=&smalestPrime;
		}
		else if(0!=candidate%currentPrime->p && sqrt(candidate)>=currentPrime->p){
			currentPrime=currentPrime->next;
		}
		else{
			struct prime newPrimeNmbr;
			newPrimeNmbr.p=candidate;
			biggestPrime->next=&newPrimeNmbr;
			biggestPrime=biggestPrime->next;
			currentPrime=&smalestPrime;
			candidate+=2;
			printf("%d\n", biggestPrime->p);
		}
	}
}

#include <stdio.h>
#include <math.h>

typedef struct prime {
	int p;
	struct prime *next;
} prime;

int main(){
	int limit=0;
	int candidate;
	prime smallestPrime;
	prime *currentPrime, *biggestPrime;

	// Get upper limit from user
	while(1>=limit){
		printf("Up to which number would you like to know all the prime numbers? ");
		scanf("%d", &limit);
		if(1>=limit){
			printf("Don't be silly...\n");
		}
	}

	// Set up variables
	smallestPrime.p=2;
	currentPrime=&smallestPrime;
	biggestPrime=&smallestPrime;
	candidate=3;

	// Search for primes below limit
	printf("{%d, ", smallestPrime.p);
	while(limit>=candidate){
		if(0==candidate%(currentPrime->p)){
			candidate+=2;
			currentPrime=&smallestPrime;
		}
		else if(0!=candidate%currentPrime->p && sqrt(candidate)>=currentPrime->p){
			currentPrime=currentPrime->next;
		}
		else{
			prime newPrime;
			if(5==candidate) printf("\nsmallestPrime.next->p: %d", smallestPrime.next->p);
			newPrime.p=candidate;
			if(5==candidate) printf("\nSome magicksx is happening (∩｀-´)⊃━☆ﾟ.*･｡ﾟ");
			if(5==candidate) printf("\nsmallestPrime.next->p: %d\n", smallestPrime.next->p);
			biggestPrime->next=&newPrime;
			biggestPrime=&newPrime;
			currentPrime=&smallestPrime;
			candidate+=2;
			printf("%d, ", biggestPrime->p);
		}
	}
	printf("}\n");
}

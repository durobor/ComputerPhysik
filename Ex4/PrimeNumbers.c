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
//		printf("\nsmallestPrime.p: %d\n", smallestPrime.p);
//		printf("currentPrime->p: %d\n", currentPrime->p);
//		printf("biggestPrime->p: %d\n", biggestPrime->p);
//		printf("sqrt(%d)=%f\n", candidate, sqrt(candidate));
//		printf("%d%%%d=%d\n", candidate, currentPrime->p, candidate%currentPrime->p);
		
		if(0==candidate%(currentPrime->p)){
			candidate+=2;
			currentPrime=&smallestPrime;
		}
		else if(0!=candidate%currentPrime->p && sqrt(candidate)>=currentPrime->p){
			currentPrime=currentPrime->next;
		}
		else{
			//debugging===============================================================
//			if(5==candidate){
//				printf("candidate: %d", candidate);
//				printf("\nsmallestPrime.p: %d\n", smallestPrime.p);
//				printf("smallestPrime.next->p: %d\n", smallestPrime.next->p);
//				printf("currentPrime->p: %d\n", currentPrime->p);
//				printf("currentPrime->next->p: %d\n", currentPrime->next->p);
//				printf("biggestPrime->p: %d\n", biggestPrime->p);
//			}
			//debugging===============================================================
			//smallestPrime: 2
			//currentPrime: 3
			//biggestPrime: 3
				if(5==candidate) printf("\nsmallestPrime.next->p: %d\n", smallestPrime.next->p);
			prime newPrime = { candidate };
//			newPrime.p=candidate;
				if(5==candidate) printf("\nsmallestPrime.next->p: %d\n", smallestPrime.next->p);
			biggestPrime->next=&newPrime;
			biggestPrime=&newPrime;
			currentPrime=&smallestPrime;
			//newPrime: 5
			//biggest->next: 5
			//biggest: 5
			/*
			//debugging===============================================================
			if(5==candidate){
				printf("candidate: %d", candidate);
				printf("\nsmallestPrime.p: %d\n", smallestPrime.p);
				printf("smallestPrime->next->p: %d\n", smallestPrime.next->p);
				printf("currentPrime->p: %d\n", currentPrime->p);
				printf("currentPrime->next->p: %d\n", currentPrime->next->p);
				printf("biggestPrime->p: %d\n", biggestPrime->p);
			}
			//debugging===============================================================
			//*/
			candidate+=2;
			printf("%d, ", biggestPrime->p);
		}
	}
	printf("}\n");
}

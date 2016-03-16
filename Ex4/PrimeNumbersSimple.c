#include <stdio.h>
#include <math.h>

int main(){
	int limit=0;

	// Get upper limit from user
	while(1>=limit){
		printf("Up to which number would you like to know all the prime numbers? ");
		scanf("%d", &limit);
		if(1>=limit){
			printf("Don't be silly...\n");
		}
	}

	int candidate;
	printf("{2, ");
	for(candidate=3;candidate<=limit;candidate+=2){
		int candidateIsPrime=1;
		int i;
		for(i=2;i<=sqrt(candidate);++i){
			if(0==candidate%i){
				candidateIsPrime=0;
				i=candidate;
			}
		}
		if(candidateIsPrime) printf("%d, ", candidate);
	}
	printf("}\n");
}

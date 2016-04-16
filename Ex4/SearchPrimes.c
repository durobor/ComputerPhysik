#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void addPrime(int**, int*, int, int);

int main(){
	int candidate=3, indx=0, indxLast=1, size=1, limit=1;
	int *primes=(int*)malloc(sizeof(int));
	*primes=2;

	// Get upper limit from user
	while(1>=limit){
		printf("Up to which number would you like to know all the prime numbers? ");
		scanf("%d", &limit);
		if(1>=limit){
			printf("Don't be silly...\n");
		}
	}

	// Search for primes below limit
	printf("{%d", *primes);
	while(limit>=candidate){
		if(0==candidate%(*(primes+indx))){
			candidate+=2;
			indx=0;
		}
		else if(0!=candidate%(*(primes+indx)) && sqrt(candidate)>=*(primes+indx)){
			++indx;
		}
		else{
			addPrime(&primes, &size, indxLast, candidate);
			printf(", %d", *(primes+indxLast));
			candidate+=2;
			++indxLast;
			indx=0;
		}
	}
	printf("}\n");
}

void addPrime(int **arr, int *size, int indx, int nmbr){
	if(*size>indx)
		*(*arr+indx)=nmbr;
	else{
		int *temp=(int*)malloc(*size*sizeof(int)), i;
		for(i=0;i<indx;++i){
			*(temp+i)=*(*arr+i);
		}
		free(*arr);
		*size*=2;
		*arr=(int*)malloc(*size*sizeof(int));
		for(i=0;i<indx;++i){
			*(*arr+i)=*(temp+i);
		}
		*(*arr+indx)=nmbr;
		free(temp);
	}
}

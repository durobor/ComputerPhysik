#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int guess, solution=rand()%1000;

	printf("Try to guess the number that I am thinking of!\n");
	while(guess!=solution){
		scanf("%d", &guess);
		if(guess>solution) printf("Too damn high!\n");
		else if(guess<solution) printf("Too low\n");
		else printf("You guessed correctly!\n");
	}

	return 0;
}

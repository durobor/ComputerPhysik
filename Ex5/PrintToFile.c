#include <stdio.h>
#include <math.h>

#define MAX_EXP 30

int main(){
	FILE *f = fopen("sequence.txt", "w");
	int i;
	for(i=2;(pow(2,MAX_EXP))>i;i*=2){
		fprintf(f, "%d\n", i);
	}
	fclose(f);

	return 0;
}

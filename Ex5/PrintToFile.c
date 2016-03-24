#include <stdio.h>
#include <math.h>

#define MAX_EXP 31;

int main(){
	FILE *f = fopen("sequence.txt", "w");
	int i;
	for(i=1;MAX_EXP>i;i*=2){
		fprintf(f, "%d\n", pow(2,i));
	}
	fclose(f);

	return 0;
}

#include <stdio.h>

int main(){
	FILE *f = fopen("sequence.txt","r");

	int i;
	fscanf(f,"%d", &i);
	while(!feof(f)){
		printf("%d\n", i);
		fscanf(f,"%d", &i);
	}

	return 0;
}

#include <stdio.h>

int sign(float);

int main(){
	printf("%d\n", sign(-1));
	printf("%d\n", sign(1));
	printf("%d\n", sign(0));

	return 0;
}

int sign(float x){
	if(0>x) return -1;
	else if(0<x) return 1;
	else return 0;
}

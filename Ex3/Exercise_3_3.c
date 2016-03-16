#include <stdio.h>
#include <math.h>

int main() {
	float a;
	float b;
	float c;
	float x1;
	float x2;

	printf("Enter parameters for the following equation: ax^2 + bx + c = 0\n");
	printf("Enter a value for a = ");
	scanf("%f", &a);
	printf("Enter a value for b = ");
	scanf("%f", &b);
	printf("Enter a value for c = ");
	scanf("%f", &c);
	
	int rootTerm = b*b-4*a*c;

	if(0>rootTerm){
		printf("There is no real solution to this equation.\n");
	}
	else if(0<rootTerm){
		x1=(-b-sqrt(rootTerm))/(2*a);
		x2=(-b+sqrt(rootTerm))/(2*a);
		printf("x1 = %.3f\n", x1);
		printf("x2 = %.3f\n", x2);
	}
	else {
		x1=-b/(2*a);
		printf("x = %.3f\n", x1);
	}

	return 0;
}

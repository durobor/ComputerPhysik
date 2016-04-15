#include <stdio.h>
#include <math.h>

int squareEquation(float, float, float, float*, float*);

int main() {
	float a;
	float b;
	float c;
	float x1;
	float x2;
	int solution;

	printf("Enter parameters for the following equation: ax^2 + bx + c = 0\n");
	printf("Enter a value for a = ");
	scanf("%f", &a);
	printf("Enter a value for b = ");
	scanf("%f", &b);
	printf("Enter a value for c = ");
	scanf("%f", &c);

	solution = squareEquation(a, b, c, &x1, &x2);

	printf("Number of solutions: %d\n", solution);
	if(0==solution)
		printf("There is no real solution.\n");
	else if(1==solution)
		printf("x = %.3f\n", x1);
	else{
		printf("x1 = %.3f\n", x1);
		printf("x2 = %.3f\n", x2);
	}
}

int squareEquation(float a, float b, float c, float* r1, float* r2){
	int rootTerm = b*b-4*a*c;

	if(0<rootTerm){
		*r1=(-b-sqrt(rootTerm))/(2*a);
		*r2=(-b+sqrt(rootTerm))/(2*a);
	}
	else {
		*r1=-b/(2*a);
	}

	if(0>rootTerm)
		return 0;
	else if(0==rootTerm)
		return 1;
	return 2;
}

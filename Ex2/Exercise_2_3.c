#include <stdio.h>
#include <math.h>

float argument = 0.0f;

int main() {
	printf("Enter an argument for the sine function: ");
	scanf("%f", &argument);
	
	printf("sin(%f) = %f \n", argument, (float)sin((double)argument));

	return 0;
}

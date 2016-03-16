#include <stdio.h>
#include <math.h>

float argument = 0.0f;
float result = 0.0f;

int main() {
	printf("Enter an agrument for the following functions: cos(x) and 1-x^2/2+x^4/24 \n x = ");
	scanf("%f", &argument);

	result = 1.-pow((double)argument, 2.0f)/2.+pow((double)argument, 4.0f)/24.;

	printf("cos(%.2f) = %f \n", argument, (float)cos((double)argument));
	printf("1-%.2f^2/2+%.2f^4/24 = %f \n", argument, argument, result); 

	return 0;
}

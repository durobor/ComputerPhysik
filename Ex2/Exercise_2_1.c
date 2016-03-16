#include <stdio.h>

int a;
int b;
float x;

int main() {
	printf("Enter a value for a = ");
	scanf("%d", &a);

	printf("Enter a value for b = ");
	scanf("%d", &b);

	x = -b/(float) a;

	printf("The solution for x = %.3f \n", x);

	return 0;
}

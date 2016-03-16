#include <stdio.h>
#include <math.h>

float h = 0.0f;
float t = 0.0f;
const float g = 9.81f;

int main() {
	printf("From which hight would you like to drop a stone (in meters)?  h = ");
	scanf("%f", &h);

	t = (float)sqrt(2*h/g);

	printf("It would take the stone %.3f seconds until it hits the ground \n", t);

	return 0;
}

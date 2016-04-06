#include <stdio.h>
#include <math.h>


float mysqrt(float, float);

int main(){
	float a, p;
	printf("Enter number of which you would like to know the square root from: ");
	scanf("%f", &a);
	printf("Enter precision: ");
	scanf("%f", &p);
	printf("mysqrt(%.2f)=%f\n", a, mysqrt(a,p));
	printf("sqrt(%.2f)=%f\n", a, sqrt(a));
	return 0;
}

float mysqrt(float x, float precison){
	float sqrt=1.f;
	while(x>sqrt*sqrt){
		sqrt+=precison;
	}
	return sqrt;
}

#include <stdio.h>
#include <math.h>

#define PRECISION pow(10,-7)

double f(double);
double integrate_Trapezoidal(double (*func)(double),double,double,double);

int main(){
	int i;
	printf("Trapezoidal method:\nt\tValue(t)\n");
	for(i=1;i<=5;++i){
		printf("%d\t%.8fl\n", i, integrate_Trapezoidal(f,-i,i,PRECISION));
	}

	/*
	printf("Simpson method:\nt\tValue(t)\n");
	for(i=1;i<=5;++i){
		printf("%d\t%.8fl\n", i, integrate_Trapezoidal(f,-i,i,PRECISION));
	}
	*/
	
	return 0;
}

double f(double x){
	return 1/sqrt(2*M_PI)*exp(-pow(x,2)/2.);
}

double integrate_Trapezoidal(double (*func)(double), double left, double right, double precision){
	double n=2.l, c=right-left, j_1=(func(left)+func(right))/n, integral_1=c*j_1, integral_2;
	int i;
	do{
		integral_2=integral_1;
		for(i=1;i<n;i+=2){
			j_1+=func(left+i/n*c);
		}
		integral_1=c/n*j_1;
		n*=2;
	}while(fabs(integral_1-integral_2)>precision*fabs(integral_2));
//	printf("%.0fl\n", log2(n));
//	printf("%.0fl\n", n);
	return integral_1;
}

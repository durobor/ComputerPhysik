#include <stdio.h>
#include <math.h>

#define PRECISION pow(10,-7)

double f(double);
double integrate_Trapezoidal(double (*func)(double),double,double,double);
double integrate_Simpson(double (*func)(double),double,double,double);

int main(){
	int i;
	printf("Trapezoidal method:\nt\tValue(t)\n");
	for(i=1;i<=5;++i){
		printf("%d\t%.8fl\n", i, integrate_Trapezoidal(f,-i,i,PRECISION));
	}

	printf("Simpson method:\nt\tValue(t)\n");
	for(i=1;i<=5;++i){
		printf("%d\t%.8fl\n", i, integrate_Simpson(f,-i,i,PRECISION));
	}
	
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
//	printf("Iterations: %.0fl\n", log2(n));
//	printf("Number of function calls: %.0fl\n", n);
	return integral_1;
}

double integrate_Simpson(double (*func)(double), double left, double right, double precision){
	double n=1.l, c=(right-left), h, integral=func(left)+func(right);
	int i;
	do{
		n*=2;
		for(i=1;i<n;i+=2){
			integral+=2*func(left+i/n*c);
		}
	}while(precision<1/pow(n,4));
	for(i=1;i<n;i+=2){
			integral+=2*func(left+i/n*c);
	}
	h=c/n;
//	printf("Iterations: %.0fl\n", log2(n));
//	printf("Number of function calls: %.0fl\n", n);
	return h/3.l*integral;
}

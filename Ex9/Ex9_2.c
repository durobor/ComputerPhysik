#include <stdio.h>
#include <math.h>

#define A0 2.L
#define GAMMA 0.3L
#define OMEGA1 1.5L
#define OMEGA2 (17.L/4.L)

#define PRECISION 0.00000001f
#define LEFT 0.f
#define RIGHT 5.f

double func_A(double);
void printRootsBisectionMethod();
double findSingleRootBisectionMethod(double,double);
void printRootsNewtonRaphsonMethod();

int main(){
	printRootsBisectionMethod();
	printRootsNewtonRaphsonMethod();
	
	return 0;
}

double func_A(double t){
	return A0*pow(M_E, -GAMMA*t)*(cos(OMEGA1*t)+sin(OMEGA2*t));
}

void printRootsBisectionMethod(){
	printf("Roots found by Bisection Method:\n");
	printf("%fl\n", findSingleRootBisectionMethod(0.5L, 1.5L));
	printf("%fl\n", findSingleRootBisectionMethod(1.5L, 1.8L));
	printf("%fl\n", findSingleRootBisectionMethod(1.8L, 2.5L));
	printf("%fl\n", findSingleRootBisectionMethod(2.5L, 3.5L));
	printf("%fl\n", findSingleRootBisectionMethod(3.5L, 4.05L));
	printf("%fl\n", findSingleRootBisectionMethod(4.05L, 4.5L));
}

double findSingleRootBisectionMethod(double left,double right){
	double epsilon=right-left, a=left, b=right, c, result_A, result_C;
	while(PRECISION<epsilon){
		c=(a+b)/2.;
		result_A=func_A(a);
		result_C=func_A(c);
		if((0<result_A && 0<result_C) || (0>result_A && 0>result_C))
			a=c;
		else
			b=c;
		epsilon/=2.L;
	}
	return c;
}

void printRootsNewtonRaphsonMethod(){
}

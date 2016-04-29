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
double func_A_der(double);
void printRootsBisectionMethod();
void printRootsNewtonRaphsonMethod();
double findSingleRootBisectionMethod(double,double);
double findSingleRootNewtonMethod(double);

int main(){
	printRootsBisectionMethod();
	printRootsNewtonRaphsonMethod();
	
	return 0;
}

double func_A(double t){
	return A0*pow(M_E, -GAMMA*t)*(cos(OMEGA1*t)+sin(OMEGA2*t));
}

double func_A_der(double t){
	return -A0*GAMMA*pow(M_E, -GAMMA*t)*(cos(OMEGA1*t)+sin(OMEGA2*t))
		+A0*pow(M_E, -GAMMA*t)*(-OMEGA1*sin(OMEGA1*t)+OMEGA2*cos(OMEGA2*t));
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

void printRootsNewtonRaphsonMethod(){
	printf("Roots found by Newton-Raphson Method:\n");
	printf("%fl\n", findSingleRootNewtonMethod(0.5L));
	printf("%fl\n", findSingleRootNewtonMethod(1.5L));
	printf("%fl\n", findSingleRootNewtonMethod(1.9L));
	printf("%fl\n", findSingleRootNewtonMethod(2.8L));
	printf("%fl\n", findSingleRootNewtonMethod(3.8L));
	printf("%fl\n", findSingleRootNewtonMethod(4.5L));
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

double findSingleRootNewtonMethod(double str_pnt){
	double epsilon=1.l, a=str_pnt, b;
	while((PRECISION<epsilon && 0<epsilon) || (PRECISION<(0-epsilon) && 0>epsilon)){
		b=a-func_A(a)/func_A_der(a);
		epsilon=b-a;
		a=b;
	}
	return a;
}

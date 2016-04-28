#include <stdio.h>
#include <math.h>

#define PREC 0.00000001f
#define LEFT 0.f
#define RIGHT 1.f
#define ITER_COUNT 30 

double function(double);
double function_der(double);

int main(){
	double e_bi=RIGHT-LEFT, e_ne=1.f, a=LEFT, b=RIGHT, result, c;
	double prec_bi[ITER_COUNT], prec_ne[ITER_COUNT];
	int i;
	for(i=0;i<ITER_COUNT;++i){
		prec_bi[i]=999999;
		prec_ne[i]=999999;
	}
	i=0;
	while(PREC<e_bi){
		c=(a+b)/2.;
		result=function(c);
		if(0<result){
			a=c;
		}
		else{
			b=c;
		}
		e_bi/=2.;
		prec_bi[i++]=e_bi;
	}
	printf("Bisection method:\na=%f\nb=%f\n", a, b);

	a=LEFT;
	i=0;
	while(PREC<e_ne){
		b=a-function(a)/function_der(a);
		e_ne=b-a;
		a=b;
		prec_ne[i++]=e_ne;
	}
	printf("\nNewton-Raphson method:\na=%f\n", a);

	printf("\nComparison of precision between the two methoods:\n");
	printf("Iteration\tBisection\tNewton\n");
	for(i=0;i<ITER_COUNT;++i){
		printf("%d\t\t%fl\t%fl\n", i, prec_bi[i], prec_ne[i]);
	}

	return 0;
}

double function(double x){
	return pow(M_E,-x)-x;
}

double function_der(double x){
	return -pow(M_E,-x)-1;
}

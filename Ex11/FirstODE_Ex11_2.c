#include <stdio.h>
#include <math.h>

double f(double,double);
double euler(double (*f)(double,double),double,double,double,double);
double runge_kutta2(double (*f)(double,double),double,double,double,double);
double runge_kutta4(double (*f)(double,double),double,double,double,double);
void exactValuesEx11_2();

int main(){
	euler(f, -2, 0, 1, 0.01);
	runge_kutta2(f, -2, 0, 1, 0.01);
	runge_kutta4(f, -2, 0, 1, 0.01);
	exactValuesEx11_2();

	// I don't give a flying fcuk about user input lol

	return 0;
}

double f(double x,double y){
	return y*sin(x)+sin(2*x);
}

double euler(double (*f)(double,double), double initialValue, double lower, double upper, double h){
	double x0, y0=initialValue;
	FILE *file = fopen("eulerMethodResults.txt", "w");
	fprintf(file, "x\t\tf(x)\n%lf\t%lf\n", x0, y0);
	for(x0=lower;x0<upper-h/2.;x0+=h){
		y0=y0+h*f(x0,y0);
		fprintf(file, "%lf\t%lf\n", x0+h, y0);
	}
	return y0;
}

double runge_kutta2(double (*f)(double,double), double initialValue, double lower, double upper, double h){
	double x0, y0=initialValue, k1, k2;
	FILE *file = fopen("rungeKutta2MethodResults.txt", "w");
	fprintf(file, "x\t\tf(x)\n%lf\t%lf\n", x0, y0);
	for(x0=lower;x0<upper-h/2.;x0+=h){
		k1=h*f(x0,y0);
		k2=h*f(x0+h/2,y0+k1/2);
		y0=y0+k2;
		fprintf(file, "%lf\t%lf\n", x0+h, y0);
	}
	return y0;
}

double runge_kutta4(double (*f)(double,double), double initialValue, double lower, double upper, double h){
	double x0, y0=initialValue, k1, k2, k3, k4;
	FILE *file = fopen("rungeKutta4MethodResults.txt", "w");
	fprintf(file, "x\t\tf(x)\n%lf\t%lf\n", x0, y0);
	for(x0=lower;x0<upper-h/2.;x0+=h){
		k1=h*f(x0,y0);
		k2=h*f(x0+h/2,y0+k1/2);
		k3=h*f(x0+h/2,y0+k2/2);
		k4=h*f(x0+h,y0+k3);
		y0=y0+k1/6+k2/3+k3/3+k4/6;
		fprintf(file, "%lf\t%lf\n", x0+h, y0);
	}
	return y0;
}

void exactValuesEx11_2(){
	double x;
	FILE *file_deci = fopen("exactValues_deci.txt", "w");
	for(x=0;x<=1-0.1/2;x+=.1){
		fprintf(file_deci, "%lf\t%lf\n", x, 2-2*cos(x)-2*exp(1-cos(x)));
	}
	FILE *file_centi = fopen("exactValues_centi.txt", "w");
	for(x=0;x<=1-0.01/2;x+=.01){
		fprintf(file_centi, "%lf\t%lf\n", x, 2-2*cos(x)-2*exp(1-cos(x)));
	}
}

#include <stdio.h>
#include <math.h>

#define START_X 0.
#define START_Y 2.
#define G -9.81
#define INTERVAL_STEP .25

int main(){
	float alpha, absV, x, y, xV, yV, t;
	int validInput = 0;

	// Get valid starting conditions from user
	while(!validInput){
		printf("Enter throwing velocity (non negative): ");
		scanf("%f", &absV);
		printf("Enter throwing angle (between 0 and 90 degree): ");
		scanf("%f", &alpha);
		if(0>=absV || 0>=alpha || 90<=alpha){
			printf("Dont be silly...\n");
			validInput=0;
		}
		else validInput=1;
	}

	// Set up variables for calculation
	alpha=alpha/180.*M_PI;
	x=START_X;
	y=START_Y;
	xV=absV*cos(alpha);
	yV=absV*sin(alpha);
	t=0.;

	// Print trajectory
	while(y>=0){
		printf("r(%.2f)=(%.1f,%.1f)\n", t, x, y);
		t=t+INTERVAL_STEP;
		x=START_X+xV*t;
		y=START_Y+yV*t+1./2.*G*pow(t,2);
	}
	printf("The stone hits the surface after %.2f seconds\n", t);
}

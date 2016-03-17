#include <stdio.h>
#include <math.h>

#define START_X 0.
#define START_Y 0.
#define M_BALL 0.5 // Ball mass
#define G -9.81
#define EKIN_MINIMUM 10
#define INTERVAL_STEP .1

int main(){
	float alpha, absV, x, y, xV, yV, tx, ty, kinE;
	int validInput = 0;

	// Get valid starting conditions from user
	while(!validInput){
		printf("Enter kicking velocity (non negative m/s): ");
		scanf("%f", &absV);
		printf("Enter kicking angle (between 0 and 90 degree): ");
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
	kinE=1./2.*M_BALL*pow(absV,2);
	tx=0.;
	ty=0.;

	// Print trajectory
	while(EKIN_MINIMUM<=kinE){
		if(0==y){
			printf("r(%.2f)=(%.1f,%.1f)	Ball hits the ground!\n", tx, x, y);
		}
		else{
			printf("r(%.2f)=(%.1f,%.1f)\n", tx, x, y);
		}
		tx+=INTERVAL_STEP;
		ty+=INTERVAL_STEP;
		x=START_X+xV*tx;
		y=START_Y+yV*ty+1./2.*G*pow(ty,2);

		// Adjust yV, ty, kinE and absV once y hits 0
		if(0>y){
			yV=-(yV+G*ty);
			absV=sqrt(pow(xV,2)+pow(yV,2));
			kinE=0.8*(1./2*M_BALL*pow(absV,2));
			absV=sqrt(2*kinE/M_BALL);
			xV=absV*cos(alpha);
			yV=absV*sin(alpha);
			y=0.;
			ty=0.;
		}
	}
}

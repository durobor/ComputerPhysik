#include <stdio.h>
#include <math.h>

int main(){
	int years, intervals;
	float capital, interest;

	printf("Enter capital: ");
	scanf("%f", &capital);
	printf("Enter rate of interest in percent (enter '5' for 5%% interest): ");
	scanf("%f", &interest);
	printf("Enter number of years: ");
	scanf("%d", &years);
	printf("Enter number of intervals per year: ");
	scanf("%d", &intervals);

	// Set up variables for calculation
	interest=interest/(intervals*100.)+1;

	// Compute interest
	capital=capital*pow(interest,intervals*years);

	printf("New capital: %.2f\n", capital);
}

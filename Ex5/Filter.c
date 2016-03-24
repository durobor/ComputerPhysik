#include <stdio.h>
#include <math.h>

#define TRANSVERSE_MOM 30

int main(){
	FILE *rawData = fopen("data.txt", "r");
	FILE *filteredData = fopen("filterdata.txt", "w");

	float x, y, z;
	while(!feof(rawData)){
		fscanf(rawData, "%f %f %f", &x, &y, &z);
		if(TRANSVERSE_MOM<sqrt(x*x+y*y) && !feof(rawData)){
			fprintf(filteredData, "%.3f %.3f %.3f\n", x, y, z);
		}
	}
	fclose(rawData);
	fclose(filteredData);

	return 0;
}

#include <stdio.h>
#include <math.h>

#define MAX_NBRS 10

int main(){
	int i;
	float sum=0.f, nmbrs[MAX_NBRS];
	
	for(i=0;i<MAX_NBRS;++i){
		printf("#%d: ", i+1);
		scanf("%f", &nmbrs[i]);
		sum+=nmbrs[i];
	}
	float average=sum/MAX_NBRS;
	printf("average: %.2f\n", average);

	for(i=0;i<MAX_NBRS;++i){
		nmbrs[i]=pow(nmbrs[i]-average,2);
		sum+=nmbrs[i];
	}
	float var=sum/MAX_NBRS;
	printf("standart deviation: %.2f\n", sqrt(var));
}

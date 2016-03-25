#include <stdio.h>

#define MAX_NBRS 10

int main(){
	float nmbrs[MAX_NBRS];
	
	int i;
	for(i=0;i<MAX_NBRS;++i){
		printf("#%d: ", i+1);
		scanf("%f", &nmbrs[i]);
	}

	for(i=1;MAX_NBRS>i;++i){
		int j=i;
		while(1<=j && nmbrs[j-1]>nmbrs[j]){
			float tmp = nmbrs[j-1];
			nmbrs[j-1]=nmbrs[j];
			nmbrs[j]=tmp;
			--j;
		}
	}
	
	printf("Sorted in ascending order:\n{");
	for(i=0;i<MAX_NBRS;++i){
		printf("%.1f", nmbrs[i]);
		if((MAX_NBRS-1)!=i) printf(", ");
	}
	printf("}\n");
}

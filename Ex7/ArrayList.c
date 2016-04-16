#include <stdio.h>
#include <stdlib.h>

void addNmbr(int**, int*, int, int);

int main(){
	int moreNmbrs=1, indx=0, size=1, n;
	int *nmbrs=(int*)malloc(sizeof(int));
	while(moreNmbrs){
		printf("Enter a number: ");
		scanf("%d", &n);
		addNmbr(&nmbrs, &size, indx++, n);
		printf("Would you like to add another number? (1 for yes, 0 for no) ");
		scanf("%d", &moreNmbrs);
	}

	int i;
	for(i=0;i<indx;++i){
		printf("%d\n", *(nmbrs+i));
	}

	return 0;
}

void addNmbr(int **pntrPntr, int *size, int indx, int n){
	if(indx<*size)
		*(*pntrPntr+indx)=n;
	else{
		int *temp=(int*)malloc(*size*sizeof(int));
		int i;
		for(i=0;i<indx;++i){
			*(temp+i)=*(*pntrPntr+i);
		}
		free(*pntrPntr);
		*size*=2;
		*pntrPntr=(int*)malloc(*size*sizeof(int));
		for(i=0;i<indx;++i){
			*(*pntrPntr+i)=*(temp+i);
		}
		*(*pntrPntr+indx)=n;
		free(temp);
	}
}

#include <stdio.h>
#include <stdlib.h>

void addNmbr(int*, int*, int, int);
void initArray(int*, int);

int main(){
	int n, moreNmbrs=1, indx=0, size=1, *arr=(int*)malloc(sizeof(int));
	initArray(arr, size);

	while(moreNmbrs){
		printf("Enter a number: ");
		scanf("%d", &n);
		addNmbr(arr, &size, indx++, n);
		printf("Would you like to add another number? (1 for yes, 0 for no) ");
		scanf("%d", &moreNmbrs);
	}

	int i;
	for(i=0;i<indx;++i){
		printf("%d\n", *(arr+i));
	}

	return 0;
}

void addNmbr(int *arr, int *size, int indx, int n){
	if(indx<*size)
		*(arr+indx)=n; 
	else{
		*size*=2;
		int *temp = (int*)malloc(*size*sizeof(int));
		initArray(temp, *size);
		int i;
		for(i=0;i<indx;++i){
			*(temp+i)=*(arr+i);
		}
		*(temp+indx)=n;
		free(arr);
		arr=temp;
	}
}

void initArray(int *arr, int size){
	int i;
	for(i=0;i<size;++i){
		*(arr+i)=0;
	}
}

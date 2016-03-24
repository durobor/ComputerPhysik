#include <stdio.h>

#define COL 3
#define ROW 3

int main(){
	double matrix[COL][ROW];
	int i;
	for(i=0;COL>i;++i){
		int j;
		for(j=0;ROW>j;++j){
			if(i==j){
				matrix[i][j]=1;
			}
			else {
				matrix[i][j]=0;
			}
			printf("%7.2f", matrix[i][j]);
		}
		printf("\n");
	}
}

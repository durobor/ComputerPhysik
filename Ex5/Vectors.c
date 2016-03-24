#inlcude <stdio.h>

#define DIM 3

int main(){
	float A[DIM], B[DIM], C[DIM];
	printf("Enter two vectors:\n");
	int i;
	for(i=0;DIM>i;++i){
		printf("A%d = ", i);
		scanf("%f", &A[i]);
	}
	for(i=0;DIM>i;++i){
		printf("B%d = ", i);
		scanf("%f", &B[i]);
	}
	float scalarProduct=0.f;
	for(i=0;DIM>i;++i){
		scalarProduct+=A[i]*B[i];
	}
	printf("Scalar product between A and B: %f\n", scalarProduct);
	printf("Vector product between A and B:\n");
	for(i=0;DIM>i;++i){
		C[i]=A[(i+1)%DIM]*B[(i+2)%DIM]-A[(i+2)%DIM]*B[(i+1)%DIM];
		printf("C%d = %f", i, C[i]);
	}
}

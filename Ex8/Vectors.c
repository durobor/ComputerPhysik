#include <stdio.h>

typedef struct{
	float x;
	float y;
	float z;
} vector3D;

float dotProduct(vector3D, vector3D);
vector3D crossProduct(vector3D, vector3D);

int main(){
	vector3D A, B, cProd;
	printf("Enter two vectors:\n");
	printf("A1=");
	scanf("%f", &(A.x));
	printf("A2=");
	scanf("%f", &(A.y));
	printf("A3=");
	scanf("%f", &(A.z));
	printf("\nB1=");
	scanf("%f", &(B.x));
	printf("B2=");
	scanf("%f", &(B.y));
	printf("B3=");
	scanf("%f", &(B.z));

	printf("\nDot product between A and B: %.3f\n", dotProduct(A, B));
	printf("Vector product between A and B:\n");
	printf("%.3f\n", (cProd=crossProduct(A, B)).x);
	printf("%.3f\n", cProd.y);
	printf("%.3f\n", cProd.z);
}

float dotProduct(vector3D vec1, vector3D vec2){
	float result=0.f;
	result+=vec1.x*vec2.x;
	result+=vec1.y*vec2.y;
	result+=vec1.z*vec2.z;
	return result;
}

vector3D crossProduct(vector3D vec1, vector3D vec2){
	vector3D cProd;
	cProd.x=vec1.y*vec2.z-vec1.z*vec2.y;
	cProd.y=vec1.z*vec2.x-vec1.x*vec2.z;
	cProd.z=vec1.x*vec2.y-vec1.y*vec2.x;
	return cProd;
}

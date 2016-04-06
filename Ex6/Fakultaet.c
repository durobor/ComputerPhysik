#include <stdio.h>

int factorial1(int);
int factorial2(int);

int main(){
	int a;
	scanf("%d", &a);
	printf("%d\n", factorial1(a));
	printf("%d\n", factorial2(a));

	return 0;
}

int factorial1(int n){
	if(1<n) return n*factorial1(n-1);
	else return 1;
}

int factorial2(int n){
	int m=n;
	while(1<n)
		m*=--n;
	return m;
}
